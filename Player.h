#pragma once
#include "Entity.h"
#include "GameExceptions.h"

class Player :
    public Entity
{
private:
    enum class commands
    {
        attack,
        special,
        item,
        run
    };
    unsigned int EP=100, MEP=100, POT=5, LVL = 1, EXP = 0;
    void levelUp();
    void attack(Entity& target);
    void describe(std::ostream&) const override;
    static commands resolveCommand(std::string);
public:
    explicit Player(std::string name);
    void operator=(const Player&) = delete;
    void act(Entity&, std::vector<Entity*>&) override;
    void checkLvlUp();
    void gainExp(unsigned int);
};

