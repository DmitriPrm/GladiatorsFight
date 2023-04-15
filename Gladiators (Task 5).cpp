
#include <iostream>

using namespace std;

class Gladiator
{
	string name;
	int health;
public: 
	Gladiator(string name)
	{
		this->name = name;
	}
	string get_name()
	{
		return name;
	}
	void set_name(string name)
	{
		this->name = name;
	}
};

class Weapon
{
protected: 
	int damage;
public:
	Weapon()
	{

	}
	Weapon(int damage)
	{
		this->damage = damage;
	}
	int get_damage()
	{
		return damage;
	}
	void set_damage(int damage)
	{
		this->damage = damage;
	}
};

class Defence
{
protected: 
	int armor;
public: 
	Defence()
	{

	}
	Defence(int armor)
	{
		this->armor = armor;
	}
	int get_armor()
	{
		return armor;
	}
	void set_armor(int armor)
	{
		this->armor = armor;
	}
};

class Sword : public Weapon
{
public:
	Sword(int damage) : Weapon(damage) {}
	Sword() : Weapon() { damage = 5; }
};

class Spear : public Weapon
{
public:
	Spear(int damage) : Weapon(damage) {}
	Spear() : Weapon() { damage = 5; }
};

class Helmet : public Defence
{
public:
	Helmet(int armor) : Defence(armor) {}
	Helmet() : Defence() { armor = 5; }
};

class ChestPlate : public Defence
{
public:
	ChestPlate(int armor) : Defence(armor) {}
	ChestPlate() : Defence() { armor = 5; }
};

class Greaves : public Defence
{
public:
	Greaves(int armor) : Defence(armor) {}
	Greaves() : Defence() { armor = 5; }
};
 
/*
Реализовать иерархии классов "Гладиаторы", "Оружие гладиаторов" и "Защитные средства".
Промоделировать бой между гладиаторами.
*/


int main()
{

}