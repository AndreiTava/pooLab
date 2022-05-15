#pragma once
#include <string>
#include <vector>
#include <iostream>

class Entity
{
protected:
	const std::string name;
	int HP,MHP,ATK,DEF;
	Entity(std::string,unsigned int, unsigned int,unsigned int);
	virtual void describe(std::ostream&) const = 0;
	Entity(const Entity&);
	void operator=(const Entity&);
public:
	virtual ~Entity() = default;
	virtual void act(Entity&, std::vector<Entity*>&) = 0;
	virtual void takeDamage(int);
	virtual void die(Entity&);
	bool isAlive() const;
	std::string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Entity&);
};

