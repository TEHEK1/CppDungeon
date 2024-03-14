#include "Map.h"
#include <iostream>
void drawMap(Map map, Position pos) {
    auto drawing = map.draw();
    for (int i =0; i<drawing.size();i++) {
        for (int j = 0;j<drawing[i].size(); j++) {
            if(i==pos.getLine() && j == pos.getColumn()){
                std::cout<< "%";
            }
            else if (drawing[i][j] == 0) {
                std::cout << " ";
            }
            else if(drawing[i][j] == 1){
                std::cout <<"@";
            }
            else {
                std::cout <<"#";
            }
        }
        std::cout << "\n";
    }
}
int main() {
    Map test = Map(138);
    Position position = test.getStartPosition();
    drawMap(test, position);
    position = test.chooseNextRoom(position, 1);
    for(int i = 0;i<20;i++){
        drawMap(test, position);
        position = test.moveRight(position);
    }
    for(int i = 0;i<0;i++){
        drawMap(test, position);
        position = test.moveLeft(position);
    }
    return 0;
}