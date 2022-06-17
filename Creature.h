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
class Creature {
    std::string name;
    int strength;
    double dexterity;
    double HP;
    double maxHP;
    double EXP;
    Elemental elemental;
    int level;
    bool dead;

public:
    Creature(const std::string &name, int strength, double dexterity, double hp,
             const Elemental &elemental,int level);

    Creature(const std::string &name, int strength, double dexterity, double hp, double maxHp, double exp,
             const Elemental &elemental, int level, bool dead);

    const std::string &getName() const;

    void setName(const std::string &name);



    int getStrength() const;

    void setStrength(int strength);

    double getDexterity() const;

    void setDexterity(double dexterity);

    double getHp() const;

    void setHp(double hp);

    double getMaxHp() const;

    void setMaxHp(double maxHp);

    double getExp() const;

    void setExp(double exp);

    const Elemental &getElemental() const;

    void setElemental(const Elemental &elemental);

    int getLevel() const;

    void setLevel(int level);

    bool isDead() const;

    void setDead(bool isDead);

    double attack(const Creature &creature);

    bool tryToEvadeAndTakeDamageIfFailed(double damage);

    friend std::ostream& operator <<(std::ostream &os, const Creature &creature);

    void levelUp(int attribute);


};


#endif //POKEMONGAME_CREATURE_H
