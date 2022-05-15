#pragma once
#include "Entity.h"

class decideStrategy
{

public:
	virtual Entity& decideTarget(Entity&, const std::vector<Entity*>&) = 0;
};

class normalStrategy : decideStrategy
{
public:
	Entity & decideTarget(Entity&, const std::vector<Entity*>&) override;
};
class healerStrategy : decideStrategy
{
public:
	Entity& decideTarget(Entity&, const std::vector<Entity*>&) override;
};
class aoeStrategy : decideStrategy
{
public:
	Entity& decideTarget(Entity&, const std::vector<Entity*>&) override;
};
