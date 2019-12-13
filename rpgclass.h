#pragma once

#include <string>
#include <vector>

#include "weapon.h"
#include "item.h"
#include "armour.h"
#include "world.h"
#include "location.h"

class rpgclass {
public:
	enum state { idle, running, walking, stunned, enchanted, burning, poisoned, frozen, sleeping, defending, dead };
	const std::vector<std::string> statenames { "idle", "running", "walking", "stunned", "enchanted", "burning", "poisoned", "frozen", "sleeping", "defending", "dead" };

	enum race { Orc, Elf, Undead, Ogre, Human, Demon, Zorbgnak, Scavenger, Dwarf, Witch };
	const std::vector<std::string> racenames{ "Orc", "Elf", "Undead", "Ogre", "Human", "Demon", "Zorbgnak", "Scavenger", "Dwarf", "Witch" };

    rpgclass(); //Default Constructor 
    rpgclass(std::string name, int health, int maxhealth, int level, race rrace);
    
    ~rpgclass();
    
    std::string getname() const;
    std::string getclass() const;
	std::string getracename() const;
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
	void dropweapon(world w);
	void eat(item food);
	void addspell();
	void setrace(race rrace);
	void setstate(state st);
    void setlocation(location* loc);
	void setfaith(int faith);
	void setexp(int exp);
	void setstregnth(int strength);
	void setinelligence(int intel);
	void setdexterity(int dex);
	void setendurance(int end);
	void setlocation(int &loc);
	void setstanima(int stan);
	void setrotation(int spin);
	void setoccindex(int index);
	void setrace(race r);

	virtual void attack(rpgclass& target);
	virtual void sleep();
	void defend();
	void walk(world w);
	bool getstate(state st);

	float genrand(float min, float max);

	

private:
	
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
    std::vector<item> inventory_;
	std::vector<armour> armour_;
    
	int occindex_;
    location* location_;
    int rotation_;
};
