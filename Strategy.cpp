#include "Strategy.h"

Entity& normalStrategy::decideTarget(Entity& player, const std::vector<Entity*>& enemies)
{
	if (enemies.empty())
		return player;
	return player;
}

decideStrategy* normalStrategy::clone()
{
	return new normalStrategy;
}

Entity& healerStrategy::decideTarget(Entity& player, const std::vector<Entity*>& enemies)
{
	if (enemies.empty())
		return player;
	const size_t ind = rand() % (enemies.size() - 1);
	return *enemies[ind];
}

decideStrategy* healerStrategy::clone()
{
	return new healerStrategy;
}
