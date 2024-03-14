#include "Map.h"
#include "Cell.h"
#include "Hall.h"
#include "Room.h"
#include "EmptyCell.h"
#include <iostream>
#include <vector>


constexpr int MAP_SIZE = 50; // doesn't depenend on window size
constexpr int MINIMAL_ROOMS = 5;

enum CellType {empty = 0, room = 1, hall = 2, new_hall = 3};
enum RoomPosition {top = 0, right = 1, bottom = 2, left = 3, center = 4};

struct MyDefinitionRoom {
    char side;
    Position pos;
};

int Map::getSeed() {
    return generatorSeed;
}

std::vector<std::vector<char>> Map::draw() {
    return m_contents;
}

std::shared_ptr<Cell> Map::getCell(Position pos) {
    return m_cells[pos.m_line][pos.m_column];
}

std::vector<Position> Map::getNextRooms(Position pos) {
    int roomIndex = -1;
    std::vector<Position> answer;
    for (int i = 0; i < m_roomPositions.size(); i++) {
        if (m_roomPositions[i].m_column == pos.m_column && m_roomPositions[i].m_line  == pos.m_line) {
            roomIndex = i;
            break;
        }
    }
    for (int i = 0; i < m_edges[roomIndex].size(); i++) {
        answer.push_back(m_roomPositions[m_edges[roomIndex][i]]);
    }
    return answer;
}

int Map::getSize() {
    int answer = 0;
    for (std::vector<char> i : m_contents) {
        for (char j : i) {
            if (j != CellType::empty) {
                answer++;
            }
        }
    }
    return answer;
}

bool Map::validForRoom(int line, int column) const {


    if ((line - 5 < MAP_SIZE/10) || (line + 5 > MAP_SIZE - MAP_SIZE/10)) {
        return false;
    }
    if ((column - 5 < MAP_SIZE/10) || (column + 5 > MAP_SIZE - MAP_SIZE/10)) {
        return false;
    }

    const char beginLineCheck   = line - 5;
    const char endLineCheck     = line + 5;
    const char beginColumnCheck = column - 5;
    const char endColumnCheck   = column + 5;

    for (char i = beginLineCheck; i <= endLineCheck; i++) {
        for (char j = beginColumnCheck; j <= endColumnCheck; j++)  {
            if (m_contents[i][j] != CellType::empty) {
                return false;
            }
        }
    }
    return true;
}

bool Map::validForHall(int line, int column) const  {

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
            if (!(m_contents[i][j] == CellType::empty || m_contents[i][j] == new_hall)) {
                return false;
            }
        }
    }

    return true;
}

void Map::deleteNewHalls() {
    for (std::vector<char>& i : m_contents) {
        for (char& j : i) {
            if (j == CellType::new_hall) {
                j = CellType::empty;
            }
        }
    }
}

void Map::solidifyNewHalls() {
    for (std::vector<char>& i : m_contents) {
        for (char& j : i) {
            if (j == CellType::new_hall) {
                j = CellType::hall;
            }
        }
    }
}

void Map::holocaustHalls() {
    for (std::vector<char>& i : m_contents) {
        for (char& j : i) {
            if (j == CellType::hall) {
                j = CellType::empty;
            }
        }
    }
}

