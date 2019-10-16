#pragma once

#include <string>

class armour {
public:
    armour();// Constructor
    
    enum armourtype { Helmet, Shirt, Shoes, Gloves, Legs, None };
    
    std::string getname() const;
    armourtype gettype() const;
    float getprotect() const;
    int getlevel() const;
    int getweight() const;
    int getdurability() const;
    
    void setname(std::string name);
    void settype(armourtype type);
    void setprotect(float protect);
    void setlevel(int level);
    void setweight(int weight);
    void setrange(int range);
    void setdurability(int durability);
    
private:
    std::string name_;
    armourtype type_;
    float protect_;
    int level_;
    int weight_;
    int range_;
    int durability_;
};
