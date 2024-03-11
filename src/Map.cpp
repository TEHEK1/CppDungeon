#include "Map.h"
#include <iostream>
#include <vector>

namespace {

constexpr int MAP_SIZE = 50; // doesn't depenend on window size
constexpr int MINIMAL_ROOMS = 5;

enum CellType {EMPTY = 0, ROOM = 1, CORIDOR = 2, NEW_CORIDOR = 3};
enum RoomPosition {TOP = 0, RIGHT = 1, BOTTOM = 2, LEFT = 3, CENTER = 4};

struct Room {
    char side;
    Position pos;
};

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

bool Map::ValidForCoridor(int line, int column) const  {

    if (line < 0  || line >= MAP_SIZE) {
        return false;
    }
    if (column < 0  || column >= MAP_SIZE) {
        return false;
    }

    const char beginLineCheck   = line - 1;
    const char endLineCheck     = line + 1;
    const char beginColumnCheck = column - 1;
    const char endColumnCheck   = column + 1;
    
    for (char i = beginLineCheck; i <= endLineCheck; i++) {
        for (char j = beginColumnCheck; j <= endColumnCheck; j++)  {
            if (m_contents[i][j] != CellType::EMPTY && m_contents[i][j] != NEW_CORIDOR) {
                return false;
            }
        }
    }

    return true;
}

void Map::DeleteNewCoridors() {
    for (std::vector<char> i : m_contents) {
        for (char j : i) {
            if (j == CellType::NEW_CORIDOR) {
                j = CellType::EMPTY;
            }
        }
    }
}

void Map::SolidifyNewCoridors() {
    for (std::vector<char> i : m_contents) {
        for (char j : i) {
            if (j == CellType::NEW_CORIDOR) {
                j = CellType::CORIDOR;
            }
        }
    }
}

bool Map::CreatePath (char begin_line, char begin_column, char end_line, char end_column, int seed, bool main_call) {
    // returns true if path has been built without problems
    Position begin, current, end;

    begin.m_column   = begin_column;
    begin.m_line     = begin_line;

    current.m_column = begin_column;
    current.m_line   = begin_line;

    end.m_column     = end_column;
    end.m_line       = end_line;

    Position mainStep, randomStep;

    if (begin_column < end_column && begin_line < end_line) {

        mainStep.m_column   = 1;
        mainStep.m_line     = 0;
        randomStep.m_column = 0;
        randomStep.m_line   = 1;

    } else if (begin_column < end_column && begin_line > end_line) {
        mainStep.m_column   = 1;
        mainStep.m_line     = 0;
        randomStep.m_column = 0;
        randomStep.m_line   = -1;
    } else if (begin_column > end_column && begin_line < end_line) {

        mainStep.m_column   = -1;
        mainStep.m_line     = 0;
        randomStep.m_column = 0;
        randomStep.m_line   = 1;

    } else if (begin_column > end_column && begin_line > end_line) {

        mainStep.m_column   = -1;
        mainStep.m_line     = 0;
        randomStep.m_column = -1;
        randomStep.m_line   = 0;

    } else if (begin_column == end_column) {

        char middle_line = (end_line + begin_line)/2;
        char middle_column = begin_column + (getRandomValue(seed) % 5 - 2);

        bool firstHalf = CreatePath(begin_line, begin_column, middle_line, middle_column, seed, false);
        bool secondHalf = CreatePath(middle_line, middle_column, end_line, end_column, seed, false);

        if (firstHalf && secondHalf == true) {
            if (main_call == true) {
                SolidifyNewCoridors();
            }
            return true;
        } else {
            if (main_call == true) {
                DeleteNewCoridors();
            }
            return false;
        }

    } else if (begin_line == end_line) {

        char middle_column = (end_column + begin_column)/2;
        char middle_line = begin_line + (getRandomValue(seed) % 5 - 2);

        bool firstHalf = CreatePath(begin_line, begin_column, middle_line, middle_column, seed, false);
        bool secondHalf = CreatePath(middle_line, middle_column, end_line, end_column, seed, false);

        if (firstHalf && secondHalf == true) {
            if (main_call == true) {
                SolidifyNewCoridors();
            }
            return true;
        } else {
            if (main_call == true) {
                DeleteNewCoridors();
            }
            return false;
        }

    }

    char height = end_column - begin_column;

    if (height < 0) {
        height = -height;
    }

    char width = end_line - begin_line;
    if  (width < 0) {
        width = -width;
    }

    if (height > width) {
        std::swap(mainStep, randomStep);
    }

    if (main_call == true) {
        char specifyDirection = getRandomValue(seed)%2;

        if (specifyDirection == 0) {
            end_line   -= 2 * mainStep.m_line;
            end_column -= 2 * mainStep.m_column;
        }  else {
            end_line   -= 2 * randomStep.m_line;
            end_column -= 2 * randomStep.m_column;
        }

    }
    

    while (current.m_column != end.m_column  &&  current.m_line != end.m_line) {

        int odds;

        if (mainStep.m_column != 0) {
            odds = (1 - static_cast<double>(current.m_column - end.m_column) / (begin.m_column - end.m_column)) * 100;
            
            if (current.m_column - end.m_column == 0) {
                odds = 100;
            }

            if (current.m_line - end.m_line  == 0) {
                odds = 0;
            }
        } else {
            odds = (1 - static_cast<double>(current.m_line - end.m_line) / (begin.m_line - end.m_line)) * 100;
            
            if (current.m_line - end.m_line == 0) {
                odds = 100;
            }

            if (current.m_column - end.m_column  == 0) {
                odds = 0;
            }
        }
        int generatedValue = getRandomValue(seed)%100;

        if (generatedValue < odds) {

            current.m_column += randomStep.m_column;
            current.m_line   += randomStep.m_line;

        } else {

            current.m_column += mainStep.m_column;
            current.m_line   += mainStep.m_line;

        }

        if (ValidForCoridor(current.m_line, current.m_column) == true)  {
            m_contents[current.m_line][current.m_column] = CellType::NEW_CORIDOR;
        } else {
            DeleteNewCoridors();
            return false;
        }

    }  

    SolidifyNewCoridors();
    return true;
}


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
    std::vector<std::vector<char>> connections(roomProperties.size());
    // for (char i = 0; i < roomProperties.size(); i++) {
    //     if (roomProperties[i].side != RoomPosition::CENTER) {
    //         occupiedSides[i][roomProperties[i].side] = 1;
    //     }
    // }

