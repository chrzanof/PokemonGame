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
    /**
     * sets random creatures
     * number of creatures are determined im gameParams object
     * @param creatures
     * @param gameParams
     */
    void setRandomCreatures(std::vector<Creature> &creatures, GameParams &gameParams);

    double attack(int playerCreatureNumber,const Creature &creature);

};


#endif //POKEMONGAME_ENEMY_H
