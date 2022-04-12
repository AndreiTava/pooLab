#pragma once
#include "Enemy.h"

class Goblin : public Enemy
{
private:
	void describe(std::ostream&) const override;
public:
	Goblin();
	virtual ~Goblin() override = default;
};
class Treant : public Enemy
{
private:
	void describe(std::ostream&) const override;
	Entity& decideTarget(Entity&, const std::vector<Entity*>&) override;
public:
	Treant();
	~Treant() override = default;
};

class Slime : public Enemy
{
private:
	void describe(std::ostream&) const override;
public:
	Slime();
	~Slime() override = default;
	void act(Entity&, std::vector<Entity*>&) override;
};
class Mimic : public Enemy
{
private:
	void describe(std::ostream&) const override;
public:
	Mimic();
	~Mimic() override = default;
	void act(Entity&, std::vector<Entity*>&) override;
};