//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H

// Non-selfmade library for UI realisation
#include <ncurses.h>
#include <vector>
class Player;
//       x --->
//  y
//  |
//  |
//  \/



//At this moment ncurses mode starts with initialistion of Monitor
class Monitor{
public:
    void draw(Player*);//Ask draw functions realizations from Map, Entity and Event if needed
    Monitor() = delete;
    Monitor(Player* player);
    ~Monitor();


    void draw(Player* player);//Ask draw functions realizations from Map, Entity and Event if needed
    void draw();
    void keyEvent(char);


    void keyEvent(char key);
    void keyEvent();

private:


    // Don't want to give access to GameWindow and its childs in other files, it's only for Monitor usage
    class GameWindow{
    public:
        GameWindow();
        ~GameWindow() = default;
        GameWindow(const size_t& pos_y, const size_t& pos_x, const size_t& y_size, const size_t& x_size);


        //Just placing sprite or text without clearing all previous text
        void draw_sprite(const size_t& pos_y, const size_t& pos_x,
                        const std::vector<std::vector<char>>& sprite, int attribute = A_NORMAL);
        void draw_text(const size_t& pos_y, const size_t& pos_x,
                        const std::vector<char>& text, int attribute = A_NORMAL);


        const size_t m_x_size;
        const size_t m_y_size;
    private:
        WINDOW* m_current_window;
    };


    Player* m_bounded_player;
    GameWindow m_inventory_display;
    GameWindow m_map_display;
    std::vector<GameWindow> m_entity_window;
    GameWindow m_background_display;
};
#endif //UNTITLED_MONITOR_H
