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
	virtual void use(unsigned int,Entity&) = 0;
	virtual ~LegendaryWeapon() = default;
};


class PlayerWeapon : public LegendaryWeapon
{
	unsigned int ATK;
public:
	void use(unsigned int, Entity&) override;
};

class VampiricEdge : LegendaryWeapon
{
	
};
class BloodLust : LegendaryWeapon
{
	
};
class ReapersLuck : LegendaryWeapon
{
	
};
