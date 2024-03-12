#include "Map.h"
#include <iostream>

int main() {
    Map test = Map(123456789);
    auto drawing = test.draw();
    for (auto i : drawing) {
        for (auto j : i) {
            std::cout << (int)j << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}