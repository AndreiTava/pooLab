#pragma once
#include "Strategy.h"
#include "Player.h"
#include <memory>

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
	std::unique_ptr<decideStrategy> strategy;
	void die(Entity& culprit) override;
	virtual void interact(Entity&);
	void describe(std::ostream&) const override;
	static types resolveType(const std::string&);
public:
	~Enemy() override = default;
	Enemy(std::string = "Generic Enemy", unsigned int = 10, unsigned int = 10, unsigned int = 0, unsigned int = 0,decideStrategy* = new normalStrategy);
	Enemy(const Enemy&);
	void operator=(const Enemy&);
	void act(Entity& ,std::vector<Entity*>&) override;
};
