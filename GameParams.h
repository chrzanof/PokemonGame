//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_GAMEPARAMS_H
#define POKEMONGAME_GAMEPARAMS_H


class GameParams {
private:
    static constexpr int NUMBER_OF_ENEMIES_PER_ROUND = 4;
    static constexpr int NUMBER_OF_ENEMY_CREATURES = 4;
public:
    static constexpr int MAX_PLAYER_CREATURES = 6;
    static constexpr int NUMBER_OF_ROUNDS = 4;
    static constexpr int MAX_NUMBER_OF_SUBSTITUTIONS = 6;
    static constexpr int EXP_PER_KILL = 100;
    enum Difficulty {
        easy = 0,
        normal = 1,
        hard = 2
    };
    Difficulty difficulty;

    GameParams();

    GameParams(Difficulty difficulty);

     int getNumberOfEnemiesPerRound();

     int getNumberOfEnemyCreatures();

};


#endif //POKEMONGAME_GAMEPARAMS_H
