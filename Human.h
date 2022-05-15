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
};

template <>
class Human<Staff> : public Enemy
{
	Staff weapon;
	void describe(std::ostream&) const override;
	void interact(Entity&) override;
public:
	Human();
	~Human() override = default;
};

template <class weapon_type>
Human<weapon_type>::Human()
	:
	Enemy("Human", 50, 20, 15, 100)
{}


/*n-am de ales decat sa fac asta aici*/

template <class weapon_type>
void Human<weapon_type>::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "is wielding a " << weapon << "\n";
}

template <class weapon_type>
void Human<weapon_type>::interact(Entity& target)
{
	std::cout << "(<<)\n" << this->name << " attacks " << target.getName() << " with " << weapon_type::getName() << "\n";
	weapon.use(ATK, target);
}

inline Human<Staff>::Human()
	:
	Enemy("Human", 50, 20, 15, 100)
{}




inline void Human<Staff>::describe(std::ostream& out) const
{
	this->Enemy::describe(out);
	out << "is wielding a " << weapon << "\n";
}


inline void Human<Staff>::interact(Entity& target)
{
	std::cout << "(<<)\n" << this->name << " heals " << target.getName() << " with " << Staff::getName() << "\n";
	weapon.use(ATK, target);
}



