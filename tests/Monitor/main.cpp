#include <iostream>
#include <ncurses.h> 
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
#include "changers/PositionChanger.h"
#include "actions/MoveLeft.h"
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
    Player* player = new Player(map, monitor);
    auto moveLeft = actions::MoveLeft();
    moveLeft.act(player);
    while(1) {
        monitor->draw(player);
        monitor->keyEvent(getch(), player);
    }

    endwin();
    delete player, map, monitor;
	return 0;
}