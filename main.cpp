#include <iostream>
#include "Creature.h"
#include "Elemental.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
int main() {
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

    Creature squirtle = Creature("Squirtle", 30, 30, 40, water,1);
    Creature bulbasaur = Creature("Bulbasaur", 35, 30, 35, earth,1);
    Creature pidgey = Creature("Pidgey", 30,40,30,air,1);
    Creature charmander = Creature("Charmander",40,30,30,fire,1);
    Creature swinub = Creature("Swinub", 30, 40, 30, ice,1);
    Creature magnemite = Creature("Magnemite", 40, 40, 20, steel,1);
    Creature caterpie = Creature("Caterpie",20,40,40,earth,1);
    Creature psyduck = Creature("Psyduck",35,35,30,water,1);
    Creature zubat = Creature("Zubat", 30, 40,30,air,1);
    Creature vulpix = Creature("Vulpix",30,40,30,fire,1);
    Creature seel = Creature("Seel", 30,30,40,ice,1);
    Creature aron = Creature("Aron",50,20,30,steel,1);
    Creature wartortle = Creature("Wartortle", 40, 35,45, water,2);
    Creature ivysaur = Creature("Ivysaur",40,40,40,earth,2);
    Creature pidgeotto = Creature("Pidgeotto", 40,40,40,air,2);
    Creature charmeleon = Creature("Charmeleon", 30,50,40,fire,2);
    Creature magneton = Creature("Magneton",40,50,30,steel,2);
    Creature piloswine = Creature("Piloswine",60,15,45,ice,2);
    Creature blastoise = Creature("Blastoise", 50, 40, 50, water,3);
    Creature venusaur = Creature("Venusaur",50,40,50,earth,3);
    Creature pidgeot = Creature("Pidgeot", 40,60,40,air,3);
    Creature charizard = Creature("Charizard", 60,40,40,fire,3);
    Creature mamoswine = Creature("Mamoswine",70,15,55,ice,3);
    Creature magnezone = Creature("Magnezone", 50, 40, 50,steel,3);

    std::vector<Creature> creaturesLevel1{squirtle, bulbasaur, pidgey, charmander, swinub, magnemite, caterpie, psyduck, zubat, vulpix, seel, aron};
    std::vector<Creature> creaturesLevel2{wartortle,ivysaur,pidgeotto,charmeleon,magneton,piloswine};
    std::vector<Creature> creaturesLevel3{blastoise,venusaur,pidgeot,charizard,mamoswine,magnezone};

    Enemy enemy1 = Enemy("enemy1");
    enemy1.setRandomCreatures(creaturesLevel1);

    for (auto & creature: enemy1.getCreatures()) {
        std::cout << creature.getName() << std::endl;
    }








    return 0;
}
