#include <iostream>
#include "Creature.h"
//#include "Elemental.h"
#include "Player.h"
#include "Enemy.h"
#include "Arena.h"
#include "GameParams.h"
#include "Game.h"
#include <vector>
#include <fstream>
#include <string>

void writeToFile(std::string fileName, const std::vector<std::string> &values) {
    std::ofstream fileOut;
    fileOut.open(fileName,std::ios::in);
    if(fileOut.is_open()){
        for (auto & row: values) {
            fileOut << row << "\n";
        }
        fileOut.close();
    }
}
 const std::vector<std::string> readFromFile(std::string fileName)  {
    std::fstream fileIn;
    std::vector<std::string> fileContent;
    fileIn.open(fileName,std::ios::in);
    if(fileIn.is_open()){
        std::string line;
        while (std::getline(fileIn,line)){
            fileContent.push_back(line);
        }
        fileIn.close();
    }
    return fileContent;
}

int main() {

    Game game = Game();
    std::vector<Creature> creaturesLevel1 = game.creatures();
    bool gameOver = false;
    bool exit = false;
    Player player;
    GameParams gameParams;
    std::cout << "1 - New Game"<<std::endl<<"2 - Continue"<<std::endl;
    int option;
    std::cin >> option;
    int enemyCounter;
    if(option == 2) {
        const std::vector<std::string> v1 = readFromFile("saves/playerName_rounds_and_defeated_enemies_save.txt");
        const std::vector<std::string> v2 = readFromFile("saves/alive_creatures_save.txt");
        const std::vector<std::string> v3 = readFromFile("saves/dead_creatures_save.txt");
        const std::vector<std::string> v4 = readFromFile("saves/available_creatures_save.txt");
        game.loadGame(player, gameParams, enemyCounter, v1,v2,v3,v4);
    } else {
        gameParams = game.chooseDifficulty();
        //wybór stworzen przez gracza
        player = Player("player");
        game.chooseCreaturesForPlayer(player, creaturesLevel1);
        enemyCounter = 0;
    }
    // wybór poziomu trudności


    bool firstLoop = true;
    //główna pętla gry
    //pętla rund
    while (Arena::round < GameParams::NUMBER_OF_ROUNDS) {
        int creatureSubstitutions = 0;

        if(!firstLoop) {
            enemyCounter = 0;
            for (auto &creature : player.getDeadCreatures()) {
                player.addCreature(creature);
            }
            const_cast<std::vector<Creature>&>(player.getDeadCreatures()).clear();
            player.resetCreaturesHP();
        }
        Arena arena = Arena();
        arena.setPlayer(player);
        //petla przeciwników
        while (enemyCounter < gameParams.getNumberOfEnemiesPerRound() && !arena.getPlayer().getCreatures().empty()) {
            enemyCounter++;
            firstLoop = false;
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
                std::cout<<"do you want to save progress and exit game?[y/n]"<<std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'y' || answer == 'Y') {
                    writeToFile("saves/playerName_rounds_and_defeated_enemies_save.txt", {arena.getPlayer().getName(),std::to_string(Arena::round),std::to_string(enemyCounter),std::to_string(gameParams.difficulty)});
                    writeToFile("saves/alive_creatures_save.txt",arena.getPlayer().returnCreaturesInfoAsString(
                            const_cast<std::vector<Creature> &>(arena.getPlayer().getCreatures())));
                    writeToFile("saves/dead_creatures_save.txt",arena.getPlayer().returnCreaturesInfoAsString(
                            const_cast<std::vector<Creature> &>(arena.getPlayer().getDeadCreatures())));
                    writeToFile("saves/available_creatures_save.txt", arena.getPlayer().returnCreaturesInfoAsString(
                            const_cast<std::vector<Creature> &>(arena.getPlayer().getAvailableCreatures())));
                    std::cout << "progress saved."<<std::endl;
                    exit = true;
                    break;
                }

            }
            if(gameOver || exit) {
                break;
            }
        }
        if(gameOver || exit){
            break;
        }
    }
    if(!gameOver && !exit)
        std::cout << "Congratulations, you finished the game!"<< std::endl;
    return 0;
}
