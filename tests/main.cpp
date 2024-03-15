#include "Map.h"
#include <iostream>
#include <stdio.h>

int main() {
    Map test = Map(123456789);
    Position startPosition = test.getStartPosition();
    auto drawing = test.draw(test.getStartPosition(), 40, 40);
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
    std::cout << "Neighbours coords:" << std::endl;
    for (int i = 0; i < nextRooms.size(); i++) {
            std::cout << i + 1 << ": " <<(int)(nextRooms[i]).getLine() << ", " << (int)(nextRooms[i]).getColumn() << std::endl;
    }
    startPosition = test.chooseNextRoom(startPosition, nextRooms[0]);
    std::cout << "Next room has coords: " <<(int)nextRooms[0].getLine() << ", " << (int)nextRooms[0].getColumn() << std::endl;

    for (int i = 0; i < 15; i++) {
        startPosition = test.moveRight(startPosition);
        std::cout << "Moved towards next room: "<< (int)startPosition.getLine() << ", " << (int)startPosition.getColumn() << std::endl;
    }

    for (int i = 0; i < 12; i++) {
        startPosition = test.moveLeft(startPosition);
        std::cout << "Moved backwards: "<< (int)startPosition.getLine() << ", " << (int)startPosition.getColumn() << std::endl;
    }
    return 0;
}