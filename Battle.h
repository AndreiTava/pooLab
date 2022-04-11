#pragma once
#include "Player.h"
#include "Enemy.h"
#include <memory>
#include <algorithm>

class Battle
{
private:
	std::shared_ptr<Player> player;
	std::vector<Entity*> enemies;
	void playTurn();
	bool over();
public:
	explicit Battle(Player&);
	Battle(const Battle&) = delete;
	void play();
	~Battle();

};

