//
// Created by Амир Кашапов on 16.03.2024.
//

#ifndef UGABUGA_NUMBERGENERATOR_H
#define UGABUGA_NUMBERGENERATOR_H
#include <random>
namespace generators {
    class NumberGenerator {
        static std::mt19937 getGenerator();
    public:
        static int generate();
        static int generate(int minNumber, int maxNumber);
    };
} // namespace generators
#endif //UGABUGA_NUMBERGENERATOR_H
