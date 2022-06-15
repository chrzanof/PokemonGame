//
// Created by Filip on 15.06.2022.
//

#include "Arena.h"
int Arena::round = 0;

Arena::Arena(const Player &player, const Enemy &enemy) : player(player), enemy(enemy) ,playerTurnCounter(0), enemyTurnCounter(0){round++;}

const Player &Arena::getPlayer() const {
    return player;
}

void Arena::setPlayer(const Player &player) {
    Arena::player = player;
}

const Enemy &Arena::getEnemy() const {
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
