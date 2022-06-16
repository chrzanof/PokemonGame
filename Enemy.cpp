//
// Created by Filip on 15.06.2022.
//

#include "Enemy.h"

void Enemy::setRandomCreatures(std::vector<Creature> &creatures) {
    srand(time(NULL));

    for (int i = 0; i < maxCreatures; ++i) {
        int index = rand() % creatures.size();
        if(isCreaturePresent(creatures.at(index),creatures))
            this->aliveCreatures.push_back(creatures.at(index));
        else
            i--;
    }


}

Enemy::Enemy(const std::string &name) : Player(name) {}

double Enemy::attack(int playerCreatureNumber, const Creature &creature) {
    return availableCreatures.at(playerCreatureNumber).attack(creature);
}

