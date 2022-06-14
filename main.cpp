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

    Creature squirtle = Creature("Squirtle", 30, 30, 30, water);
    Creature bulbasaur = Creature("Bulbasaur", 30, 30, 30, earth);
    Creature pidgey = Creature("Pidgey", 30,40,30,air);
    Creature charmander = Creature("Charmander",40,40,30,fire);
    Creature swinub = Creature("Swinub", 30, 30, 30, ice);
    Creature magnemite = Creature("Magnemite", 30, 30, 30, steel);








    return 0;
}
