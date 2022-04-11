#include "Battle.h"


Battle::Battle(Player& plr)
	:
	player(&plr)
{
	for (int i = 0; i < 3; ++i)
	{
		Entity* newEnemy = new Enemy();
		enemies.push_back(newEnemy);
	}
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
	player->act(*player, enemies);
	for (auto enemy : enemies)
		if (enemy->isAlive())
			enemy->act(*player, enemies);
}


void Battle::play()
{
	while(!over())
	{
		playTurn();
	}
	if (player->isAlive())
		std::cout << "\n~~Victory!~~\n" << player->getName() << " has defeated the enemies!\n";
	else
		std::cout << "]\n~~Defeat!~~\n" << player->getName() << " has been defeated!\n";
}

