#pragma once
#include "Entity.h"
#include "Player.h"
class Enemy :
	public Entity
{
protected:
	const unsigned int EXP;
	virtual Entity& decideTarget(Entity&, const std::vector<Entity*>&);
	void die(Entity& culprit) override;
	virtual void interact(Entity&);
	/*void describe(std::ostream&) const override;*/
public:
	virtual ~Enemy() = default;
	Enemy(std::string = "Generic Enemy", unsigned int = 10, unsigned int = 10, unsigned int = 0, unsigned int = 0);
	void act(Entity& ,std::vector<Entity*>&) override;
};
