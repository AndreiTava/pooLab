#pragma once
#include "Entity.h"

class decideStrategy
{
public:
	virtual Entity& decideTarget(Entity&, const std::vector<Entity*>&) = 0;
	virtual decideStrategy* clone() = 0;
	virtual ~decideStrategy() = default;
};

class normalStrategy : public decideStrategy
{
public:
	Entity & decideTarget(Entity&, const std::vector<Entity*>&) override;
	decideStrategy* clone() override;
};
class healerStrategy : public decideStrategy
{
public:
	Entity& decideTarget(Entity&, const std::vector<Entity*>&) override;
	decideStrategy* clone() override;
};
