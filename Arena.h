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

    Arena();

    Arena(const Player &player, const Enemy &enemy);



    Player &getPlayer();

    void setPlayer(const Player &player);

    Enemy &getEnemy();

    void setEnemy(const Enemy &enemy);

    int getPlayerTurnCounter() const;

    void setPlayerTurnCounter(int playerTurnCounter);

    int getEnemyTurnCounter() const;

    void setEnemyTurnCounter(int enemyTurnCounter);
/**
 * returns all information about arena - enemy and his creatures on top, player and his creatures at bottom
 * also round number. toString() equivalent.
 * @param os
 * @param arena
 * @return os
 */
    friend std::ostream& operator <<(std::ostream &os, const Arena &arena);



};


#endif //POKEMONGAME_ARENA_H
