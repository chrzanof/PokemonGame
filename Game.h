//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_GAME_H
#define POKEMONGAME_GAME_H
#include "Arena.h";


class Game {
    std::vector<Creature> gameCreatures;
    std::vector<Elemental> elementals;
public:
    Game();

    void setGameCreatures(const std::vector<Creature> &gameCreatures);
    const std::vector<Elemental> &getElementals() const;
    void setElementals(const std::vector<Elemental> &elementals);
    std::vector<Creature> creatures();
/**
 * player' turn algorithm,player can attack enemy creature , use special attack when HP of enemy creature
 * is less than 1/3 maxHP, change dead creature
 *updates arena and number of creature substitutions
 *
 * @param arena
 * @param creatureSubstitutions
 * @param gameCreatures
 */
    void playerTurn(Arena &arena, int &creatureSubstitutions, const std::vector<Creature> &gameCreatures);
    /**
     * enemy chooses his random creature to attack random player's creature
     * updates arena
     * @param arena
     */
    void enemyTurn(Arena &arena);
    /**
     * asks if player wants to change dead creature
     * if user's input == y or Y replace dead creature with creature chosen by player
     * updates arena and creatureSubstitution
     * @param arena
     * @param count
     * @param creatureSubstitutions
     * @param gameCreatures
     */
    void changeDeadCreature(Arena &arena, int &count,int &creatureSubstitutions, const std::vector<Creature> &gameCreatures);
    /**
     * asks player to choose two creature's attribute and calls Creature::levelUp function for those attributes
     * @param arena
     */
    void levelUpCreatures(Arena &arena);
    /**
     * ask player to choose difficulty level and sets it accordingly
     * @return GameParams object
     */
    GameParams chooseDifficulty();
    /**
     * asks player for input and add creature to player
     * repeats Game::Params::MAX_PLAYER_CREATURES times
     * @param player
     * @param gameCreatures
     */
    void chooseCreaturesForPlayer(Player &player, const std::vector<Creature> &gameCreatures);

    Elemental findElementalByName(std::string name);
    /**
     * updates player and game params and enemyCounter from 4 vectors of strings
     * player.name, arena.round, enemyCounter, params.difficulty from gameProgress vector
     * player.aliveCreatures from aliveCreatures vector
     * player.deadCreatures from deadCreatures vector
     * player.availableCreatures form availableCreatures vector
     * @param player
     * @param params
     * @param enemyCounter
     * @param gameProgress
     * @param aliveCreatures
     * @param deadCreatures
     * @param availableCreatures
     */
    void loadGame(Player &player, GameParams &params,int &enemyCounter, const std::vector<std::string> gameProgress,
                  const std::vector<std::string> aliveCreatures, const std::vector<std::string> deadCreatures,
                  const std::vector<std::string> availableCreatures);
};


#endif //POKEMONGAME_GAME_H