    bool davai_po_novoi_misha = true;

    while (davai_po_novoi_misha) {

        davai_po_novoi_misha = false;

        for (char i = roomProperties.size() - 1; i >= 0; i--) {
            for (char side = TOP; side <= LEFT; side++) {

                if (roomProperties[i].side != RoomPosition::CENTER) {
                    char generatedValue = getRandomValue(seed)%100;

                    if (generatedValue < 30) {

                        char destination = getRandomValue(seed)%roomProperties.size();
                        if (destination != i) {

                            char beginLine   = roomProperties[i].pos.m_line;
                            char beginColumn = roomProperties[i].pos.m_column;

                            if (side == TOP) {
                                beginColumn -= 2;
                            } else if (side == RIGHT) {
                                beginLine += 2;
                            } else if (side == BOTTOM) {
                                beginColumn += 2;
                            } else if (side == LEFT)  {
                                beginLine  -= 2;
                            }

                            char endLine     = roomProperties[destination].pos.m_line;
                            char endColumn   = roomProperties[destination].pos.m_column;

                            if (CreatePath(beginLine, beginColumn, endLine, endColumn, seed, true)) {
                                davai_po_novoi_misha = true;
                            }

                        }

                    }

                }

            } // second for loop
        } // first for loop

    } // while loop

}

Map::Map()
: Map::Map(time(NULL)) {}

} // namespace