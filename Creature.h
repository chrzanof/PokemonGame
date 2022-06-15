//
// Created by Filip on 14.06.2022.
//

#ifndef POKEMONGAME_CREATURE_H
#define POKEMONGAME_CREATURE_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Elemental.h"
//#include "Creature.h"
class Creature {
    std::string name;
    int strength;
    double dexterity;
    double HP;
    double EXP;
    Elemental elemental;
    Creature* nextForm;
    int level;

public:
    Creature(const std::string &name, int strength, double dexterity, double hp,
             const Elemental &elemental,int level);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getStrength() const;

    void setStrength(int strength);

    double getDexterity() const;

    void setDexterity(double dexterity);

    double getHp() const;

    void setHp(double hp);

    double getExp() const;

    void setExp(double exp);

    const Elemental &getElemental() const;

    void setElemental(const Elemental &elemental);

    Creature *getNextForm() const;

    void setNextForm(Creature *nextForm);

    int getLevel() const;

    void setLevel(int level);

    double attack(const Creature &creature);

    bool tryToEvadeAndTakeDamageIfFailed(double damage);


};


#endif //POKEMONGAME_CREATURE_H