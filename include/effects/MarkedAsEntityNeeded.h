//
// Created by Амир Кашапов on 15.03.2024.
//

#ifndef TEST_MARKEDASENTITYNEEDED_H
#define TEST_MARKEDASENTITYNEEDED_H
#include "functional"
#include "namespaces/entity.h"
namespace effects{
    class MarkedAsEntityNeeded{
    protected:
        friend changers::EffectChanger;
        virtual std::function<int(const std::shared_ptr<entity::Entity>& )> getTurnFunctionEntity() = 0;
    public:
        virtual ~MarkedAsEntityNeeded() = default;
    };
} // namespace effects
#endif //TEST_MARKEDASENTITYNEEDED_H
