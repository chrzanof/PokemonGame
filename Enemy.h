//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_ENEMY_H
#define POKEMONGAME_ENEMY_H
#include "Player.h"
#include <vector>
#include <ctime>
class Enemy : public Player{
    static const int maxCreatures = 4;
public:
    Enemy(const std::string &name);

    void setRandomCreatures(std::vector<Creature> &creatures);

};


#endif //POKEMONGAME_ENEMY_H