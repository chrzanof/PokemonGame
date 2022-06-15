//
// Created by Filip on 15.06.2022.
//

#include "Player.h"

Player::Player(const std::string &name) : name(name) {}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

const std::vector<Creature> &Player::getCreatures() const {
    return creatures;
}

void Player::setCreatures(const std::vector<Creature> creatures) {
    if(creatures.size() <= maxCreatures)
        Player::creatures = creatures;
    else
        std::cout << "To many creatures!" << std::endl;
}

void Player::addCreature(Creature creature) {
    if(creatures.size() < maxCreatures)
        creatures.push_back(creature);
    else
        std::cout << "To many creatures!" << std::endl;

}

double Player::attack(int playerCreatureNumber,const Creature &creature) {
    return creatures.at(playerCreatureNumber).attack(creature);
}

bool Player::isCreaturePresent(Creature &creature) {
    for (int i = 0; i < creatures.size(); ++i) {
        if(creature.getName() == creatures.at(i).getName()){
            return true;
        }
    }
    return false;
}
