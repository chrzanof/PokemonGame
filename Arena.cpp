//
// Created by Filip on 15.06.2022.
//

#include "Arena.h"
int Arena::round = 0;

Arena::Arena(const Player &player, const Enemy &enemy) : player(player), enemy(enemy) ,playerTurnCounter(0), enemyTurnCounter(0){round++;}


Player & Arena::getPlayer()  {
    return player;
}

void Arena::setPlayer(const Player &player) {
    Arena::player = player;
}

 Enemy &Arena::getEnemy() {
    return enemy;
}

void Arena::setEnemy(const Enemy &enemy) {
    Arena::enemy = enemy;
}

int Arena::getPlayerTurnCounter() const {
    return playerTurnCounter;
}

void Arena::setPlayerTurnCounter(int playerTurnCounter) {
    Arena::playerTurnCounter = playerTurnCounter;
}

int Arena::getEnemyTurnCounter() const {
    return enemyTurnCounter;
}

void Arena::setEnemyTurnCounter(int enemyTurnCounter) {
    Arena::enemyTurnCounter = enemyTurnCounter;
}

std::ostream &operator<<(std::ostream &os, const Arena &arena) {
     os<<std::endl << "                round " << Arena::round
     << std::endl << std::endl
    <<"                "<<arena.enemy.getName() << std::endl;
     int counter = 0;
    for (auto & creature : arena.enemy.getCreatures()) {
        if(!creature.isDead()) {
            os << counter << "." << creature;
            if(!arena.enemy.isCreaturePresent(const_cast<Creature &>(creature), arena.enemy.getAvailableCreatures()))
                os << " " << "not available" << std::endl;
        }

        counter ++;
    }
    os << std::endl;
    os << "vs";
    os << std::endl<< std::endl;
    counter = 0;
    for (auto & creature : arena.player.getCreatures()) {
        if(!creature.isDead()) {
            os << counter << "." << creature;
            if(!arena.player.isCreaturePresent(const_cast<Creature &>(creature), arena.player.getAvailableCreatures()))
                os << " " << "not available" << std::endl;
        }

        counter ++;
    }

    os <<"                  "<< arena.player.getName()<< std::endl;

    return os;
}

bool Arena::checkIfLost(const Player &player) {
    for (auto &creature: player.getCreatures()) {
        if(creature.getHp() > 0)
            return false;
    }
    return true;
}

Arena::Arena() : playerTurnCounter(0), enemyTurnCounter(0) {round++;}


