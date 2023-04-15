
#include <iostream>
#include <vector>
#include <map>
using namespace std;

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

class Armor
{
protected:
	int armor;
public:
	Armor()
	{

	}
	Armor(int armor)
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

class Helmet : public Armor
{
public:
	Helmet(int armor) : Armor(armor) {}
	Helmet() : Armor() { armor = 5; }
};

class ChestPlate : public Armor
{
public:
	ChestPlate(int armor) : Armor(armor) {}
	ChestPlate() : Armor() { armor = 5; }
};

class Greaves : public Armor
{
public:
	Greaves(int armor) : Armor(armor) {}
	Greaves() : Armor() { armor = 5; }
};

class Gladiator
{
	string name;
	int health;
	Weapon* weapon;
	map<string, Armor*> armor;
public: 
	Gladiator(string name)
	{
		this->name = name;
		armor["Helmet"] = nullptr;
		armor["ChestPlate"] = nullptr;
		armor["Greaves"] = nullptr;
		armor["Shield"] = nullptr;
	}
	string get_name()
	{
		return name;
	}
	void set_name(string name)
	{
		this->name = name;
	}
	Weapon* get_weapon()
	{
		return weapon;
	}
	void set_weapon(Weapon* weapon)
	{
		this->weapon = weapon;
	}
	void add_armor(Armor* armor)
	{
		
	}

};

 
/*
Реализовать иерархии классов "Гладиаторы", "Оружие гладиаторов" и "Защитные средства".
Промоделировать бой между гладиаторами.
*/


int main()
{
	Gladiator max("Maximus");
	Sword sw;
	max.set_weapon(&sw);
	Greaves gr;
	max.add_armor(&gr);
}