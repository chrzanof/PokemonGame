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

    static const int getMaxCreatures();

    bool isCreaturePresent(Creature &creature, const std::vector<Creature> &creatures) const;

    bool updateDeadCreatures();

    bool ifFoundDeleteCreature(const Creature &creature, std::vector<Creature>&creatures);

    void deleteCreature(int index, std::vector<Creature>&creatures);

    void resetCreaturesHP();

    std::vector<std::string> returnCreaturesInfoAsString(std::vector<Creature> &creatures);




};


#endif //POKEMONGAME_PLAYER_H
