#pragma once

#include <string>

class weapon {
public:
    
    enum weapontype { Longsword, Bastardsword, Spear, Mace, Bow, Staff, Fist };
    
    weapon();// Constructor
    
    std::string getname() const;
    weapontype gettype() const;
    float getdamage() const;
    int getlevel() const;
    int getweight() const;
    int getrange() const;
    int getdurability() const;
    
    void setname(std::string name);
    void settype(weapontype type);
    void setdamage(float damage);
    void setlevel(int level);
    void setweight(int weight);
    void setrange(int range);
    void setdurability(int durability);
    
private:
    
    std::string name_;
    weapontype type_;
    float damage_;
    int level_;
    int weight_;
    int range_;
    int durability_;
};
