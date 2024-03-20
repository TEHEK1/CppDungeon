//
// Created by Амир Кашапов on 20.03.2024.
//

#include "actions/Lose.h"

namespace actions {
    void Lose::act(Player *) {
        exit(0);
    }

    std::string Lose::getName() {
        return "You Lost";
    }
} // actions