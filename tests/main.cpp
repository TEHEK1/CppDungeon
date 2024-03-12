#include "Map.h"
#include <iostream>

int main() {
    Map test = Map(1710271398); // 1710271398
    auto drawing = test.draw();
    for (auto i : drawing) {
        for (auto j : i) {
            if  (j == 0) {
                std::cout << "  ";
            } else {
                std::cout << (int)j << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}