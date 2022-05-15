#include "Battle.h"
#include <time.h>
int main()
{
    srand(clock());
    LegendaryWeapon* myWeapon = new PlayerWeapon(20);
    myWeapon = applyModifier<BloodLust>(myWeapon);
    myWeapon = applyModifier<VampiricEdge>(myWeapon);
    myWeapon = applyModifier<ReapersLuck>(myWeapon);
    Player me("Player",myWeapon);
    Battle battle(me);
    battle.play();
}

