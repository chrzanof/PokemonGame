//
// Created by Filip on 15.06.2022.
//

#include "Game.h"
#include <ctime>

void Game::playerTurn(Arena &arena, int &creatureSubstitutions, const std::vector<Creature> &gameCreatures) {
    int count = 0;
    //tura gracz
    while(!arena.getPlayer().getAvailableCreatures().empty() && !arena.getEnemy().getCreatures().empty()) {
        try {
            if(creatureSubstitutions < GameParams::MAX_NUMBER_OF_SUBSTITUTIONS && !arena.getPlayer().getDeadCreatures().empty() && count < 1) {
                changeDeadCreature(arena,count,creatureSubstitutions,gameCreatures);
            }

            std::cout << arena;
            std::cout << arena.getPlayer().getName() << "\'s turn" << std::endl;
            arena.setPlayerTurnCounter(arena.getPlayerTurnCounter() + 1);
            int playerCreature = -1, enemyCreature = -1;
            std::cout << "choose your creature:";
            std::cin >> playerCreature;
            while(!arena.getPlayer().isCreaturePresent(
                    const_cast<Creature &>(arena.getPlayer().getCreatures().at(playerCreature)),
                    arena.getPlayer().getAvailableCreatures())) {
                std::cout << arena.getPlayer().getCreatures().at(playerCreature).getName() << " already attacked in this turn"<< std::endl;
                std::cin >> playerCreature;
            }
            std::cout << "choose enemy creature:";
            std::cin >> enemyCreature;
            double creatureHp = arena.getEnemy().getCreatures().at(enemyCreature).getHp();
            double creatureMaxHp = arena.getEnemy().getCreatures().at(enemyCreature).getMaxHp();
            //attack specialny jeśli HP stworznia jest <= 33.3% maxHP
            if(creatureHp <= creatureMaxHp / 3) {
                std::cout << "do you want do end creature with special attack?[y/n]" << std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'y' || answer == 'Y') {
                    double damage = arena.getPlayer().getCreatures().at(playerCreature).getElemental().getSpecialAttack().getDamage();
                    const_cast<Creature &>(arena.getEnemy().getCreatures().at(enemyCreature)).setHp(
                            const_cast<Creature &>(arena.getEnemy().getCreatures().at(enemyCreature)).getHp() - damage);
                    std::cout << arena.getPlayer().getCreatures().at(playerCreature).getName() << " attacked using "
                    << arena.getPlayer().getCreatures().at(playerCreature).getElemental().getSpecialAttack().getName() << std::endl;
                } else {
                    double damage = arena.getPlayer().attack(playerCreature,
                                                             arena.getEnemy().getCreatures().at(enemyCreature));
                    const_cast<Creature &>(arena.getEnemy().getCreatures().at(
                            enemyCreature)).tryToEvadeAndTakeDamageIfFailed(damage);
                }
            } else {
                double damage = arena.getPlayer().attack(playerCreature,
                                                         arena.getEnemy().getCreatures().at(enemyCreature));
                const_cast<Creature &>(arena.getEnemy().getCreatures().at(
                        enemyCreature)).tryToEvadeAndTakeDamageIfFailed(damage);
            }
            arena.getPlayer().ifFoundDeleteCreature(arena.getPlayer().getCreatures().at(playerCreature),
                                                    const_cast<std::vector<Creature> &>(arena.getPlayer().getAvailableCreatures()));
            bool died = arena.getEnemy().updateDeadCreatures();
            if(died) {
                const_cast<Creature&>(arena.getPlayer().getCreatures().at(playerCreature))
                        .setExp(arena.getPlayer().getCreatures().at(playerCreature).getExp() + GameParams::EXP_PER_KILL);
            }

        } catch (std::out_of_range e) {
            std::cout << "wrong input!"<<std::endl;
        }

    }
}

void Game::enemyTurn(Arena &arena) {
    srand(time(NULL));
    while (!arena.getEnemy().getAvailableCreatures().empty() && !arena.getPlayer().getCreatures().empty()){
        std::cout << arena;
        std::cout << arena.getEnemy().getName() << "\'s turn" << std::endl;
        arena.setEnemyTurnCounter(arena.getEnemyTurnCounter() + 1);
        int attackingCreatureNumber = rand() % arena.getEnemy().getAvailableCreatures().size();
        int attackedCreatureNumber = rand() % arena.getPlayer().getCreatures().size();
        int damage = arena.getEnemy().attack(attackingCreatureNumber,arena.getPlayer().getCreatures().at(attackedCreatureNumber));
        const_cast<Creature &>(arena.getPlayer().getCreatures().at(attackedCreatureNumber)).tryToEvadeAndTakeDamageIfFailed(damage);
        std::vector<Creature>&v = const_cast<std::vector<Creature>&>(arena.getEnemy().getAvailableCreatures());
        v.erase(v.begin() + attackingCreatureNumber);
        arena.getPlayer().updateDeadCreatures();
        getchar();
    }


}

