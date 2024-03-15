#include "Map.h"
#include <iostream>
#include <stdio.h>

int main() {
    Map test = Map();
    Position startPosition = test.getStartPosition();
    Position currentPosition = startPosition;
    auto drawing = test.draw(currentPosition, 40, 40);
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
    std::vector<Position> nextRooms = test.getNextRooms(currentPosition);
    std::cout << "Starting from " << (int)currentPosition.getLine() << ", " << (int)currentPosition.getColumn() << std::endl;
    std::cout << "Neighbours coords:" << std::endl;
    for (int i = 0; i < nextRooms.size(); i++) {
            std::cout << i + 1 << ": " <<(int)(nextRooms[i]).getLine() << ", " << (int)(nextRooms[i]).getColumn() << std::endl;
    }
    currentPosition = test.chooseNextRoom(currentPosition, nextRooms[1]);
    std::cout << "Next room has coords: " <<(int)nextRooms[1].getLine() << ", " << (int)nextRooms[1].getColumn() << std::endl;

    int debugCounter = 2;
    while (debugCounter > 0) {
        currentPosition = test.moveRight(currentPosition);
        std::cout << "Moved towards next room: "<< (int)currentPosition.getLine() << ", " << (int)currentPosition.getColumn() << std::endl;
        if (currentPosition.getLine() == nextRooms[1].getLine() && currentPosition.getColumn() == nextRooms[1].getColumn()) {
            debugCounter--;
        }
    }

    debugCounter = 2;
    while (debugCounter > 0) {
        currentPosition = test.moveLeft(currentPosition);
        std::cout << "Moved backwards: "<< (int)currentPosition.getLine() << ", " << (int)currentPosition.getColumn() << std::endl;
        if (currentPosition.getLine() == startPosition.getLine() && currentPosition.getColumn() == startPosition.getColumn()) {
            debugCounter--;
        }
    }
    return 0;
}