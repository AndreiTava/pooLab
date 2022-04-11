#include "Battle.h"

int main()
{
    /*Player me("Dumitran");
    Battle battle(me);
    battle.play();*/
    Entity* iWantToDie = new Enemy();
    std::cout << *iWantToDie << "\n";
    delete iWantToDie;
}

