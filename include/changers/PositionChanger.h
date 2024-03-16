//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_POSITIONCHANGER_H
#define CPPDUNGEON_POSITIONCHANGER_H
class Player;
class Position;
namespace changers {
    class PositionChanger {
    protected:
        static void setPosition(Player *, Position);
    };
} // namespace changers
#endif //CPPDUNGEON_POSITIONCHANGER_H
