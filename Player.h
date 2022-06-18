//
// Created by Filip on 15.06.2022.
//

#ifndef POKEMONGAME_PLAYER_H
#define POKEMONGAME_PLAYER_H
#include <string>
#include <vector>
#include "Creature.h"
class Player {
    static const int maxCreatures = 6;
protected:
    std::string name;
    std::vector<Creature> aliveCreatures;
    std::vector<Creature> deadCreatures;
    std::vector<Creature> availableCreatures;
public:
     const std::vector<Creature> &getAvailableCreatures() const ;

    void setAvailableCreatures(const std::vector<Creature> &availableCreatures);

public:
    Player();

    Player(const std::string &name);

    void addCreature(Creature creature);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Creature> &getCreatures() const ;

    void setCreatures(const std::vector<Creature> creatures);

    const std::vector<Creature> &getDeadCreatures() const;

    void setDeadCreatures(const std::vector<Creature> &deadCreatures);

    double attack(int playerCreatureNumber,const Creature &creature);

    bool isCreaturePresent(Creature &creature, const std::vector<Creature> &creatures) const;
/**
 * moves creatures with HP < 0 from aliveCreatures to deadCreatures
 * @return true if found creature with HP < 0
 */
    bool updateDeadCreatures();
/**
 * check if creature is present in creatures (compares by name) and deletes it if finds it
 * @param creature
 * @param creatures
 * @return true if deleted, false if didn't
 */
    bool ifFoundDeleteCreature(const Creature &creature, std::vector<Creature>&creatures);

    void deleteCreature(int index, std::vector<Creature>&creatures);

    void resetCreaturesHP();
/**
 * converts every creature's field into string and  pushes it into vector of strings. This is used to prepare
 * string vector to write it to file.
 * @param creatures
 * @return strVector
 */
    std::vector<std::string> returnCreaturesInfoAsString(std::vector<Creature> &creatures);




};


#endif //POKEMONGAME_PLAYER_H
