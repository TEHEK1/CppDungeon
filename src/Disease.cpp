//
// Created by artem on 12.03.2024.
//
#include "Disease.h"
namespace effects {
    Disease::Disease(std::map<size_t, int> modifier) : Debuff(static_cast<std::shared_ptr<Entity>>(nullptr),  1, modifier) {

    }
}