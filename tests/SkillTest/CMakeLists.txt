cmake_minimum_required(VERSION 3.24)
project(SkillTest)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../include)

add_executable(skillTest
        main.cpp
        ../../src/entity/Entity.cpp
        ../../src/effects/ForceMove.cpp
        ../../src/effects/Move.cpp
        ../../src/BattleFieldChanger.cpp
        ../../src/BattleField.cpp
        ../../src/Squad.cpp
        ../../src/SquadChanger.cpp
        ../../src/effects/ImmediateEffect.cpp
        ../../src/effects/PermanentEffect.cpp
        ../../src/changers/EffectChanger.cpp
        ../../src/effects/MarkedAsTurnable.cpp
        ../../src/effects/MarkedAsEndBattle.cpp
        ../../src/enemies/CultistAcolyte/EldritchPush.cpp
        ../../src/skillDesignes/Skill.cpp
        ../../src/skillDesignes/RangeSkill.cpp
        ../../src/generators/NumberGenerator.cpp
        ../../src/effects/Damege.cpp
        ../../src/effects/ImmediateCharacteristicEffect.cpp
        ../../src/changers/EntityChanger.cpp
        ../../src/enemies/CultistAcolyte/StressfulIncantation.cpp
        ../../src/enemies/Webber/Web.cpp
        ../../src/effects/Mark.cpp
        ../../src/effects/Stun.cpp
        ../../src/effects/Debuff.cpp
        ../../src/effects/Buff.cpp
        ../../src/enemies/Webber/Bite.cpp
        ../../src/effects/Blight.cpp
        ../../src/effects/AutoAction.cpp
        ../../src/effects/Bleed.cpp
)
