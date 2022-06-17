//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_SPECIALATTACK_H
#define POKEMONGAME_SPECIALATTACK_H

#include <string>
class SpecialAttack {
    std::string name;
    double damage;

public:
    SpecialAttack(const std::string &name, double damage);

    const std::string &getName() const;

    void setName(const std::string &name);

    double getDamage() const;

    void setDamage(double damage);
};


#endif //POKEMONGAME_SPECIALATTACK_H
