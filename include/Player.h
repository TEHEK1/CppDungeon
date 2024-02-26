//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <vector>
class Hero;
class Position;
class Map;
class Monitor;
class Player{
public:
    std::vector<Hero*> getHeroes();
    Monitor* getMonitor();
    Position getPosition();
    Map* getMap();
};
#endif //UNTITLED_PLAYER_H
