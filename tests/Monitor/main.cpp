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
    Player* player = new Player(map);
    Monitor* monitor = new Monitor(player);
    player->setMonitor(monitor);

    monitor->draw();
    //Some test code


    getch();
    endwin();
    delete player;
	return 0;
}