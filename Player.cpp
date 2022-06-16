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

const std::vector<Creature> & Player::getCreatures() const  {
    return aliveCreatures;
}

void Player::setCreatures(const std::vector<Creature> creatures) {
    if(creatures.size() <= maxCreatures){
        Player::aliveCreatures = creatures;
        Player::availableCreatures = creatures;
    }
    else
        std::cout << "To many aliveCreatures!" << std::endl;
}

void Player::addCreature(Creature creature) {
    if(aliveCreatures.size() < maxCreatures)
        aliveCreatures.push_back(creature);
    else
        std::cout << "To many aliveCreatures!" << std::endl;

}

double Player::attack(int playerCreatureNumber,const Creature &creature) {
    return aliveCreatures.at(playerCreatureNumber).attack(creature);
}

bool Player::isCreaturePresent(Creature &creature,const std::vector<Creature> &creatures) const {
    for (int i = 0; i < creatures.size(); ++i) {
        if(creature.getName() == creatures.at(i).getName()){
            return true;
        }
    }
    return false;
}

const int Player::getMaxCreatures() {
    return maxCreatures;
}

void Player::updateDeadCreatures() {
    int count = 0;
    for (auto &creature: getCreatures()) {
        if(creature.getHp() <= 0) {
            deadCreatures.push_back(creature);
            ifFoundDeleteCreature(creature,availableCreatures);
            aliveCreatures.erase(aliveCreatures.begin() + count);
        }
        count++;
    }
}

const std::vector<Creature> &Player::getDeadCreatures() const {
    return deadCreatures;
}

void Player::setDeadCreatures(const std::vector<Creature> &deadCreatures) {
    Player::deadCreatures = deadCreatures;
}

 const std::vector<Creature> &Player::getAvailableCreatures() const {
    return availableCreatures;
}

void Player::setAvailableCreatures(const std::vector<Creature> &availableCreatures) {
    Player::availableCreatures = availableCreatures;
}


bool Player::ifFoundDeleteCreature(const Creature &creature, std::vector<Creature> &creatures) {
    int count = 0;
    for(auto &c : creatures) {
        if(c.getName() == creature.getName()) {
            creatures.erase(creatures.begin() + count);
        }
        count++;
    }
}

void Player::deleteCreature(int index, std::vector<Creature> &creatures) {
    creatures.erase(creatures.begin() + index);
}




