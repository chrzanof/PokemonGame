//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_ENEMY_H
#define POKEMONGAME_ENEMY_H
#include "Player.h"
#include "GameParams.h"
#include <vector>
#include <ctime>
class Enemy : public Player{
    static const int maxCreatures = 4;
public:
    Enemy();

    Enemy(const std::string &name);

    void setRandomCreatures(std::vector<Creature> &creatures, GameParams &gameParams);

    double attack(int playerCreatureNumber,const Creature &creature);

};


#endif //POKEMONGAME_ENEMY_H
