#include "Map.h"
#include <iostream>
#include <vector>


constexpr int MAP_SIZE = 50; // doesn't depenend on window size
constexpr int MINIMAL_ROOMS = 5;

enum CellType {EMPTY = 0, ROOM = 1, CORIDOR = 2, NEW_CORIDOR = 3};
enum RoomPosition {TOP = 0, RIGHT = 1, BOTTOM = 2, LEFT = 3, CENTER = 4};

struct Room {
    char side;
    Position pos;
};

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

    if (line < 2  || line >= MAP_SIZE - 2) {
        return false;
    }
    if (column < 2  || column >= MAP_SIZE - 2) {
        return false;
    }

    const char beginLineCheck   = line - 1;
    const char endLineCheck     = line + 1;
    const char beginColumnCheck = column - 1;
    const char endColumnCheck   = column + 1;
    
    for (char i = beginLineCheck; i <= endLineCheck; i++) {
        for (char j = beginColumnCheck; j <= endColumnCheck; j++)  {
            if (!(m_contents[i][j] == CellType::EMPTY || m_contents[i][j] == NEW_CORIDOR)) {
                return false;
            }
        }
    }

    return true;
}

void Map::DeleteNewCoridors() {
    for (std::vector<char>& i : m_contents) {
        for (char& j : i) {
            if (j == CellType::NEW_CORIDOR) {
                j = CellType::EMPTY;
            }
        }
    }
}

void Map::SolidifyNewCoridors() {
    for (std::vector<char>& i : m_contents) {
        for (char& j : i) {
            if (j == CellType::NEW_CORIDOR) {
                j = CellType::CORIDOR;
            }
        }
    }
}

