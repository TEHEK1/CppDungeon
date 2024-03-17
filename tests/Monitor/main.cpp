#include <iostream>
#include <ncurses.h> 


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

    //Some test code


    getch();
	return 0;
}