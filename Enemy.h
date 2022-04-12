#pragma once
#include "Entity.h"
#include "Player.h"
class Enemy :
	public Entity
{
protected:
	enum class types
	{
		goblin,
		treant,
		slime,
		mimic,
	};
	unsigned int EXP;
	virtual Entity& decideTarget(Entity&, const std::vector<Entity*>&);
	void die(Entity& culprit) override;
	virtual void interact(Entity&);
	void describe(std::ostream&) const override;
	static types resolveType(std::string);
public:
	~Enemy() override = default;
	Enemy(std::string = "Generic Enemy", unsigned int = 10, unsigned int = 10, unsigned int = 0, unsigned int = 0);
	Enemy(const Enemy&);
	void operator=(const Enemy&);
	void act(Entity& ,std::vector<Entity*>&) override;
};
