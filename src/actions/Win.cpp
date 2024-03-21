//
// Created by Амир Кашапов on 20.03.2024.
//

#include "actions/Win.h"

namespace actions {
    void Win::act(Player *) {
        exit(0);
    }

    std::string Win::getName() {
        return "Congratulations. You won";
    }
} // actions