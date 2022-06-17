//
// Created by Filip on 15.06.2022.
//

#include "GameParams.h"


GameParams::GameParams(GameParams::Difficulty difficulty) : difficulty(difficulty) {

}

 int GameParams::getNumberOfEnemiesPerRound() {

    return NUMBER_OF_ENEMIES_PER_ROUND + difficulty;
}
 int GameParams::getNumberOfEnemyCreatures() {
    return NUMBER_OF_ENEMY_CREATURES + difficulty;
}
