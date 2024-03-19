#include <iostream>
#include <ncurses.h> 
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include "changers/PositionChanger.h"
#include "actions/MoveRight.h"
#include "actions/MoveLeft.h"
#include "actions/Use.h"
#include "actions/DontUse.h"
#include "actions/ChooseNextRoom.h"
#include "enemies/BrigandFusier/BrigandFusilier.h"
#include "enemies/BrigandRaider/BrigandRaider.h"
#include "Squad.h"
class PositionChangerAdapter: public changers::PositionChanger{
public:
    using changers::PositionChanger::setPosition;
};
int main()
{	
    raw();
    keypad(stdscr, TRUE);
	initscr();
    noecho();
    int row, col;
    getmaxyx(stdscr, row, col);
    start_color();
    refresh();
    
    auto map = std::make_shared<Map>(12);
    auto monitor = std::make_shared<Monitor>();
    std::vector<std::shared_ptr<entity::Entity>> allies;
    allies.reserve(4);
    for(int i = 0;i<4;i++){
        allies.push_back(std::make_shared<enemies::BrigandRaider::BrigandRaider>());
    }
    Player* player = new Player(map, monitor, std::make_shared<Squad>(allies));

    /*for(auto action:player->getActions()){
        if(auto chooseNextRoom = std::dynamic_pointer_cast<actions::ChooseNextRoom>(action)){
            chooseNextRoom->act(player);
        }
    }
    auto moveRight = actions::MoveRight();
    moveRight.act(player);
    for(auto action:player->getActions()){
        if(auto dontUse = std::dynamic_pointer_cast<actions::Use>(action)){
            dontUse->act(player);
        }
    }
    moveRight.act(player);
*/

    while(1) {
        monitor->draw(player);
        monitor->keyEvent(getch(), player);
    }

    endwin();
    delete player, map, monitor;
	return 0;
}