void Game::changeDeadCreature(Arena &arena, int &count, int &creatureSubstitutions,
                              const std::vector<Creature> &gameCreatures) {
    std::cout << "do you want change dead creature?[y/n]"<<std::endl;
    count++;
    char answer;
    std::cin >> answer;
    if(answer == 'y' || answer == 'Y') {
        creatureSubstitutions++;
        for(int i = 0; i < gameCreatures.size(); i++) {
            std:: cout<< i << "." << gameCreatures.at(i);
        }
        std::cout<<std::endl;
        int selectedCreature;
        std::cin >> selectedCreature;
        for(int i = 0; i < arena.getPlayer().getDeadCreatures().size(); i++) {
            std:: cout<< i << "." << arena.getPlayer().getDeadCreatures().at(i);
        }
        int creatureToReplace;
        std::cin >> creatureToReplace;
        try {
            arena.getPlayer().addCreature(gameCreatures.at(selectedCreature));
            arena.getPlayer().deleteCreature(creatureToReplace,
                                             const_cast<std::vector<Creature> &>(arena.getPlayer().getDeadCreatures()));
        } catch (std::out_of_range e) {
            std::cout << "Wrong input!"<<std::endl;
        }
    }

}

void Game::levelUpCreatures(Arena &arena) {
    for(auto &creature : arena.getPlayer().getCreatures()) {
        if(creature.getExp() >= GameParams::EXP_PER_KILL * creature.getLevel()) {
            int firstAttribute = -1;
            while (firstAttribute<1 || firstAttribute>3) {
                std::cout << creature.getName()
                          << " levels up. Choose first attribute to increase(1-HP, 2-S, 3:D):" << std::endl;
                std::cin >> firstAttribute;
            }
            const_cast<Creature&>(creature).levelUp(firstAttribute);
            int secondAttribute = -1;
            while (secondAttribute<1 || secondAttribute>3) {
                std::cout <<"Choose second attribute to increase(1-HP, 2-S, 3:D):" << std::endl;
                std::cin >> secondAttribute;
            }
            const_cast<Creature&>(creature).levelUp(secondAttribute);
            const_cast<Creature&>(creature).setLevel(creature.getLevel() + 1);
        }
    }
}

GameParams Game::chooseDifficulty() {
    std::cout << "Type difficulty level(1 - easy, 2 - normal, 3 - hard): ";
    int difficultyNumber;
    std::cin >> difficultyNumber;
    std::cout<<std::endl;
    switch (difficultyNumber) {
        case 2 :
            return GameParams(GameParams::normal);
            break;
        case 3:
            return GameParams(GameParams::hard);
        default:
            return  GameParams(GameParams::easy);
            break;
    }
}

void Game::chooseCreaturesForPlayer(Player &player, const std::vector<Creature> &gameCreatures) {
    for(int i = 0; i < gameCreatures.size(); i++) {
        std:: cout<< i << "." << gameCreatures.at(i);
    }
    std::cout << "Choose 6 creatures:" << std::endl;

    for (int i = 0; i < GameParams::MAX_PLAYER_CREATURES; ++i) {
        try {
            int number = -1;
            std::cin >> number;
            if (!player.isCreaturePresent(const_cast<Creature &>(gameCreatures.at(number)), player.getCreatures()))
                player.addCreature(gameCreatures.at(number));
            else{
                std::cout << "You have this creature already!"<< std::endl;
                i--;
            }
        } catch (std::out_of_range e) {
            std::cout<< "Wrong input!"<<std::endl;
            i--;
        }

    }
    std::cout << std::endl;

}

std::vector<Creature> Game::creatures() {
    Elemental water = Elemental("water", SpecialAttack("Tsunami",100));
    Elemental earth = Elemental("earth", SpecialAttack("EarthQuake",100));
    Elemental air = Elemental("air", SpecialAttack("Tornado",100));
    Elemental fire = Elemental("fire", SpecialAttack("Lava Attack",100));
    Elemental ice = Elemental("ice", SpecialAttack("Frost",100));
    Elemental steel = Elemental("steel", SpecialAttack("steelFist",100));

    water.addWeakness(water);
    water.setStrengths({earth, fire});
    earth.addWeakness(air);
    earth.setStrengths({fire, ice, steel});
    air.setWeaknesses({earth, steel});
    air.addStrength(ice);
    fire.setWeaknesses({water, earth});
    fire.setStrengths({ice, steel});
    ice.setWeaknesses({water, fire, ice});
    ice.addStrength(earth);
    steel.setWeaknesses({fire, steel});
    steel.setStrengths({water, earth});

    Creature squirtle = Creature("Squirtle", 30, 30, 80, water,1);
    Creature bulbasaur = Creature("Bulbasaur", 35, 30, 70, earth,1);
    Creature pidgey = Creature("Pidgey", 30,40,60,air,1);
    Creature charmander = Creature("Charmander",40,30,60,fire,1);
    Creature swinub = Creature("Swinub", 30, 40, 60, ice,1);
    Creature magnemite = Creature("Magnemite", 40, 40, 40, steel,1);
    Creature caterpie = Creature("Caterpie",20,40,80,earth,1);
    Creature psyduck = Creature("Psyduck",35,35,60,water,1);
    Creature zubat = Creature("Zubat", 30, 40,60,air,1);
    Creature vulpix = Creature("Vulpix",30,40,60,fire,1);
    Creature seel = Creature("Seel", 30,30,80,ice,1);
    Creature aron = Creature("Aron",50,20,60,steel,1);
    Creature wartortle = Creature("Wartortle", 40, 35,90, water,1);
    Creature ivysaur = Creature("Ivysaur",40,40,80,earth,1);
    Creature pidgeotto = Creature("Pidgeotto", 40,40,80,air,1);


    return {squirtle,bulbasaur,pidgey,charmander,swinub,magnemite,caterpie,psyduck,zubat,vulpix,seel,aron,wartortle,ivysaur,pidgeotto};
}

