#pragma once

//#include <string>
//#include <vector>

#include "world.h"
#include "weapon.h"
#include "item.h"
#include "armour.h"
#include "location.h"

//class world;

typedef struct rpgclass {

	enum state { idle, running, walking, stunned, enchanted, burning, poisoned, frozen, sleeping, defending, dead };
	const char[][] statenames { "idle", "running", "walking", "stunned", "enchanted", "burning", "poisoned", "frozen", "sleeping", "defending", "dead" };

	enum race { Orc, Elf, Undead, Ogre, Human, Demon, Zorbgnak, Scavenger, Dwarf, Witch };
	const char[][] racenames{ "Orc", "Elf", "Undead", "Ogre", "Human", "Demon", "Zorbgnak", "Scavenger", "Dwarf", "Witch" };

    rpgclass(); //Default Constructor
    rpgclass(std::string name, int health, int maxhealth, int level, race rrace);

    char* getname() const;
    char* getclass() const;
	char* getracename() const;
    int gethealth() const;
    int getlevel() const;
	int getstregnth() const;
	int getfaith() const;
	int getexp() const;
	int getintelligence() const;
	int getdexterity() const;
	int getendurance() const;
    location* getlocation();
	int getstanima() const;
	int getrotation() const;
	int getoccindex() const;
	race getrace() const;
    world* getworld() const;

	float gettotalarmour();
    weapon charweapon_;

    int getvalue(std::string name) const;
    std::string getdescription(std::string name) const;

    void additem(std::string name);
    void removeitem(std::string name);

	void equiparmour(armour a);
	void unequiparmour(std::string name);

    void setname(std::string name);
    void sethealth(int health);
    void setlevel(int level);
    void setmaxhealth(int maxhealth);
    void setweapon(weapon w);
	void dropweapon(world& w);
	void eat(item food);
	void addspell();
	void setrace(race rrace);
	void setstate(state st);
	void setfaith(int faith);
	void setexp(int exp);
	void setstregnth(int strength);
	void setinelligence(int intel);
	void setdexterity(int dex);
	void setendurance(int end);
	void setlocation(location *loc);
	void setstanima(int stan);
	void setrotation(int spin);
	void setoccindex(int index);
    void setworld(world* w);

	virtual void attack(rpgclass& target);
	virtual void sleep();
	void defend();
	void walk();
	bool getstate(state st);

	float genrand(float min, float max);


	race thisrace_;
	bool thisstate_[11];

    std::string name_;
    std::string rpgclass_;
	int weight_;
    int health_;
    int maxhealth_;
    int level_;
	int strength_;
	int intelligence_;
    int exp_;
	int faith_;
	int dexterity_;
	int endurance_;
	int stanima_;
    struct* inventory_;
	struct* armours;

	int occindex_;
    location* location_;
    world* world_;
    int rotation_;
};
