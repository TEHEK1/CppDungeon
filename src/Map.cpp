#include "Map.h"
#include <iostream>
#include <vector>

namespace {

constexpr int MAP_SIZE = 50; // doesn't depenend on window size
constexpr int MINIMAL_ROOMS = 5;

enum CellType {EMPTY = 0, ROOM = 1, CORIDOR = 2};
enum RoomPosition {TOP = 0, RIGHT = 1, BOTTOM = 2, LEFT = 3, CENTER = 4};


int Map::getRandomValue(int seed) {
    #ifndef GENERATOR_RANDOM_SEED
        #define GENERATOR_RANDOM_SEED
        srand(seed);
    #endif
    return rand();
}

std::vector<std::vector<char>> Map::draw() {
    return m_contents;
}

int Map::getSize() {
    return m_size;
}

bool Map::ValidForRoom(int line, int column) const {

    if ((line - 3 < MAP_SIZE/10) || (line + 3 > MAP_SIZE - MAP_SIZE/10)) {
        return false;
    }
    if ((column - 3 < MAP_SIZE/10) || (column + 3 > MAP_SIZE - MAP_SIZE/10)) {
        return false;
    }

    const char beginLineCheck   = line - 3;
    const char endLineCheck     = line + 3;
    const char beginColumnCheck = column - 3;
    const char endColumnCheck   = column + 3;

    for (char i = beginLineCheck; i <= endLineCheck; i++) {
        for (char j = beginColumnCheck; j <= endColumnCheck; j++)  {
            if (m_contents[i][j] != CellType::EMPTY) {
                return false;
            }
        }
    }

    return true;
}

struct Room {
    char side;
    Position pos;
};

Map::Map(int seed) {

    m_contents.resize(MAP_SIZE); // zero means empty cell
    for (auto line : m_contents) {
        line.resize(MAP_SIZE);
    }

    char roomsToGenerate     = MINIMAL_ROOMS + (getRandomValue(seed) % 4); // we will have from 5 to 8 rooms
    const short CENTER_BEGIN = (MAP_SIZE / 2) - (MAP_SIZE / 10);
    bool generatedCenter     = false;
    std::vector<std::vector<char>> roomCounter;
    roomCounter.resize(4); // there are 4 different positions: top/right/bottom/left
    std::vector<Room> roomProperties;
    roomProperties.resize(roomsToGenerate);

    std::vector<std::vector<char>> availablePaths(roomsToGenerate, std::vector<char>());
    
    // generating rooms
    while (roomsToGenerate > 0) {

        if (generatedCenter == false) { // generating center rooms

            char centerLine = CENTER_BEGIN + (getRandomValue(seed) % (MAP_SIZE / 5));
            char centerColumn = CENTER_BEGIN + (getRandomValue(seed) % (MAP_SIZE / 5));

            for (char i = centerLine - 1; i <= centerLine + 1; i++) {
                for (char j = centerColumn - 1; j <= centerColumn + 1; j++) {
                    m_contents[i][j] = CellType::ROOM;
                }
            }

            roomsToGenerate--;
            roomProperties[roomsToGenerate].side         = RoomPosition::CENTER;
            roomProperties[roomsToGenerate].pos.m_line   = centerLine;
            roomProperties[roomsToGenerate].pos.m_column = centerColumn;
            // generaing first center room

            if (roomsToGenerate == 7) {
                while (true) {
                    centerLine = CENTER_BEGIN + (getRandomValue(seed) % (MAP_SIZE / 5));
                    centerColumn = CENTER_BEGIN + (getRandomValue(seed) % (MAP_SIZE / 5));

                    if ( ValidForRoom(centerLine, centerColumn) == true ) {
                        break;
                    }
                }

                for (char i = centerLine - 1; i <= centerLine + 1; i++) {
                    for (char j = centerColumn - 1; j <= centerColumn + 1; j++) {
                        m_contents[i][j] = CellType::ROOM;
                    }
                }
                //generating second center room

            }

            roomsToGenerate--;
            roomProperties[roomsToGenerate].side         = RoomPosition::CENTER;
            roomProperties[roomsToGenerate].pos.m_line   = centerLine;
            roomProperties[roomsToGenerate].pos.m_column = centerColumn;

            generatedCenter = true;

        } else { // generating ordinary rooms

            char roomPosition = (getRandomValue(seed) % 4);

            while (roomCounter[roomPosition].size() >= 2) { // preventing overloads
                roomPosition = (roomPosition + 1) % 4;
            }

            char roomLine;
            char roomColumn;

            const char DEFAULT_POSITION = MAP_SIZE / 10;
            const char MOVED_POSITION   = (MAP_SIZE / 5) * 3;

            const char SMALL_RANGE = (MAP_SIZE / 5) * 2;
            const char BIG_RANGE   = MAP_SIZE - 2 * DEFAULT_POSITION;

            while (true) {

                if (roomPosition == RoomPosition::BOTTOM) {

                    roomLine   = MOVED_POSITION + getRandomValue(seed) % SMALL_RANGE;
                    roomColumn = DEFAULT_POSITION + getRandomValue(seed) % BIG_RANGE;

                } else if (roomPosition == RoomPosition::LEFT) {

                    roomLine   = DEFAULT_POSITION + getRandomValue(seed) % BIG_RANGE;
                    roomColumn = DEFAULT_POSITION + getRandomValue(seed) % SMALL_RANGE;

                } else if (roomPosition == RoomPosition::RIGHT) {

                    roomLine   = DEFAULT_POSITION + getRandomValue(seed) % BIG_RANGE;
                    roomColumn = MOVED_POSITION + getRandomValue(seed) % SMALL_RANGE;

                } else { // TOP

                    roomLine   = DEFAULT_POSITION + getRandomValue(seed) % SMALL_RANGE;
                    roomColumn = DEFAULT_POSITION + getRandomValue(seed) % BIG_RANGE;

                }

                if ( ValidForRoom(roomLine, roomColumn) == true ) {
                    break;
                }

            }

            for (char i = roomLine - 1; i <= roomLine + 1; i++) {
                for (char j = roomColumn - 1; j <= roomColumn + 1; j++) {
                    m_contents[i][j] = CellType::ROOM;
                }
            }

            roomsToGenerate--;
            roomProperties[roomsToGenerate].side         = roomPosition;
            roomProperties[roomsToGenerate].pos.m_line   = roomLine;
            roomProperties[roomsToGenerate].pos.m_column = roomColumn;
            roomCounter[roomPosition].push_back(roomsToGenerate);

        }

    }

    // generating coridors

    // connecting rooms
    std::vector<std::vector<char>> occupiedSides(roomProperties.size(), std::vector<char>(4, 0));
    for (char i = 0; i < roomProperties.size(); i++) {
        if (roomProperties[i].side != RoomPosition::CENTER) {
            occupiedSides[i][roomProperties[i].side] = 1;
        }
    }


    for (char i = roomProperties.size() - 1; i >= 0; i--) {
        
    }
}

Map::Map()
: Map::Map(time(NULL)) {}

} // namespace