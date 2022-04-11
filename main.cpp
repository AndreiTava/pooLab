#include "Battle.h"

int main()
{
    Player me("Dumitran");
    auto battle = Battle::getInstance(me);
    battle->play();
}

