#ifndef CPPDUNGEON_SIZEDSKILL_H
#define CPPDUNGEON_SIZEDSKILL_H
#include "Skill.h"

class SizedSkill: public skillDesigns::Skill {
public: 
    SizedSkill(int size);
protected:
    int m_size;

};

#endif //CPPDUNGEON_SIZEDSKILL_H