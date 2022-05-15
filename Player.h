#pragma once
#include "Entity.h"
#include "GameExceptions.h"
#include "Weapons.h"

class Player :
    public Entity
{
private:
    enum class commands
    {
        attack,
        special,
        item
    };
    unsigned int EP=100, MEP=100, POT=5, LVL = 1, EXP = 0;
    void levelUp();
    void attack(Entity& target);
    void special(const std::vector<Entity*>&);
    void item();
    void describe(std::ostream&) const override;
    static commands resolveCommand(const std::string&);
public:
    explicit Player(std::string);
    ~Player() override = default;
    Player(const Player&) = delete;
    void operator=(const Player&) = delete;
    void act(Entity&, std::vector<Entity*>&) override;
    void checkLvlUp();
    void gainExp(unsigned int);
};

