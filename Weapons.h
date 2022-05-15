#pragma once
#include "Entity.h"

class Sword
{
	static std::string name;
public:
	void use(unsigned int, Entity&);
	static std::string getName();
	friend std::ostream& operator<<(std::ostream&, const Sword&);
};


class Staff 
{
	static std::string name;
public:
	void use(unsigned int, Entity& targets);
	static std::string getName();
	friend std::ostream& operator<<(std::ostream&, const Staff&);
};



class LegendaryWeapon
{
public:
	virtual unsigned int use(unsigned int,Entity&) = 0;
	virtual ~LegendaryWeapon() = default;
	virtual void addAttack(unsigned int) = 0;
};


class PlayerWeapon : public LegendaryWeapon
{
	unsigned int ATK;
public:
	PlayerWeapon(unsigned int = 10);
	unsigned int use(unsigned int, Entity&) override;
	void addAttack(unsigned int) override;
};

class LegendaryDecorator : public LegendaryWeapon
{
protected:
	std::unique_ptr<LegendaryWeapon> weapon;
public:
	LegendaryDecorator(LegendaryWeapon*);
	unsigned int use(unsigned int, Entity&) = 0;
	void addAttack(unsigned) override;
};

class VampiricEdge : public LegendaryDecorator
{
public:
	VampiricEdge(LegendaryWeapon*);
	unsigned int use(unsigned int, Entity&) override;
};
class BloodLust : public LegendaryDecorator
{
public:
	BloodLust(LegendaryWeapon*);
	unsigned int use(unsigned int, Entity&) override;
};
class ReapersLuck : public LegendaryDecorator
{
public:
	ReapersLuck(LegendaryWeapon*);
	unsigned int use(unsigned int, Entity&) override;
};


template<class modifier>
LegendaryWeapon* applyModifier(LegendaryWeapon* wpn)
{
	return new modifier(wpn);
};