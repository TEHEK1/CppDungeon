//
// Created by neb_orion on 09.03.2024.
//
/*
#include "player/Player.h"
#include "navigation/Map.h"
#include "entity/Entity.h"
#include "events/Event.h"
#include "navigation/Cell.h"
#include "monitor/Monitor.h"
#include "Squad.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
//Refresh correct pos and size coordinates and add some cooments about resolution and fixed or not sprites 


namespace {
    static const int ENTITY_NUM = 7;
    enum Entity_position {HERO_3, HERO_2, HERO_1, CHEST, ENEMY_1, ENEMY_2, ENEMY_3};
    std::vector<std::vector<char>> Dead_hero = {
        {' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', '-', '-', '|', '-', '-', ' ', ' '},
        {' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {' ', ' ', '-', '-', '-', '-', '-', ' ', ' '},
        {' ', '-', '-', '-', '-', '-', '-', '-', ' '},
        {' ', '-', '-', '-', '-', '-', '-', '-', '-'}
    };
}


Monitor::GameWindow::GameWindow(const size_t& y_size, const size_t& x_size, const size_t& pos_y, const size_t& pos_x)
: m_y_size(y_size)
, m_x_size(x_size) {
    m_current_window = newwin(m_y_size, m_x_size, pos_y, pos_x);
    //DEBUG: for visual size of areas, will remove this when drawing ready sprites
    wborder(m_current_window, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(m_current_window);
}

Monitor::GameWindow::GameWindow()
: m_y_size(0)
, m_x_size(0)
, m_current_window(nullptr) {}

//TODO: add size checkers
//draw_sprite draws with only either text formating attribute or pair of colors (text, font) 
void Monitor::GameWindow::draw_sprite(const size_t& pos_y, const size_t& pos_x,
                        const std::vector<std::vector<char>>& sprite, int attribute) {
    wattron(m_current_window, attribute);
    size_t current_y = pos_y;
    size_t current_x = pos_x;
    for (const std::vector<char>& current_string : sprite) {
        //Ncurses can only draw char or const char*,  so need to write by symbol
        wmove(m_current_window, current_y, current_x);
        for (char symbol : current_string) {
            waddch(m_current_window, symbol);
        }
        current_y++;
        current_x = pos_x;
    }
    wattroff(m_current_window, attribute);
    wrefresh(m_current_window);
}


void Monitor::GameWindow::draw_text(const size_t& pos_y, const size_t& pos_x,
                        const std::vector<char>& text, int attribute) {
    draw_sprite(pos_y, pos_x, std::vector<std::vector<char>> (1, text), attribute);
}

size_t Monitor::GameWindow::get_x() {
    return m_x_size;
}

size_t Monitor::GameWindow::get_y() {
    return m_y_size;
}

Monitor::GameWindow::GameWindow (const Monitor::GameWindow& other) { 
    m_current_window = other.m_current_window;
    m_x_size = other.m_x_size;
    m_y_size = other.m_y_size;
}
// Starting ncurses mode with initialisation of Monitor
//TODO: Apply this variant or move initscr() to main
Monitor::Monitor(Player* current_player) {
    //Enable curses mode


    int row, col;
    getmaxyx(stdscr, row, col);

    m_bounded_player = current_player;

    //        |--------------------|
    // 2 / 3  |  Battle            |
    //        |                    |
    //        |                    |
    //        |----------| ------- |
    // 1 / 3  | Inventory|      Map|
    //        |          |         |
    m_background_display = GameWindow (2 * row / 3, col, 0, 0);
    m_inventory_display = GameWindow (row / 3, col / 2, row * 2 / 3 + 1, 0);
    m_map_display = GameWindow (row / 3, col / 2, row * 2 / 3 + 1, col / 2 + 1);

    int block_dictance = col / ((ENTITY_NUM - 1) * 1 + ENTITY_NUM * 4 + 2);// blocks between heroes, blocks on hero, board blocks
    int left_dictance = col % ((ENTITY_NUM - 1) * 1 + ENTITY_NUM * 4 + 2);

    for (int i = 0; i < ENTITY_NUM; i++) {
        m_entity_window.push_back(GameWindow(5 * m_background_display.get_y() / 9,
                                             4 * block_dictance, m_background_display.get_y() /3, block_dictance * (5 * i + 1) + left_dictance / 2));
    }
}


Monitor::~Monitor() {
    //TODO: See TODO of Monitor
    endwin();
}


//TODO: Change start postion of all sprites
void Monitor::draw(Player* current_player) {
    //Heroes
    int draw_position = static_cast<int>(Entity_position::HERO_1);
    
    for (const std::shared_ptr<entity::Entity>& i : current_player->getSquad()->getEntities()) {
        if (i != nullptr) {
            m_entity_window[draw_position].draw_sprite(0, 0, i->draw());
        }
        draw_position--;
    }

    
    m_map_display.draw_sprite(1, 1, current_player->getMap()->draw(current_player->getPosition(), m_map_display.get_y() - 2, m_map_display.get_x() - 2));
    //TODO: After discussion add player.getMap().getCell(player.getPosition()).draw() using color or italic 
    //TODO: Add inventory list display and other related to interface stuff to draw after discussion 

}


void Monitor::draw() {
    draw(m_bounded_player);
}


void Monitor::keyEvent(char key) {
    //Still do not know which interaction should i do with a key
}


void Monitor::keyEvent() {
    char pressed_key = getch();
    keyEvent(pressed_key);
}
*/