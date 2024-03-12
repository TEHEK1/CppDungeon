#include "Map.h"
#include <iostream>
#include <stdio.h>

int main() {
    Map test = Map();
    auto drawing = test.draw();
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
    return 0;
}