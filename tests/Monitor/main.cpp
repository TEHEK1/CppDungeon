#include <iostream>
#include <ncurses.h> 
#include "monitor/Monitor.h"
#include "player/Player.h"
#include "navigation/Map.h"
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
    
    Map* map = new Map(12);
    Monitor* monitor = new Monitor();
    Player* player = new Player(map, monitor);

    player->setMonitor(monitor);
    map->getCell(map->getStartPosition());
    monitor->draw(player);
    //Some test code


    getch();
    endwin();
    delete player;
	return 0;
}