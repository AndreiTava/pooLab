#pragma once
#include "Enemy.h"
#include "Weapons.h"

template <class weapon_type>
class Human : public Enemy
{
private:
	weapon_type weapon;
	void describe(std::ostream&) const override;
	void interact(Entity&) override;
public:
	Human();
	~Human() override = default;
	friend std::istream& operator>>(std::istream&, Human&);
};

template <>
class Human<Staff> : public Enemy
{
private:
	Staff weapon;
	void describe(std::ostream&) const override;
	Entity& decideTarget(Entity&, const std::vector<Entity*>&) override;
	void interact(Entity&) override;
public:
	Human();
	~Human() override = default;
	friend std::istream& operator>>(std::istream&, Human&);
};