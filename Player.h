#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:
    unsigned int LVL = 1, EXP = 0;
    void levelUp();
    void attack(Entity& target);
    void describe(std::ostream&) const override;
public:
    Player(std::string name);
    void act(Entity&, std::vector<Entity*>&);
    void checkLvlUp();
    void gainExp(unsigned int);
};

