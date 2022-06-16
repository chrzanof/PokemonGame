#include <iostream>
#include "Creature.h"
#include "Elemental.h"
#include "Player.h"
#include "Enemy.h"
#include "Arena.h"
#include <vector>
int main() {
    srand(time(NULL));
    Elemental water = Elemental("water");
    Elemental earth = Elemental("earth");
    Elemental air = Elemental("air");
    Elemental fire = Elemental("fire");
    Elemental ice = Elemental("ice");
    Elemental steel = Elemental("steel");
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
    Creature wartortle = Creature("Wartortle", 40, 35,90, water,2);
    Creature ivysaur = Creature("Ivysaur",40,40,80,earth,2);
    Creature pidgeotto = Creature("Pidgeotto", 40,40,80,air,2);
    Creature charmeleon = Creature("Charmeleon", 30,50,80,fire,2);
    Creature magneton = Creature("Magneton",40,50,60,steel,2);
    Creature piloswine = Creature("Piloswine",60,15,90,ice,2);
    Creature blastoise = Creature("Blastoise", 50, 40, 100, water,3);
    Creature venusaur = Creature("Venusaur",50,40,100,earth,3);
    Creature pidgeot = Creature("Pidgeot", 40,60,80,air,3);
    Creature charizard = Creature("Charizard", 60,40,80,fire,3);
    Creature mamoswine = Creature("Mamoswine",70,15,110,ice,3);
    Creature magnezone = Creature("Magnezone", 50, 40, 100,steel,3);

    std::vector<Creature> creaturesLevel1{squirtle, bulbasaur, pidgey, charmander, swinub, magnemite, caterpie, psyduck, zubat, vulpix, seel, aron};
    std::vector<Creature> creaturesLevel2{wartortle,ivysaur,pidgeotto,charmeleon,magneton,piloswine};
    std::vector<Creature> creaturesLevel3{blastoise,venusaur,pidgeot,charizard,mamoswine,magnezone};

    bool gameOver = false;


    // Wybór stworzeń przez gracza
    for(int i = 0; i < creaturesLevel1.size(); i++) {
        std:: cout<< i << "." << creaturesLevel1.at(i);
    }
    Player player = Player("player");
    std::cout << "Wybierz 6 stworzen:" << std::endl;

    for (int i = 0; i < Player::getMaxCreatures(); ++i) {
        try {
            int number = -1;
            std::cin >> number;
            if (!player.isCreaturePresent(creaturesLevel1.at(number), player.getCreatures()))
                player.addCreature(creaturesLevel1.at(number));
            else{
                std::cout << "Posiadasz juz te stworzenie"<< std::endl;
                i--;
            }
        } catch (std::out_of_range e) {
            std::cout<< "Wrong input!"<<std::endl;
            i--;
        }

    }
    for (auto &creature: player.getCreatures()) {
        std::cout << creature.getName() << " ";

    }
    std::cout << std::endl;

    //główna pętla gry
    int counter = 0;
    while (Arena::round < 4) {
        counter++;
        Arena arena = Arena(player, Enemy("enemy " + std::to_string(counter)));
        arena.getEnemy().setRandomCreatures(creaturesLevel1);

        // tury gracz - przeciwnik
        while (!arena.getEnemy().getCreatures().empty() && !arena.getPlayer().getCreatures().empty()) {

            arena.getPlayer().setAvailableCreatures(arena.getPlayer().getCreatures());
            arena.getEnemy().setAvailableCreatures(arena.getEnemy().getCreatures());
            //tura gracz
            while(!arena.getPlayer().getAvailableCreatures().empty() && !arena.getEnemy().getCreatures().empty()) {
                try {
                    std::cout << arena;
                    std::cout << arena.getPlayer().getName() << "\'s turn" << std::endl;
                    arena.setPlayerTurnCounter(arena.getPlayerTurnCounter() + 1);
                    int playerCreature = -1, enemyCreature = -1;
                    std::cin >> playerCreature;
                    while(!arena.getPlayer().isCreaturePresent(
                            const_cast<Creature &>(arena.getPlayer().getCreatures().at(playerCreature)),
                            arena.getPlayer().getAvailableCreatures())) {
                        std::cout << arena.getPlayer().getCreatures().at(playerCreature).getName() << " already attacked in this turn"<< std::endl;
                        std::cin >> playerCreature;
                    }
                    std::cin >> enemyCreature;
                    double damage = arena.getPlayer().attack(playerCreature,
                                                             arena.getEnemy().getCreatures().at(enemyCreature));
                    const_cast<Creature &>(arena.getEnemy().getCreatures().at(
                            enemyCreature)).tryToEvadeAndTakeDamageIfFailed(damage);
                    arena.getPlayer().ifFoundDeleteCreature(arena.getPlayer().getCreatures().at(playerCreature),
                                                            const_cast<std::vector<Creature> &>(arena.getPlayer().getAvailableCreatures()));
                    arena.getEnemy().updateDeadCreatures();
                } catch (std::out_of_range e) {
                    std::cout << "wrong input!"<<std::endl;
                }

            }
            //tura przeciwnik
            while (!arena.getEnemy().getAvailableCreatures().empty() && !arena.getPlayer().getCreatures().empty()){
                std::cout << arena;
                std::cout << arena.getEnemy().getName() << "\'s turn" << std::endl;
                arena.setEnemyTurnCounter(arena.getEnemyTurnCounter() + 1);
                int attackingCreatureNumber = rand() % arena.getEnemy().getAvailableCreatures().size();
                int attackedCreatureNumber = rand() % arena.getPlayer().getCreatures().size();
                int damage = arena.getEnemy().attack(attackingCreatureNumber,arena.getPlayer().getCreatures().at(attackedCreatureNumber));
                const_cast<Creature &>(arena.getPlayer().getCreatures().at(attackedCreatureNumber)).tryToEvadeAndTakeDamageIfFailed(damage);
                //arena.getEnemy().ifFoundDeleteCreature(arena.getEnemy().getCreatures().at(attackingCreatureNumber),
                //                                        const_cast<std::vector<Creature> &>(arena.getEnemy().getAvailableCreatures()));
                std::vector<Creature>&v = const_cast<std::vector<Creature>&>(arena.getEnemy().getAvailableCreatures());
                v.erase(v.begin() + attackingCreatureNumber);
                arena.getPlayer().updateDeadCreatures();
                getchar();
            }
        }
        player = arena.getPlayer();


        if(arena.getPlayer().getCreatures().empty()){
            std::cout<< std::endl << "Game Over! You've lost!" << std::endl;
            gameOver = true;
            break;
        } else {
            std::cout<<"You won round " << Arena::round << std::endl;
            // możliwa wymiana stworzenia
            // możliwy zapis gry
            // ewolucja stworzenia
        }
    }





    if(!gameOver)
        std::cout << "Congratulations, you finished the game!"<< std::endl;
    return 0;
}
