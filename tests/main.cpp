#include "Map.h"
#include <iostream>
#include <stdio.h>

int main() {
    Map test = Map();
    auto drawing = test.draw(test.getStartPosition(), 5, 5);
    for (auto i : drawing) {
        for (auto j : i) {
            if  (j == 0) {
                std::cout << "  ";
            } else {
                if (j == 1) {
                    printf("\x1B[2;33;45m  \x1B[0;0;0m");
                } else {
                    printf("\x1B[1;33;42m  \x1B[0;0;0m");
                }
            }
        }
        std::cout << std::endl;
    }
    std::vector<Position> nextRooms = test.getNextRooms(startPosition);
    std::cout << "Starting from " << (int)startPosition.getLine() << ", " << (int)startPosition.getColumn() << std::endl;
    for (int i = 0; i < nextRooms.size(); i++) {
            std::cout << (int)(nextRooms[i]).getLine() << ", " << (int)(nextRooms[i]).getColumn() << std::endl;
    }
    startPosition = test.chooseNextRoom(startPosition, nextRooms[0]);
    std::cout << (int)startPosition.getDestination() << std::endl;
    startPosition = test.moveRight(startPosition);
    std::cout << (int)startPosition.getLine() << ", " << (int)startPosition.getColumn() << std::endl;
    startPosition = test.moveRight(startPosition);
    std::cout << (int)startPosition.getLine() << ", " << (int)startPosition.getColumn() << std::endl;
    startPosition = test.moveLeft(startPosition);
    std::cout << (int)startPosition.getLine() << ", " << (int)startPosition.getColumn() << std::endl;
    return 0;
}