#ifndef CPPDUNGEON_EFFECTGENERATOR_H
#define CPPDUNGEON_EFFECTGENERATOR_H

#include <string>
#include <vector>
#include <memory>

class Effect;

class EffectGenerator {
public:
    void generateImmediateCharacteristicEffect(std::string name, std::vector<int> rank, std::vector<int> target, int accuracy, int critChance, int dmg);
    void generateNumberOfTurnsEffect(std::string name, std::vector<int> rank, std::vector<int> target, int accuracy, int critChance, int dmg, std::shared_ptr<Effect> effect, int duration);
    void generateUncritedEffect(std::string name, std::vector<int> rank, std::vector<int> target, int accuracy, int critChance);
};

#endif //CPPDUNGEON_EFFECTGENERATOR_H