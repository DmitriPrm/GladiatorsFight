
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
	string type;
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
	string get_type()
	{
		return type;
	}
};

class Sword : public Weapon
{
public:
	Sword(int damage) : Weapon(damage) { }
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
	Helmet(int armor) : Armor(armor) { type = "Helmet"; }
	Helmet() : Armor() { type = "Helmet"; armor = 5; }
};

class ChestPlate : public Armor
{
public:
	ChestPlate(int armor) : Armor(armor) { type = "ChestPlate"; }
	ChestPlate() : Armor() { type = "ChestPlate"; armor = 5; }
};

class Greaves : public Armor
{
public:
	Greaves(int armor) : Armor(armor) { type = "Greaves"; }
	Greaves() : Armor() { type = "Greaves"; armor = 5; }
};

class Shield : public Armor
{
public:
	Shield(int armor) : Armor(armor) { type = "Shield"; }
	Shield() : Armor() { type = "Shield"; armor = 5; }
};

class Gladiator
{
	string name;
	bool isAlive = true;
	int health;
	Weapon* weapon;
	map<string, Armor*> armorList;
	int armor;
public: 
	Gladiator(string name)
	{
		this->name = name;
		armor = 0;
		health = 100;
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
	int get_health()
	{
		return health;
	}
	void set_health(int health)
	{
		this->health = health;
	}
	void set_weapon(Weapon* weapon)
	{
		this->weapon = weapon;
	}
	bool get_isAlive()
	{
		return isAlive;
	}
	void set_isAlive(bool isAlive)
	{
		this->isAlive = isAlive;
	}
	void add_armor(Armor* armor)
	{
		this->armorList[armor->get_type()] = armor;
		reset_armor(armor->get_armor());
	}
	void reset_armor(int value)
	{
		armor += value;
	}
	int get_armor()
	{
		return armor;
	}
	void hit(Gladiator* gl)
	{
		if (armor)
		{
			if (gl->get_armor() - weapon->get_damage() < 0)
			{
				armor = 0;
				return;
			}
			gl->reset_armor(-weapon->get_damage());
		}
		else
		{
			if (gl->health - weapon->get_damage() < 0)
			{
				gl->isAlive = false;
				return;
			}
			gl->health -= weapon->get_damage();
		}
	}
};

class Fight
{
	Gladiator* first;
	Gladiator* second;
public: 
	Fight(Gladiator* first, Gladiator* second)
	{
		this->first = first;
		this->second = second;
	};
	void print_hp()
	{
		cout << first->get_name() << ": " << first->get_health() << " hp , " << first->get_armor() << " armor ; " 
			<< second->get_name() << ": " << second->get_health() << " hp, " << second->get_armor() << " armor " << endl;
	}
	void start_fight()
	{
		while (first->get_isAlive() && second->get_isAlive())
		{
			first->hit(second);
			print_hp();
			if (!second->get_isAlive())
			{
				cout << "Гладиатор " << second->get_name() << " мертв!" << endl;
				break;
			}
			second->hit(first);
			print_hp();
		}
		if (first->get_isAlive())
		{
			cout << " --- Гладиатор " << first->get_name() << " победил! --- " << endl;
		}
		else
		{
			cout << " --- Гладиатор " << second->get_name() << " победил! --- " << endl;
		}
	}
};

 
/*
Реализовать иерархии классов "Гладиаторы", "Оружие гладиаторов" и "Защитные средства".
Промоделировать бой между гладиаторами.
*/


int main()
{
	setlocale(LC_ALL, "Russian");
	Gladiator max("Maximus");
	Helmet h;
	Greaves g;
	Sword sw;
	max.add_armor(&h);
	max.add_armor(&g);
	max.set_weapon(&sw);

	Gladiator hex("Hexus");
	Helmet h1;
	ChestPlate cp;
	Spear sp;
	hex.add_armor(&h1);
	hex.add_armor(&cp);
	hex.set_weapon(&sp);

	Fight f(&max, &hex);
	f.start_fight();

}