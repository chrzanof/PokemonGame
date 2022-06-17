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
                   const Elemental &elemental, int level) : name(name), strength(strength), dexterity(dexterity), HP(hp), EXP(0),
                                                 elemental(elemental), level(level), maxHP(hp) {dead = false;}

const Elemental &Creature::getElemental() const {
    return elemental;
}

void Creature::setElemental(const Elemental &elemental) {
    Creature::elemental = elemental;
}

int Creature::getLevel() const {
    return level;
}

void Creature::setLevel(int level) {
    Creature::level = level;
}

/**
 * return modified strength value and writes whether attack was strong or weak against enemy;
 * @param creature
 * @return damage amount dealt to the creature modified by value returned by Elemental::returnModifier function
 */
double Creature::attack(const Creature &creature) {
    std::cout<<name << " attacks "<<creature.name<<std::endl;
    double modifier = this->elemental.returnModifier(creature.elemental);
    if(modifier > 1) std::cout << this->name << " is strong against " << creature.name << std::endl;
    else if( modifier < 1) std::cout << this->name << " is weak against " << creature.name << std::endl;
    return strength * modifier;
}

bool Creature::tryToEvadeAndTakeDamageIfFailed(double damage) {
    srand(time(NULL));
    if(std::rand() % 100 + 1 > dexterity) {
        HP = HP - damage;
        if(HP <= 0) {
            setDead(true);
            std::cout << name << " died" << std::endl;
        }
        return false;
    }
    std::cout<< this->name << " evaded the attack!" << std::endl;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Creature &creature) {
    return os << creature.name  << " HP: " << std::to_string(creature.HP)
                                << " S: " << std::to_string(creature.strength)
                                << " D: " << std::to_string(creature.dexterity)
                                << " E: " << creature.elemental.getName()
                                << std::endl;
}

bool Creature::isDead() const {
    return dead;
}

void Creature::setDead(bool isDead) {
    Creature::dead = isDead;
}

double Creature::getMaxHp() const {
    return maxHP;
}

void Creature::setMaxHp(double maxHp) {
    maxHP = maxHp;
}

void Creature::levelUp(int attribute) {
    if(attribute == 1) {
        setMaxHp(getMaxHp() + 10);
        setHp(getMaxHp());
    } else if (attribute == 2){
        setStrength(getStrength() + 10);
    } else {
        setDexterity(getDexterity() + 10);
    }

}




