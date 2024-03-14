//
// Created by Амир Кашапов on 25.02.2024.
//

#ifndef CPPDUNGEON_POSITION_H
#define CPPDUNGEON_POSITION_H
class Position{
public:
    friend class Map;
    char getLine();
    char getColumn();
    char getDestination();
private:
    char m_line;
    char m_column;
    char m_destination;
    char m_prevLine;
    char m_prevColumn;

};
#endif //CPPDUNGEON_POSITION_H
