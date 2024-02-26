//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H
class Player;
class Monitor{
public:
    void draw(Player*);//Ask draw functions realizations from Map, Entity and Event if needed
    void draw();
    void keyEvent(char);
    void keyEvent();
};
#endif //UNTITLED_MONITOR_H
