#include "Battle.h"
#include <time.h>
int main()
{
    srand(clock());
    Player me("Player");
    Battle battle(me);
    battle.play();
}

