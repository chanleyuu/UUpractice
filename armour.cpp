#include "armour.h"

armour::armour(void) {
    setname("Naked");
    settype(None);
    setprotect(0.0);
    setlevel(1);
    setweight(0);
    setdurability(-1);
}


std::string armour::getname() const {
    return name_;
}

armour::armourtype armour::gettype() const {
    return type_;
}

float armour::getprotect() const {
    return protect_;
}

int armour::getlevel() const {
    return level_;
}

int armour::getweight() const {
    return weight_;
}

int armour::getdurability() const {
    return durability_;
}

//////////////////////////////////////////////////////////////////////////

void armour::setname(std::string name) {
     name_ = name;
}

void armour::settype(armourtype type) {
     type_ = type;
}

void armour::setprotect(float protect) {
    protect_ = protect;
}

void armour::setlevel(int level) {
    level_ = level;
}

void armour::setweight(int weight) {
    weight_ = weight;
}

void armour::setdurability(int durability) {
    durability_ = durability;
}