bool Map::createPath (char begin_line, char begin_column, char end_line, char end_column, int seed, bool main_call) {
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

    } else if (begin_column == end_column || begin_line == end_line) {
        deleteNewHalls();
        return false;
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
            if (m_contents[end.m_line][end.m_column] == CellType::empty) {

                m_contents[end.m_line][end.m_column] = CellType::new_hall;

            } else {

                deleteNewHalls();
                return false;

            }
            end.m_line   -= mainStep.m_line;
            end.m_column -= mainStep.m_column;

        } else {
            end.m_line   -= 2 * randomStep.m_line;
            end.m_column -= 2 * randomStep.m_column;
            if (m_contents[end.m_line][end.m_column] == CellType::empty) {

                m_contents[end.m_line][end.m_column] = CellType::new_hall;

            } else {

                deleteNewHalls();
                return false;

            }
            end.m_line   -= randomStep.m_line;
            end.m_column -= randomStep.m_column;
        }

        bool flag = createPath(begin.m_line, begin.m_column, end.m_line, end.m_column, seed, false);
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

        if (validForHall(current.m_line, current.m_column) == true)  {
            m_contents[current.m_line][current.m_column] = CellType::new_hall;
        } else {
            deleteNewHalls();
            return false;
        }

    }
    

    solidifyNewHalls();
    return true;
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
    std::vector<MyDefinitionRoom> roomProperties;
    m_roomPositions.resize(roomsToGenerate);
    roomProperties.resize(roomsToGenerate);

    std::vector<std::vector<char>> availablePaths(roomsToGenerate, std::vector<char>());
    
    // generating rooms (works!)
    while (roomsToGenerate > 0) {

        if (generatedCenter == false) { // generating center rooms

            char centerLine = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));
            char centerColumn = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));

            for (char i = centerLine - 1; i <= centerLine + 1; i++) {
                for (char j = centerColumn - 1; j <= centerColumn + 1; j++) {
                    m_contents[i][j] = CellType::room;
                }
            }

            roomsToGenerate--;
            roomProperties[roomsToGenerate].side         = RoomPosition::center;
            roomProperties[roomsToGenerate].pos.m_line   = centerLine;
            roomProperties[roomsToGenerate].pos.m_column = centerColumn;
            // generaing first center room


            if (roomsToGenerate == 7) {
                while (true) {
                    centerLine = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));
                    centerColumn = CENTER_BEGIN + (generator() % (MAP_SIZE / 5));
                    if (centerLine != roomProperties[7].pos.m_line && centerColumn != roomProperties[7].pos.m_column) {
                        if ( validForRoom(centerLine, centerColumn) == true ) {
                            break;
                        }
                    } 
                }

                for (char i = centerLine - 1; i <= centerLine + 1; i++) {
                    for (char j = centerColumn - 1; j <= centerColumn + 1; j++) {
                        m_contents[i][j] = CellType::room;
                    }
                }
                //generating second center room

                roomsToGenerate--;
                roomProperties[roomsToGenerate].side         = RoomPosition::center;
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

                if (roomPosition == RoomPosition::bottom) {

                    roomLine   = MOVED_POSITION + generator() % SMALL_RANGE;
                    roomColumn = DEFAULT_POSITION + generator() % BIG_RANGE;

                } else if (roomPosition == RoomPosition::left) {

                    roomLine   = DEFAULT_POSITION + generator() % BIG_RANGE;
                    roomColumn = DEFAULT_POSITION + generator() % SMALL_RANGE;

                } else if (roomPosition == RoomPosition::right) {

                    roomLine   = DEFAULT_POSITION + generator() % BIG_RANGE;
                    roomColumn = MOVED_POSITION + generator() % SMALL_RANGE;

                } else { // top

                    roomLine   = DEFAULT_POSITION + generator() % SMALL_RANGE;
                    roomColumn = DEFAULT_POSITION + generator() % BIG_RANGE;

                }
                bool noLinearMatches = true;
                for (int index = roomProperties.size() - 1; index >= roomsToGenerate; index--) {
                    if (roomLine == roomProperties[index].pos.m_line || roomColumn == roomProperties[index].pos.m_column) {
                        noLinearMatches = false;
                    }
                }
                if ( validForRoom(roomLine, roomColumn) == true && noLinearMatches == true) {
                    break;
                }

            }

            for (char i = roomLine - 1; i <= roomLine + 1; i++) {
                for (char j = roomColumn - 1; j <= roomColumn + 1; j++) {
                    m_contents[i][j] = CellType::room;
                }
            }

            roomsToGenerate--;
            roomProperties[roomsToGenerate].side         = roomPosition;
            roomProperties[roomsToGenerate].pos.m_line   = roomLine;
            roomProperties[roomsToGenerate].pos.m_column = roomColumn;
            roomCounter[roomPosition].push_back(roomsToGenerate);

        }

    }
    for (int index = 0; index < m_roomPositions.size(); index++) {
        m_roomPositions[index] = roomProperties[index].pos;
    }
    //PrintWholeMap();

    // connecting rooms
    std::vector<std::vector<char>> occupiedSides(roomProperties.size(), std::vector<char>(4, 0));
    std::vector<std::vector<char>> connections(roomProperties.size());

    bool generateAgain = true;
    unsigned int iterationCounter = 0;

    while (generateAgain) {

        iterationCounter++;
        holocaustHalls();
        for (std::vector<char>& occupied : occupiedSides) {
            occupied = std::vector<char>(4, 0);
        }

        for (std::vector<char>& paths : connections) {
            paths = std::vector<char>();
        }

        generateAgain = false;

        for (char i = roomProperties.size() - 1; i >= 0; i--) {
            if (generateAgain) {
                break;
            }
            for (char side = top; side <= left; side++) {
                if (occupiedSides[i][side] == true) {
                    continue;
                }

                char generatedValue;
                if (i == roomProperties.size() - 1) {
                    generatedValue = generator() % 100;
                } else {
                    generatedValue = 0;
                }

                if (generatedValue < 50) {

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

                    if (side == top) {
                        beginLine -= 2;
                        if (m_contents[beginLine][beginColumn] == CellType::empty) {
                            m_contents[beginLine][beginColumn] = CellType::new_hall;
                        } else {
                            continue;
                        }
                        beginLine--;
                    } else if (side == right) {
                        beginColumn += 2;
                        if (m_contents[beginLine][beginColumn] == CellType::empty) {
                            m_contents[beginLine][beginColumn] = CellType::new_hall;
                        } else {
                            continue;
                        }
                        beginColumn++;
                    } else if (side == bottom) {
                        beginLine += 2;
                        if (m_contents[beginLine][beginColumn] == CellType::empty) {
                            m_contents[beginLine][beginColumn] = CellType::new_hall;
                        } else {
                            continue;
                        }
                        beginLine++;
                    } else if (side == left)  {
                        beginColumn -= 2;
                        if (m_contents[beginLine][beginColumn] == CellType::empty) {
                            m_contents[beginLine][beginColumn] = CellType::new_hall;
                        } else {
                            continue;
                        }
                        beginColumn--;
                    }
                    if ( validForHall(beginLine, beginColumn) ) {
                        m_contents[beginLine][beginColumn] = CellType::new_hall;
                    } else {
                        deleteNewHalls();
                        continue;
                    }

                    char endLine     = roomProperties[destination].pos.m_line;
                    char endColumn   = roomProperties[destination].pos.m_column;

                    bool createdSuccessfuly = createPath(beginLine, beginColumn, endLine, endColumn, seed, true);

                    if (createdSuccessfuly == false) {
                        if (roomProperties[i].side == RoomPosition::center) {
                            generateAgain = true;
                        }
                        break;
                    } else {
                        connections[i].push_back(destination);
                        connections[destination].push_back(i);

                        occupiedSides[i][side] = true;
                        for (char side_checker = top; side_checker <= left; side_checker++) {
                            if (occupiedSides[destination][side_checker] == false) {

                                if (side_checker == top) {

                                    if (m_contents[endLine][endColumn + 2] == CellType::hall) {
                                        occupiedSides[destination][side_checker] = true;
                                    }

                                } else if (side_checker == right) {

                                    if (m_contents[endLine + 2][endColumn] == CellType::hall) {
                                        occupiedSides[destination][side_checker] = true;
                                    }

                                } else if (side_checker == bottom) {

                                    if (m_contents[endLine][endColumn - 2] == CellType::hall) {
                                            occupiedSides[destination][side_checker] = true;
                                    }

                                } else if (side_checker  == left) {

                                    if (m_contents[endLine - 2][endColumn] == CellType::hall) {
                                        occupiedSides[destination][side_checker] = true;
                                    }

                                }

                            }
                                
                        }

                    }

                }

            } // second for loop

            if (generateAgain) {
                break;
            }
            //PrintWholeMap();

        } // first for loop

        if (generateAgain == false) {
            // check for existance of room with 4 neighbours
            bool flag = false;
            for (char from  = 0; from < connections.size(); from++) {
                if (connections[from].size() >= 4) {
                    flag = true;
                }
            }
            if (flag == false) {
                generateAgain = true;
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
                    if (visited == 0) {
                        generateAgain  = true;
                    }
                }
            }
        }

    } // while loop
    generatorSeed = seed;
    m_cells.resize(m_contents.size()); // zero means empty cell
    for (std::vector<std::shared_ptr<Cell>>& line : m_cells) {
        line.resize(m_contents[0].size());
    }

    // Uncomment this when Constructors for Room and Hall are ready
    // for (int i = 0; i < m_cells.size(); i++) {
    //     for (int j = 0; j < m_cells[i].size(); j++) {
    //         if (m_contents[i][j] == 0) {
    //             m_cells[i][j] = nullptr;
    //         } else if (m_contents[i][j] == 1) {
    //             if (m_contents[i][j - 1] == 1) {
    //                 m_cells[i][j] = m_cells[i][j - 1];
    //             } else if (m_contents[i - 1][j] == 1) {
    //                 m_cells[i][j] = m_cells[i - 1][j];
    //             } else {
    //                 m_cells[i][j] = std::shared_ptr<Room>(new Room());
    //             }
    //         } else if (m_contents[i][j] == 2) {
    //             m_cells[i][j] = std::shared_ptr<Hall>(new Hall());
    //         }
    //     }
    // }
    m_edges = connections;
}

Map::Map()
: Map::Map(time(NULL)) {}
