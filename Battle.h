#pragma once
#include "Player.h"
#include "Enemy.h"
#include <memory>

class Battle
{
private:
	static Battle* instance;
	std::unique_ptr<Player> player;
	std::vector<Entity*> enemies;
	Battle(Player&);
	void playTurn();
	bool over();
public:
	static Battle* getInstance(Player&);
	Battle(const Battle&) = delete;
	void start();
	~Battle();

};

