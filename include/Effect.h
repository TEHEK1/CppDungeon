#ifndef UNTITLED_EFFECT_H
#define UNTITLED_EFFECT_H

namespace effects{
    class Effect {
        void turn();
        void endBattleTurn();
        friend class EntityChanger;
    };
} // namespace effects
#endif