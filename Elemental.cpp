//
// Created by Filip on 14.06.2022.
//

#include "Elemental.h"

Elemental::Elemental(const std::string &name, SpecialAttack specialAttack) : name(name), specialAttack(specialAttack) {}

const std::string &Elemental::getName() const {
    return name;
}

void Elemental::setName(const std::string &name) {
    Elemental::name = name;
}

const std::vector<Elemental> &Elemental::getWeaknesses() const {
    return weaknesses;
}

void Elemental::setWeaknesses(const std::vector<Elemental> &weaknesses) {
    Elemental::weaknesses = weaknesses;
}

const std::vector<Elemental> &Elemental::getStrengths() const {
    return strengths;
}

void Elemental::setStrengths(const std::vector<Elemental> &strengths) {
    Elemental::strengths = strengths;
}


void Elemental::addWeakness(Elemental elemental) {
    weaknesses.push_back(elemental);
}

void Elemental::addStrength(Elemental elemental) {
    strengths.push_back(elemental);
}

double Elemental::returnModifier(const Elemental &elemental) {

    for (auto & weakness : weaknesses) {
        if(elemental.getName() == weakness.getName()) {
            return WEAKNESS_MODIFIER;
        }
    }
    for (auto & strength : strengths) {
        if(elemental.getName() == strength.getName()) {
            return STRENGTH_MODIFIER;
        }
    }
    return 1;
}

const SpecialAttack &Elemental::getSpecialAttack() const {
    return specialAttack;
}

void Elemental::setSpecialAttack(const SpecialAttack &specialAttack) {
    Elemental::specialAttack = specialAttack;
}


