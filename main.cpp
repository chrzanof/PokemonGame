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
    water.setStrengths({earth,fire});
    earth.addWeakness(air);
    earth.setStrengths({fire, ice, steel});
    air.setWeaknesses({earth, steel});
    air.addStrength(ice);
    fire.setWeaknesses({water,earth});
    fire.setStrengths({ice, steel});
    ice.setWeaknesses({water, fire, ice});
    ice.addStrength(earth);
    steel.setWeaknesses({fire, steel});
    steel.setStrengths({water, earth});


    return 0;
}
