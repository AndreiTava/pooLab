#include "Battle.h"

int main()
{
    /*Player me("Dumitran");
    Battle battle(me);
    battle.play();*/
    Entity* iWantToDie = new Enemy();
    std::cout << *iWantToDie << "\n";
    iWantToDie->takeDamage(10);
    delete iWantToDie;
}

