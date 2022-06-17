//
// Created by Filip on 15.06.2022.
//

#include "SpecialAttack.h"

const std::string &SpecialAttack::getName() const {
    return name;
}

void SpecialAttack::setName(const std::string &name) {
    SpecialAttack::name = name;
}



double SpecialAttack::getDamage() const {
    return damage;
}

void SpecialAttack::setDamage(double damage) {
    SpecialAttack::damage = damage;
}

SpecialAttack::SpecialAttack(const std::string &name, double damage) : name(name), damage(damage) {}
