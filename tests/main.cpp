#include "Map.h"
#include <iostream>
#include <stdio.h>
struct Coord{
    Position pos;
    char symbol1, symbol2;
};
// void draw(Map map, std::vector<Coord> coords){
//     auto drawing = map.draw();
//     for (int i = 0; i< drawing.size();i++) {
//         for (int j = 0; j< drawing[i].size();j++) {
//             auto cooord = std::find_if(coords.begin(), coords.end(),
//                                        [i, j](Coord a){return a.pos.getLine()== i && a.pos.getColumn() == j;});
//             if(cooord!=coords.end()){
//                 printf("%c%c", cooord->symbol1, cooord->symbol2);
//             }
//             else if  (drawing[i][j] == 0) {
//                 std::cout << "  ";
//             }
//             else if (drawing[i][j] == 1) {
//                 printf("\x1B[2;33;45m  \x1B[0;0;0m");
//             }
//             else {
//                 printf("\x1B[1;33;42m  \x1B[0;0;0m");
//             }
//         }
//         std::cout << std::endl;
//     }
// }
void printNextRooms(Map map, Coord coord){
    auto positions = map.getNextRooms(coord.pos);
    std::vector<Coord> coords;
    for(int i = 0;i<positions.size();i++){
        coords.push_back(Coord{positions[i], static_cast<char>('0'+i), static_cast<char>('0'+i)});
    }
    for (int i = 0; i < coords.size(); i++) {
        std::cout << i + 1 << ": (" << (int)coords[i].pos.getLine() << ", " << (int)coords[i].pos.getColumn() << ")" << std::endl;
    }
}

int main() {
    Map test = Map(12);
    Position startPosition = test.getStartPosition();
    Position currentPosition = startPosition;
    Coord currentCoord = {currentPosition, '@', '@'};
    auto drawing = test.draw(startPosition, 40, 40);
    for (int i = 0; i < drawing.size(); i++) {
        for (int j = 0; j < drawing[i].size(); j++) {
            if  (drawing[i][j] == 0) {
                std::cout << "  ";
            }
            else if (drawing[i][j] == 1) {
                printf("\x1B[2;33;45m  \x1B[0;0;0m");
            }
            else {
                printf("\x1B[1;33;42m  \x1B[0;0;0m");
            }
        }
        std::cout << std::endl;
    }
    printNextRooms(test, currentCoord);
    while(1){
        char action;
        std::cin>>action;
        switch (action) {
            case 'p':
                printNextRooms(test, currentCoord);
                break;
            case 'd':
                currentCoord.pos = test.moveRight(currentCoord.pos);
                std::cout << (int)currentCoord.pos.getLine() << ", " << (int)currentCoord.pos.getColumn() << std::endl;
                break;
            case 'a':
                currentCoord.pos = test.moveLeft(currentCoord.pos);
                std::cout << (int)currentCoord.pos.getLine() << ", " << (int)currentCoord.pos.getColumn() << std::endl;
                break;
            default:
                currentCoord.pos = test.chooseNextRoom(currentCoord.pos, test.getNextRooms(currentCoord.pos)[action - '0' - 1]);
        }
    }
    return 0;
}