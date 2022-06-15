//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_ARENA_H
#define POKEMONGAME_ARENA_H
#include "Player.h"
#include "Enemy.h"
class Arena {
    Player player;
    Enemy enemy;
    int playerTurnCounter;
    int enemyTurnCounter;
public:
    static int round;

    Arena(const Player &player, const Enemy &enemy);

    const Player &getPlayer() const;

    void setPlayer(const Player &player);

    const Enemy &getEnemy() const;

    void setEnemy(const Enemy &enemy);

    int getPlayerTurnCounter() const;

    void setPlayerTurnCounter(int playerTurnCounter);

    int getEnemyTurnCounter() const;

    void setEnemyTurnCounter(int enemyTurnCounter);


};


#endif //POKEMONGAME_ARENA_H
