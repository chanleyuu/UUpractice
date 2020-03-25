#pragma once

#include <string>
#include "item.h"


class weapon :
		public item {
public:
    
    enum weapontype { Longsword, Bastardsword, Spear, Mace, Bow, Staff, Fist };
    
    weapon();// Constructor
    
	weapon(std::string name, std::string desc, int value,
		weapon::weapontype wep, float damage, int level,
		int range, int weight, int durability);

 //   std::string getname() const;
    weapontype gettype() const;
    float getdamage() const;
    int getlevel() const;
    int getweight() const;
    int getrange() const;
    int getdurability() const;
    
   // void setname(std::string name);
    void settype(weapontype type);
    void setdamage(float damage);
    void setlevel(int level);
    void setweight(int weight);
    void setrange(int range);
    void setdurability(int durability);
    

	virtual std::string tostring();
private:
    
    weapontype type_;
    float damage_;
    int level_;
    int range_;
    int weight_;
    int durability_;
};
