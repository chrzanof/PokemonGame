#include <iostream>
#include "Creature.h"
#include "Elemental.h"
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

    Creature squirtle = Creature("Squirtle", 30, 30, 30, water,1);
    Creature bulbasaur = Creature("Bulbasaur", 30, 30, 30, earth,1);
    Creature pidgey = Creature("Pidgey", 30,40,30,air,1);
    Creature charmander = Creature("Charmander",40,40,30,fire,1);
    Creature swinub = Creature("Swinub", 30, 30, 30, ice,1);
    Creature magnemite = Creature("Magnemite", 30, 30, 20, steel,1);

    Creature wartortle = Creature("Wartortle", 40, 35,40, water,2);
    Creature blastoise = Creature("Blastoise", 50, 40, 50, water,3);
    wartortle.setNextForm(&blastoise);
    squirtle.setNextForm(&wartortle);
    Creature ivysaur = Creature("Ivysaur",40,40,40,earth,2);
    Creature venusaur = Creature("Venusaur",50,50,50,earth,3);
    ivysaur.setNextForm(&venusaur);
    bulbasaur.setNextForm(&ivysaur);
    Creature pidgeotto = Creature("Pidgeotto", 40,50,40,air,2);
    Creature pidgeot = Creature("Pidgeot", 50,60,50,air,3);
    pidgeotto.setNextForm(&pidgeot);
    pidgey.setNextForm(&pidgeotto);
    Creature charmeleon = Creature("Charmeleon", 40,50,40,fire,2);
    Creature charizard = Creature("Charizard", 60,50,50,fire,3);
    charmeleon.setNextForm(&charizard);
    charmander.setNextForm(&charmeleon);
    Creature piloswine = Creature("Piloswine",60,30,60,ice,2);
    Creature mamoswine = Creature("Mamoswine",70,50,60,ice,3);
    piloswine.setNextForm(&mamoswine);
    swinub.setNextForm(&piloswine);
    Creature magneton = Creature("Magneton",40,50,30,steel,2);
    Creature magnezone = Creature("Magnezone", 50, 40, 50,steel,3);
    magneton.setNextForm(&magnezone);
    magnemite.setNextForm(&magneton);








    return 0;
}
