//
// Created by neb_orion on 09.03.2024.
//

#include "player/Player.h"
#include "navigation/Map.h"
#include "entity/Entity.h"
#include "events/Event.h"
#include "navigation/Cell.h"
#include "monitor/Monitor.h"
#include "actions/ChooseNextRoom.h"
#include "Squad.h"
#include <iostream>
#include <vector>
#include <ncurses.h>
//Refresh correct pos and size coordinates and add some cooments about resolution and fixed or not sprites 


namespace {
    static const int ENTITY_NUM = 7;
    enum Entity_position {HERO_3, HERO_2, HERO_1, CHEST, ENEMY_1, ENEMY_2, ENEMY_3};
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


void Monitor::GameWindow::set_atr(size_t row, size_t col, size_t num, attr_t atr, short color) {
    mvwchgat(m_current_window, row, col, num, atr, color, NULL);
    wrefresh(m_current_window);
}

void Monitor::GameWindow::clear_atr(size_t row, size_t col, int num) {
    if (num == -1) {
        wattrset(m_current_window, A_NORMAL);
        wcolor_set(m_current_window, 0, NULL);
    } else {
        this->set_atr(row, col, num);
    }
}
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

size_t Monitor::GameWindow::get_x() const{
    return m_x_size;
}

size_t Monitor::GameWindow::get_y() const{
    return m_y_size;
}

Monitor::GameWindow::GameWindow (const Monitor::GameWindow& other) { 
    m_current_window = other.m_current_window;
    m_x_size = other.m_x_size;
    m_y_size = other.m_y_size;
}


Monitor::Monitor() {
    int row, col;
    getmaxyx(stdscr, row, col);

    //        |--------------------|
    // 2 / 3  |  Battle            |
    //        |                    |
    //        |                    |
    //        |----------| ------- |
    // 1 / 3  | Inventory|      Map|
    //        |          |         |
    m_background_display = GameWindow ( 2 * row / 3, col, 0, 0);
    m_inventory_display = GameWindow (8 * row / 9, col / 2, 7 * row / 9 + 1, 0);
    m_map_display = GameWindow (row / 3, col / 2, row * 2 / 3 + 1, col / 2 + 1);
    m_user_actions_display = GameWindow (row / 9, col / 2, 2 * row / 3 + 1, 0);
    //Calculating x_distance and size
    const int heroes_blocks = 4;
    const int edge_blocks = 1;
    const int space_blocks = 1;
    int block_dictance = col / ((ENTITY_NUM - 1) * space_blocks + ENTITY_NUM * heroes_blocks + edge_blocks * 2);
    // blocks between heroes, blocks on hero, board edge blocks
    int left_dictance = col % ((ENTITY_NUM - 1) * space_blocks + ENTITY_NUM * heroes_blocks + edge_blocks * 2);



    for (int i = 0; i < ENTITY_NUM; i++) {
        m_entity_window.push_back(GameWindow(8 * m_background_display.get_y() / 10,
                                            heroes_blocks * block_dictance, m_background_display.get_y() / 10,
                                            block_dictance * ((heroes_blocks + space_blocks) * i + edge_blocks) + left_dictance / 2));
    }
}

void Monitor::abs_coordinates_to_relative(int& row, int& col, const GameWindow& cur_window, Position center) {
    int row_realtive_center = cur_window.get_y() / 2 - (cur_window.get_y() + 1) % 2;
    int col_realtive_center = cur_window.get_x() / 2 - (cur_window.get_x() + 1) % 2;
    int row_difference = center.getLine() - row;
    int col_difference = center.getColumn() - col;
    row = row_realtive_center - row_difference;
    col = col_realtive_center - col_difference;
}


//TODO: Change start postion of all sprites
void Monitor::draw(Player* current_player) {
    //Heroes
    int draw_position = static_cast<int>(Entity_position::HERO_1);
    if(current_player->getSquad() == nullptr){
        throw std::logic_error("Squad is not initialized");
    }
    for (const std::shared_ptr<entity::Entity>& i : current_player->getSquad()->getEntities()) {
        if (i != nullptr) {
            m_entity_window[draw_position].draw_sprite(0, 0, i->draw());
        }
        draw_position--;
    }
    auto tmp = current_player->getMap()->draw(current_player->getPosition(), m_map_display.get_y() - 2, m_map_display.get_x() - 2);
    for (auto& i : tmp) {
        for (auto& j : i) {
            if (j == 0) {
                j = ' ';
            } else {
                j += '0';
            }
        }
    }
    m_map_display.draw_sprite(1, 1, tmp);
    init_pair(1, COLOR_CYAN, COLOR_RED);
    int center_x = current_player->getPosition().getColumn();
    int center_y = current_player->getPosition().getLine();
    abs_coordinates_to_relative(center_y, center_x, m_map_display, current_player->getPosition());
    m_map_display.set_atr(center_y, center_x, 1, 0, 1);
    for (Position i : current_player->getMap()->getNextRooms(current_player->getPosition())) {
        int cur_x = i.getColumn();
        int cur_y = i.getLine();
        abs_coordinates_to_relative(cur_y, cur_x, m_map_display, current_player->getPosition());
        m_map_display.set_atr(cur_y, cur_x, 1, A_BLINK, A_NORMAL);
    }

    //TODO: After discussion add player.getMap().getCell(player.getPosition()).draw() using color or italic 
    //TODO: Add inventory list display and other related to interface stuff to draw after discussion 

}



void Monitor::keyEvent(char key) {
    
}


void Monitor::keyEvent() {
    char pressed_key = getch();
    keyEvent(pressed_key);
}

void Monitor::addKeyChooseNextRooms(Player* player){
    if(player == nullptr){
        throw std::logic_error("Player undefined");
    }
    for(auto& action:player->getActions()){
        if(auto chooseNextRoom = std::dynamic_pointer_cast<actions::ChooseNextRoom>(action)){
            switch (player->getMap()->getDirecrion(player->getPosition(), chooseNextRoom->getPostion())) {
                case Map::direction::up:
                    break;
                case Map::direction::down:
                    break;
                case Map::direction::left:
                    break;
                case Map::direction::right:
                    break;
            }
        }
    }
}