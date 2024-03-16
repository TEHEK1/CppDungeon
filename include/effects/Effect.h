#ifndef UNTITLED_EFFECT_H
#define UNTITLED_EFFECT_H
#include <map>
namespace changers{
    class EntityChanger;
} // namespace changers

namespace effects{
    class Effect {
    public:
        std::map<int, int> getModifier();
        void turn();
        void endBattleTurn();
        friend changers::EntityChanger;
    };
} // namespace effects
#endif