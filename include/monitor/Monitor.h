//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H

// Non-selfmade library for UI realisation
#include <ncurses.h>
#include <vector>
#include <map>
#include <memory>
#include <actions/Action.h>
#include <navigation/Map.h>
class Player;
//       x --->
//  y
//  |
//  |
//  \/



//At this moment ncurses mode starts with initialistion of Monitor
class Monitor{
public:
    Monitor();
    ~Monitor() = default;


    void draw(Player* player);//Ask draw functions realizations from Map, Entity and Event if needed


    void keyEvent(char key);
    void keyEvent();

private:

    void addKeyChooseNextRooms(Player* player);

    // Don't want to give access to GameWindow and its childs in other files, it's only for Monitor usage
    class GameWindow {
        public:
            GameWindow();
            GameWindow(const GameWindow& other);
            ~GameWindow() = default;
            GameWindow(const size_t& pos_y, const size_t& pos_x, const size_t& y_size, const size_t& x_size);


            //Just placing sprite or text without clearing all previous text
            void draw_sprite(const size_t& pos_y, const size_t& pos_x,
                            const std::vector<std::vector<char>>& sprite, int attribute = A_NORMAL);
            void draw_text(const size_t& pos_y, const size_t& pos_x,
                            const std::vector<char>& text, int attribute = A_NORMAL) ;

            void clear_atr(size_t row = 0, size_t col = 0, int num = -1);
            size_t get_x() const;
            size_t get_y() const;
            void set_atr(size_t row, size_t col, size_t num = 1, attr_t atr = A_NORMAL, short color = 0);

        private:
            WINDOW* m_current_window;
            size_t m_x_size;
            size_t m_y_size;
    };

    class InterfaceColumnWindow : public GameWindow {
        public:
            void draw_interface();
            void get_binds();
        private:
            std::vector<std::vector<GameWindow>> m_columns;
            const size_t m_max_string_len = 10;
            std::map<char, std::shared_ptr<actions::Action>> m_key_binds;
    };

    static void abs_coordinates_to_relative(int& row, int& col, const GameWindow& cur_window, Position center);

    


    GameWindow m_inventory_display;
    GameWindow m_user_actions_display;
    GameWindow m_map_display;
    std::vector<GameWindow> m_entity_window;
    GameWindow m_background_display;
};
#endif //UNTITLED_MONITOR_H
