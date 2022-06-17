#include <iostream>
#include "Creature.h"
#include "Elemental.h"
#include "Player.h"
#include "Enemy.h"
#include "Arena.h"
#include "GameParams.h"
#include "Game.h"
#include <vector>
int main() {

    Game game = Game();
    std::vector<Creature> creaturesLevel1 = game.creatures();
    bool gameOver = false;
    // wybór poziomu trudności

    GameParams gameParams = game.chooseDifficulty();

    //wybór stworzen przez gracza
    Player player = Player("player");
    game.chooseCreaturesForPlayer(player, creaturesLevel1);

    //główna pętla gry
    int roundCounter = 0;
    //pętla rund
    while (Arena::round < GameParams::NUMBER_OF_ROUNDS) {
        int creatureSubstitutions = 0;
        roundCounter++;
        for (auto &creature : player.getDeadCreatures()) {
            player.addCreature(creature);
        }
        const_cast<std::vector<Creature>&>(player.getDeadCreatures()).clear();
        player.resetCreaturesHP();
        Arena arena = Arena();
        arena.setPlayer(player);
        int enemyCounter = 0;
        //petla przeciwników
        while (enemyCounter < gameParams.getNumberOfEnemiesPerRound() && !arena.getPlayer().getCreatures().empty()) {
            enemyCounter++;
            arena.setEnemy(Enemy("enemy" + std::to_string(enemyCounter)));
            arena.getEnemy().setRandomCreatures(creaturesLevel1, gameParams);

            // tury gracz - przeciwnik
            while (!arena.getEnemy().getCreatures().empty() && !arena.getPlayer().getCreatures().empty()) {
                arena.getPlayer().setAvailableCreatures(arena.getPlayer().getCreatures());
                arena.getEnemy().setAvailableCreatures(arena.getEnemy().getCreatures());
                game.playerTurn(arena, creatureSubstitutions, creaturesLevel1);
                game.enemyTurn(arena);
            }

            if(arena.getPlayer().getCreatures().empty()){
                std::cout<< std::endl << "Game Over! You've lost!" << std::endl;
                gameOver = true;
                break;
            } else {
                std::cout<<"You won against " << arena.getEnemy().getName() << std::endl;
                // ewolucja stworzenia
                game.levelUpCreatures(arena);
                player = arena.getPlayer();
                // możliwy zapis gry
            }
            if(gameOver) {
                break;
            }
        }
        if(gameOver){
            break;
        }
    }
    if(!gameOver)
        std::cout << "Congratulations, you finished the game!"<< std::endl;
    return 0;
}
