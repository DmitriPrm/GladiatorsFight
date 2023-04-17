
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
#include <iomanip> 

using namespace std;

void sleep(int msec) 
{
	std::chrono::milliseconds time(msec);
	std::this_thread::sleep_for(time);
}

class Weapon
{
protected:
	int damage;
public:
	Weapon() { }
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
		if (!damage) throw exception("Damage must be more than zero!");
		this->damage = damage;
	}
};

class Armor
{
protected:
	int armor;
	string type;
public:
	Armor() { }
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
		if (!armor) throw exception("Armor must be more than zero!");
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
	ChestPlate() : Armor() { type = "ChestPlate"; armor = 25; }
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
	Shield() : Armor() { type = "Shield"; armor = 25; }
};

class Gladiator
{
	string name;
	bool isAlive = true;
	int health;
	Weapon* weapon;
	map<string, Armor*> armorList;
	int armor;
	int skill;
public: 
	Gladiator(string name, int skill)
	{
		if (!skill) throw exception ("Skill must be more than zero!");
		this->name = name;
		armor = 0;
		health = 100;
		this->skill = skill;
	}
	string get_name()
	{
		return name;
	}
	void set_name(string name)
	{
		this->name = name;
	}
	int get_skill()
	{
		return skill;
	}
	void set_skill(int skill)
	{
		if (!skill) throw exception("Skill must be more than zero!");
		this->skill = skill;
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
		if (!health) throw exception("Health must be more than zero!");
		this->health = health;
	}
	void set_weapon(Weapon* weapon)
	{
		if (!weapon) throw exception("Wrong weapon!");
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
		bool miss = rand() % 10 < skill / 10;
		bool superHit = rand() % 10 < skill / 100;
		if (!miss)
		{
			return;
		}
		if (superHit)
		{
			int superHitCount = rand() % 5;
			for (int i = 0; i < superHitCount; i++)
			{
				hit(gl);
			}
			return;
		}
		if (armor)
		{
			if (gl->get_armor() - weapon->get_damage() <= 0)
			{
				armor = 0;
				return;
			}
			gl->reset_armor(-weapon->get_damage());
		}
		else
		{
			if (gl->health - weapon->get_damage() <= 0)
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
		cout << setw(3) << right << first->get_armor() << "/" << setw(3) <<  left << first->get_health() << " | "
			<< setw(3) << right << second->get_armor() << "/" << setw(3) << left << second->get_health() << endl;
	}
	void start_fight()
	{
		cout << setw(8) << first->get_name() << setw(8) << second->get_name() << endl;
		cout << setw(8) << "ARMOR/HP " << setw(8) << "ARMOR/HP" << endl;
		print_hp();
		sleep(500);
		while (first->get_isAlive() && second->get_isAlive())
		{
			first->hit(second);
			print_hp();
			sleep(500);
			if (!second->get_isAlive())
			{
				cout << "Гладиатор " << second->get_name() << " мертв!" << endl;
				break;
			}
			second->hit(first);
			print_hp();
			sleep(500);
		}
		if (first->get_isAlive())
		{
			cout << endl << " --- Гладиатор " << first->get_name() << " победил! --- " << endl;
		}
		else
		{
			cout << endl << " --- Гладиатор " << second->get_name() << " победил! --- " << endl;
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
	Gladiator max("Maximus", 100);
	Helmet h;
	ChestPlate cp;
	Greaves g;
	Sword sw;
	max.add_armor(&h);
	max.add_armor(&cp);
	max.add_armor(&g);
	max.set_weapon(&sw);

	Gladiator hex("Hexus", 100);
	Helmet h1;
	ChestPlate cp1;
	Spear sp;
	hex.add_armor(&h1);
	hex.add_armor(&cp1);
	hex.set_weapon(&sp);

	Fight f(&max, &hex);
	f.start_fight();

}