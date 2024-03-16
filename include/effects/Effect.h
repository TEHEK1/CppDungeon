#ifndef UNTITLED_EFFECT_H
#define UNTITLED_EFFECT_H

namespace changers{
    class EntityChanger;
} // namespace changers

namespace effects{
    class Effect {
        void turn();
        void endBattleTurn();
        friend changers::EntityChanger;
    };
} // namespace effects
#endif