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


    void keyEvent(char key, Player* player);
    void keyEvent(Player* player);

private:

    void addKeysNavigation(Player* player);

    // Don't want to give access to GameWindow and its childs in other files, it's only for Monitor usage
    class GameWindow {
        public:
            GameWindow();
            GameWindow(const GameWindow& other);
            ~GameWindow() = default;
            GameWindow(const size_t& pos_y, const size_t& pos_x, const size_t& y_size, const size_t& x_size);


            //Just placing sprite or text without clearing all previous text
            void draw_sprite(const size_t& pos_y, const size_t& pos_x,
                            const std::vector<std::vector<char>>& sprite, bool skip_spaces = false, int attribute = A_NORMAL);
            void draw_text(const size_t& pos_y, const size_t& pos_x,
                            const std::string& text, bool skip_spaces = false, int attribute = A_NORMAL) ;

            void clear_atr(size_t row = 0, size_t col = 0, int num = -1);
            size_t get_x() const;
            size_t get_y() const;
            void set_atr(size_t row, size_t col, size_t num = 1, attr_t atr = A_NORMAL, short color = 0);

        protected:
            WINDOW* m_current_window;
            size_t m_x_size;
            size_t m_y_size;
    };

    class InterfaceColumnWindow : public GameWindow {
        public:
            InterfaceColumnWindow();
            InterfaceColumnWindow(const size_t& y_size, const size_t& x_size, const size_t& pos_y, const size_t& pos_x);
            InterfaceColumnWindow(const InterfaceColumnWindow& other);
            ~InterfaceColumnWindow() = default;
            friend Monitor;
            char find_action(std::shared_ptr<actions::Action> action);
            void draw_interface(std::set<std::shared_ptr<actions::Action>> available_actions, bool adaptive = true);
            void get_binds();
        private:
            std::vector<GameWindow> m_columns;
            char m_first_unbind = 'a';
            std::map<char, std::shared_ptr<actions::Action>> m_key_binds;
    };

    static void abs_coordinates_to_relative(int& row, int& col, const GameWindow& cur_window, Position center);

    


    GameWindow m_inventory_display;
    InterfaceColumnWindow m_user_actions_display;
    GameWindow m_map_display;
    std::vector<GameWindow> m_entity_window;
    GameWindow m_background_display;
};
#endif //UNTITLED_MONITOR_H
