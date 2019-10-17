#pragma once

#include <string>
#include <vector>

#include "weapon.h"
#include "item.h"
#include "armour.h"

class rpgclass {
public:
    rpgclass(); //Constructor 
    
    std::string getname() const;
    std::string getclass() const;
    int gethealth() const;
    int getlevel() const;
	float gettotalarmour();
    weapon charweapon_;
    
    int getvalue(std::string name) const;
    std::string getdescription(std::string name) const;
    
    void additem(std::string name);
    void removeitem(std::string name);

	void equiparmour(armour a);
	void unequiparmour(std::string name);

    void setname(std::string name);
    void setclass(std::string rclass);
    void sethealth(int health);
    void setlevel(int level);
    void setmaxhealth(int maxhealth);
    void setweapon(weapon w);
	void dropweapon();
    

private:
    std::string name_;
    std::string rpgclass_;
    int health_;
    int maxhealth_;
    int level_;
    std::vector<item> inventory_;
	std::vector<armour> armour_;
};
