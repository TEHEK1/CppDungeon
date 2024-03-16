//
// Created by artem on 16.03.2024.
//

#ifndef CPPDUNGEON_CREATIR_H
#define CPPDUNGEON_CREATIR_H
#include "abstractEventCreator.h"
template <class C, class Base>
//
class Creator: public AbstractCreator<Base>
{
public:
    Creator() { }
    virtual ~Creator()	{}
    Base * create() const { return new C(); }
};
#endif //CPPDUNGEON_CREATIR_H
