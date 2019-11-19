#include "weapon.h"

weapon::weapon(void) : item ("Fist", "Bare hands", 0)  {
    settype(Fist);
    setdamage(1.0);
    setlevel(1);
    setrange(0);
    setweight(0);
    setdurability(-0);
}

weapon::weapon(std::string name, std::string desc, int value,
				weapon::weapontype wep, float damage, int level,
				int range, int weight, int durability)  
	: item(name, desc, value), type_{ wep }, damage_{ damage }, level_{ level }, range_{ range }, weight_{ weight }, durability_{ durability } {
}

/*
std::string weapon::getname() const {
    return name_;
} */

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
/*
void weapon::setname(std::string name) {
     name_ = name;
}*/

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

std::string weapon::tostring(){
	std::string type;
	switch (type_) {
	case 0: type = "Longsword";
		break;
	case 1: type = "Bastardsword";
		break;
	case 2: type = "Spear";
		break;
	case 3: type = "Mace";
		break;
	case 4: type = "Bow";
		break;
	case 5: type = "Staff";
		break;
	case 6: type = "Fist";
		break;
	}

	std::string out = "Name: " + this->getname() + "\n Description: " + this->getdescription() + "\n Value: " + std::to_string(this->getvalue()) +
		"\n Type: " + type + "\n Damage: " + std::to_string(damage_) + "\n Range: " + std::to_string(range_) + "\n Weight: " + std::to_string(weight_);
	return out;
}
