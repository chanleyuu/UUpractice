#include "weapon.h"

weapon::weapon(void) {
    setname("Fist");
    settype(Fist);
    setdamage(1.0);
    setlevel(1);
    setrange(0);
    setweight(0);
    setdurability(-0);
}


std::string weapon::getname() const {
    return name_;
}

weapon::weapontype weapon::gettype() const {
    return type_;
}

float weapon::getdamage() const {
    return damage_ * (1 * ((level_ - 1) / 10));
}

int weapon::getlevel() const {
    return level_;
}

int weapon::getweight() const {
    return weight_;
}

int weapon::getrange() const {
    return range_;
}

int weapon::getdurability() const {
    return durability_;
}

//////////////////////////////////////////////////////////////////////////

void weapon::setname(std::string name) {
     name_ = name;
}

void weapon::settype(weapontype type) {
     type_ = type;
}

void weapon::setdamage(float damage) {
    damage_ = damage;
}

void weapon::setlevel(int level) {
    level_ = level;
}

void weapon::setweight(int weight) {
    weight_ = weight;
}

void weapon::setrange(int range) {
    range_ = range;
}

void weapon::setdurability(int durability) {
    durability_ = durability;
}