void Map::HolocaustCoridors() {
    for (std::vector<char>& i : m_contents) {
        for (char& j : i) {
            if (j == CellType::CORIDOR) {
                j = CellType::EMPTY;
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
        randomStep.m_column = 0;
        randomStep.m_line   = -1;

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
        char specifyDirection = generator() % 2;

        if (specifyDirection == 0) {
            end.m_line   -= 2 * mainStep.m_line;
            end.m_column -= 2 * mainStep.m_column;
            m_contents[end.m_line][end.m_column] = CellType::NEW_CORIDOR;
            end.m_line   -= mainStep.m_line;
            end.m_column -= mainStep.m_column;

        } else {
            end.m_line   -= 2 * randomStep.m_line;
            end.m_column -= 2 * randomStep.m_column;
            m_contents[end.m_line][end.m_column] = CellType::NEW_CORIDOR;
            end.m_line   -= randomStep.m_line;
            end.m_column -= randomStep.m_column;
        }

        bool flag = CreatePath(begin.m_line, begin.m_column, end.m_line, end.m_column, seed, false);
        return flag;

    }
    
    while (current.m_column != end.m_column || current.m_line != end.m_line) {

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

        int generatedValue = generator()%100;

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


void Map::PrintWholeMap() {
    for (int i = 5; i < 45; i++) {
        for (int j = 5; j < 45; j++) {
            std::cout << (int)m_contents[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout <<  std::endl;
}

Map::Map(int seed) {

    generator.seed(seed);

    m_contents.resize(MAP_SIZE); // zero means empty cell
    for (std::vector<char>& line : m_contents) {
        line.resize(MAP_SIZE);
    }

    char roomsToGenerate = MINIMAL_ROOMS + (generator() % 4); // we will have from 5 to 8 rooms

    const short CENTER_BEGIN = (MAP_SIZE / 2) - (MAP_SIZE / 10);
    bool generatedCenter     = false;
    std::vector<std::vector<char>> roomCounter;
    roomCounter.resize(4); // there are 4 different positions: top/right/bottom/left
    std::vector<Room> roomProperties;
    roomProperties.resize(roomsToGenerate);

    std::vector<std::vector<char>> availablePaths(roomsToGenerate, std::vector<char>());
    
    // generating rooms (works!)
    while (roomsToGenerate > 0) {

        if (generatedCenter == false) { // generating center rooms

            char centerLine = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));
            char centerColumn = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));

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
                    centerLine = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));
                    centerColumn = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));

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

                roomsToGenerate--;
                roomProperties[roomsToGenerate].side         = RoomPosition::CENTER;
                roomProperties[roomsToGenerate].pos.m_line   = centerLine;
                roomProperties[roomsToGenerate].pos.m_column = centerColumn;

            }

            generatedCenter = true;

        } else { // generating ordinary rooms

            char roomPosition = (generator() % 4);

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

                    roomLine   = MOVED_POSITION + generator() % SMALL_RANGE;
                    roomColumn = DEFAULT_POSITION + generator() % BIG_RANGE;

                } else if (roomPosition == RoomPosition::LEFT) {

                    roomLine   = DEFAULT_POSITION + generator() % BIG_RANGE;
                    roomColumn = DEFAULT_POSITION + generator() % SMALL_RANGE;

                } else if (roomPosition == RoomPosition::RIGHT) {

                    roomLine   = DEFAULT_POSITION + generator() % BIG_RANGE;
                    roomColumn = MOVED_POSITION + generator() % SMALL_RANGE;

                } else { // TOP

                    roomLine   = DEFAULT_POSITION + generator() % SMALL_RANGE;
                    roomColumn = DEFAULT_POSITION + generator() % BIG_RANGE;

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

    // connecting rooms
    std::vector<std::vector<char>> occupiedSides(roomProperties.size(), std::vector<char>(4, 0));
    std::vector<std::vector<char>> connections(roomProperties.size());

    bool davai_po_novoi_misha = true;

    while (davai_po_novoi_misha) {

        HolocaustCoridors();
        for (std::vector<char>& occupatied : occupiedSides) {
            occupatied = std::vector<char>(4, 0);
        }

        for (std::vector<char>& paths : connections) {
            paths = std::vector<char>();
        }

        davai_po_novoi_misha = false;

        for (char i = roomProperties.size() - 1; i >= 0; i--) {
            if (davai_po_novoi_misha) {
                break;
            }
            for (char side = TOP; side <= LEFT; side++) {
                if (occupiedSides[i][side] == true) {
                    continue;
                }

                char generatedValue;
                if (roomProperties[i].side != RoomPosition::CENTER) {
                    generatedValue = generator() % 100;
                } else {
                    generatedValue = 0;
                }

                if (generatedValue < 30) {

                    bool needNewDestination  = true;
                    char destination;  

                    while(needNewDestination == true) {
                        needNewDestination =  false;
                        destination = generator() % roomProperties.size();
                        if (destination == i) {
                            needNewDestination = true;
                        } else {
                            for (int iter = 0; iter < connections[i].size(); iter++) {
                                if (connections[i][iter] == destination) {
                                    needNewDestination = true;
                                }
                            }
                        }
                        
                    }

                    char beginLine   = roomProperties[i].pos.m_line;
                    char beginColumn = roomProperties[i].pos.m_column;

                    if (side == TOP) {
                        beginLine -= 2;
                        m_contents[beginLine][beginColumn] = CellType::NEW_CORIDOR;
                        beginLine--;
                    } else if (side == RIGHT) {
                        beginColumn += 2;
                        m_contents[beginLine][beginColumn] = CellType::NEW_CORIDOR;
                        beginColumn++;
                    } else if (side == BOTTOM) {
                        beginLine += 2;
                        m_contents[beginLine][beginColumn] = CellType::NEW_CORIDOR;
                        beginLine++;
                    } else if (side == LEFT)  {
                        beginColumn -= 2;
                        m_contents[beginLine][beginColumn] = CellType::NEW_CORIDOR;
                        beginColumn--;
                    }
                    m_contents[beginLine][beginColumn] = CellType::NEW_CORIDOR;

                    char endLine     = roomProperties[destination].pos.m_line;
                    char endColumn   = roomProperties[destination].pos.m_column;

                    bool createdSuccessfuly = CreatePath(beginLine, beginColumn, endLine, endColumn, seed, true);

                    if (createdSuccessfuly == false) {
                        davai_po_novoi_misha = true;
                        break;
                    } else {
                        connections[i].push_back(destination);
                        connections[destination].push_back(i);

                        occupiedSides[i][side] = true;
                        for (char side_checker = TOP; side_checker <= LEFT; side_checker++) {
                            if (occupiedSides[destination][side_checker] == false) {

                                if (side_checker == TOP) {

                                    if (m_contents[endLine][endColumn + 2] == CellType::CORIDOR) {
                                        occupiedSides[destination][side_checker] = true;
                                    }

                                } else if (side_checker == RIGHT) {

                                    if (m_contents[endLine + 2][endColumn] == CellType::CORIDOR) {
                                        occupiedSides[destination][side_checker] = true;
                                    }

                                } else if (side_checker == BOTTOM) {

                                    if (m_contents[endLine][endColumn - 2] == CellType::CORIDOR) {
                                            occupiedSides[destination][side_checker] = true;
                                    }

                                } else if (side_checker  == LEFT) {

                                    if (m_contents[endLine - 2][endColumn] == CellType::CORIDOR) {
                                        occupiedSides[destination][side_checker] = true;
                                    }

                                }

                            }
                                
                        }

                    }

                }

            } // second for loop

            if (davai_po_novoi_misha) {
                break;
            }

        } // first for loop

        if (davai_po_novoi_misha == false) {
            // check for existance of room with 4 neighbours
            bool flag = false;
            for (char from  = 0; from < connections.size(); from++) {
                if (connections[from].size() >= 4) {
                    flag = true;
                }
            }
            if (flag == false) {
                davai_po_novoi_misha = true;
            } else {
                // BFS for vertexes
                std::queue<char> vertex;
                std::vector<char> checked(roomProperties.size(), 0);
                vertex.push(0);
                while (!vertex.empty()) {
                    char tmp = vertex.front();
                    vertex.pop();
                    checked[tmp] = 1;
                    for (char iter = 0; iter < connections[tmp].size(); iter++) {
                        if (checked[connections[tmp][iter]] == 0) {
                            vertex.push(connections[tmp][iter]);
                            checked[connections[tmp][iter]] = 1;
                        }
                    }
                }

                for (char visited : checked) {
                    if (visited  == 0) {
                        davai_po_novoi_misha  = true;
                    }
                }
            }
        }
        

    } // while loop
}

Map::Map()
: Map::Map(time(NULL)) {}
