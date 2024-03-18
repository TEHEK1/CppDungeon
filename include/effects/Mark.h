//
// Created by Амир Кашапов on 18.03.2024.
//

#ifndef UGABUGA_MARKED_H
#define UGABUGA_MARKED_H
#include <memory>
#include "Debuff.h"
namespace effects {
    class Mark: public Debuff{
    public:
        Mark(int numberOfTurns);
        int resistanceHash() override;
    };
}
#endif //UGABUGA_MARKED_H
