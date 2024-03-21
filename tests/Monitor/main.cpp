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
#include "heroes/ManAtArms/ManAtArms.h"
#include "heroes/Musketeer/Musketeer.h"
#include "heroes/BountyHunter/BountyHunter.h"
#include "heroes/Hellion/Hellion.h"
#include "Main.h"
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
    auto main = std::make_shared<Main>();
    std::vector<std::shared_ptr<entity::Entity>> allies;
    allies.reserve(3);
    allies.push_back(std::make_shared<Heroes::ManAtArms::ManAtArms>());
    allies.push_back(std::make_shared<Heroes::Hellion::Hellion>());
    allies.push_back(std::make_shared<Heroes::Musketeer::Musketeer>());
    auto alliesSquad = std::make_shared<Squad>(allies);
    auto enemiesSquad = alliesSquad;
    auto player = std::make_shared<Player>(map, monitor, enemiesSquad, main);

    while (1) {
        monitor->draw(player.get());
        char key = getch();
        if(key == 'q'){
            break;
        }
        monitor->keyEvent(key, player.get());
    }
    endwin();
	return 0;
}