#pragma once
#include "Player.h"
#include "Human.h"
#include "Enemies.h"
#include <algorithm>

class Battle
{
private:
	Player* player;
	std::vector<Entity*> enemies;
	void playTurn();
	bool over();
public:
	explicit Battle(Player&);
	Battle(const Battle&) = delete;
	void play();
	~Battle();

};

