//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASRESISTABLE_H
#define TEST_MARKEDASRESISTABLE_H
#include "entity/Resistances.h"
namespace effects {
    class MarkedAsResistable {
    public:
        virtual int resistanceHash() = 0;
        virtual ~MarkedAsResistable() = default;
    };
} // namespace effects
#endif //TEST_MARKEDASRESISTABLE_H
