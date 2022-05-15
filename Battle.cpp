#include "Battle.h"
Battle::Battle(Player& plr)
	:
	player(&plr)
{
	Entity* newEnemy = new Human<Sword>;
	enemies.push_back(newEnemy);
	newEnemy = new Human<Staff>;
	enemies.push_back(newEnemy);
}
Battle::~Battle()
{
	for (const auto& en : enemies)
		delete en;
	enemies.clear();
}

bool Battle::over()
{
	if (!player->isAlive())
		return true;
	bool victory = true;
	if (std::any_of(enemies.begin(), enemies.end(), [](const Entity* e) {return e->isAlive(); }))
		victory = false;
	if (victory)
		return true;
	return false;
}

void Battle::playTurn()
{
	std::cout << "\n~New turn~\n";
	player->act(*player, enemies);
	for (size_t i=0;i<enemies.size();++i)
		if (enemies[i]->isAlive())
			enemies[i]->act(*player, enemies);
}


void Battle::play()
{
	std::cout << "~~A battle has started!~~\n";
	while(!over())
	{
		playTurn();
	}
	if (player->isAlive())
		std::cout << "\n~~Victory!~~\n" << player->getName() << " has defeated the enemies!\n";
	else
		std::cout << "\n~~Defeat!~~\n" << player->getName() << " has been defeated!\n";
}

