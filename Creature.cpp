//
// Created by Filip on 14.06.2022.
//

#include "Creature.h"



const std::string &Creature::getName() const {
    return name;
}

void Creature::setName(const std::string &name) {
    Creature::name = name;
}

int Creature::getStrength() const {
    return strength;
}

void Creature::setStrength(int strength) {
    Creature::strength = strength;
}

double Creature::getDexterity() const {
    return dexterity;
}

void Creature::setDexterity(double dexterity) {
    Creature::dexterity = dexterity;
}

double Creature::getHp() const {
    return HP;
}

void Creature::setHp(double hp) {
    HP = hp;
}

double Creature::getExp() const {
    return EXP;
}

void Creature::setExp(double exp) {
    EXP = exp;
}

Creature::Creature(const std::string &name, int strength, double dexterity, double hp,
                   const Elemental &elemental) : name(name), strength(strength), dexterity(dexterity), HP(hp), EXP(0),
                                                 elemental(elemental) {}

const Elemental &Creature::getElemental() const {
    return elemental;
}

void Creature::setElemental(const Elemental &elemental) {
    Creature::elemental = elemental;
}


