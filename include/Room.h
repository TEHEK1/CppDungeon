//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H
#include "Cell.h"
class Room:public Cell{
public:
    void generateEvents() override;
};
#endif //UNTITLED_ROOM_H