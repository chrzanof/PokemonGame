//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_PLAYER_H
#define POKEMONGAME_PLAYER_H
#include <string>
#include <vector>
#include "Creature.h"
class Player {
    static const int maxCreatures = 6;
protected:
    std::string name;
    std::vector<Creature> creatures;

public:

    Player(const std::string &name);

    void addCreature(Creature creature);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Creature> &getCreatures() const;

    void setCreatures(const std::vector<Creature> creatures);

    double attack(int playerCreatureNumber,const Creature &creature);

protected:
    bool isCreaturePresent(Creature &creature);


};


#endif //POKEMONGAME_PLAYER_H
