//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_GAME_H
#define POKEMONGAME_GAME_H
#include "Arena.h";


class Game {
public:
    void playerTurn(Arena &arena, int &creatureSubstitutions, const std::vector<Creature> &gameCreatures);
    void enemyTurn(Arena &arena);
    void changeDeadCreature(Arena &arena, int &count,int &creatureSubstitutions, const std::vector<Creature> &gameCreatures);
    void levelUpCreatures(Arena &arena);
    GameParams chooseDifficulty();
    void chooseCreaturesForPlayer(Player &player, const std::vector<Creature> &gameCreatures);
    std::vector<Creature> creatures();
};


#endif //POKEMONGAME_GAME_H