void Game::loadGame(Player &player, GameParams &params, int &enemyCounter, const std::vector<std::string> gameProgress,
                    const std::vector<std::string> aliveCreatures, const std::vector<std::string> deadCreatures,
                    const std::vector<std::string> availableCreatures) {

    player.setName(gameProgress.front());
    Arena arena = Arena();
    arena.round = std::stoi(gameProgress.at(1)) - 1;
    enemyCounter = std::stoi(gameProgress.at(2));
    params.difficulty = static_cast<GameParams::Difficulty>(std::stoi(gameProgress.at(3)));

    std::vector<Creature> aliveCreaturesVector;
    for (int i = 0; i < aliveCreatures.size(); i+=9) {
        Creature creature = Creature(
                aliveCreatures.at(i),
                std::stoi(aliveCreatures.at(i+1)),
                std::stod(aliveCreatures.at(i+2)),
                std::stod(aliveCreatures.at(i+3)),
                std::stod(aliveCreatures.at(i+4)),
                std::stod(aliveCreatures.at(i+5)),
                findElementalByName(aliveCreatures.at(i+6)),
                std::stoi(aliveCreatures.at(i+7)),
                false
                );
        aliveCreaturesVector.push_back(creature);
    }
    player.setCreatures(aliveCreaturesVector);
    std::vector<Creature> deadCreaturesVector;
    for (int i = 0; i < deadCreatures.size(); i+=9) {
        Creature creature = Creature(
                deadCreatures.at(i),
                std::stoi(deadCreatures.at(i+1)),
                std::stod(deadCreatures.at(i+2)),
                std::stod(deadCreatures.at(i+3)),
                std::stod(deadCreatures.at(i+4)),
                std::stod(deadCreatures.at(i+5)),
                findElementalByName(deadCreatures.at(i+6)),
                std::stoi(deadCreatures.at(i+7)),
                true
        );
        deadCreaturesVector.push_back(creature);
    }
    player.setDeadCreatures(deadCreaturesVector);
    std::vector<Creature> availableCreaturesVector;
    for (int i = 0; i < availableCreatures.size(); i+=9) {
        Creature creature = Creature(
                availableCreatures.at(i),
                std::stoi(availableCreatures.at(i+1)),
                std::stod(availableCreatures.at(i+2)),
                std::stod(availableCreatures.at(i+3)),
                std::stod(availableCreatures.at(i+4)),
                std::stod(availableCreatures.at(i+5)),
                findElementalByName(availableCreatures.at(i+6)),
                std::stoi(availableCreatures.at(i+7)),
                false
        );
        availableCreaturesVector.push_back(creature);
    }
    player.setAvailableCreatures(availableCreaturesVector);
}

Elemental Game::findElementalByName(std::string name) {
    Elemental water = Elemental("water", SpecialAttack("Tsunami",100));
    Elemental earth = Elemental("earth", SpecialAttack("EarthQuake",100));
    Elemental air = Elemental("air", SpecialAttack("Tornado",100));
    Elemental fire = Elemental("fire", SpecialAttack("Lava Attack",100));
    Elemental ice = Elemental("ice", SpecialAttack("Frost",100));
    Elemental steel = Elemental("steel", SpecialAttack("steelFist",100));

    water.addWeakness(water);
    water.setStrengths({earth, fire});
    earth.addWeakness(air);
    earth.setStrengths({fire, ice, steel});
    air.setWeaknesses({earth, steel});
    air.addStrength(ice);
    fire.setWeaknesses({water, earth});
    fire.setStrengths({ice, steel});
    ice.setWeaknesses({water, fire, ice});
    ice.addStrength(earth);
    steel.setWeaknesses({fire, steel});
    steel.setStrengths({water, earth});
    std::vector<Elemental> v {water,earth,air,fire,ice,steel};
    for (auto & el: v) {
        if(el.getName() == name) {
            return el;
        }
    }
    return Elemental("",SpecialAttack("",0));
}


