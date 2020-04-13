#include "weapon.h"

weapon::weapon() : item ("Fist", "Bare hands", 0)  {
    settype(weapontype::Fist);
    setdamage(1.0);
    setlevel(1);
    setrange(0);
    setweight(0);
    setdurability(-0);
}

weapon::weapon(std::string name, std::string desc, int value,
				weapontype wep, float damage, int level,
				int range, int weight, int durability)  
	: item(name, desc, value), type_{ wep }, damage_{ damage }, level_{ level }, range_{ range }, weight_{ weight }, durability_{ durability } {
}

/*
std::string weapon::getname() const {
    return name_;
} */

weapontype weapon::gettype() const {
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
	case weapontype::Longsword: type = "Longsword";
		break;
    case weapontype::Bastardsword: type = "Bastardsword";
		break;
	case weapontype::Spear: type = "Spear";
		break;
	case weapontype::Mace: type = "Mace";
		break;
	case weapontype::Bow: type = "Bow";
		break;
	case weapontype::Staff: type = "Staff";
		break;
    case weapontype::Fist: type = "Fist";
		break;
	default: type = "Unknown";
		break;
	}

	std::string out = "Name: " + this->getname() + "\n Description: " + this->getdescription() + "\n Value: " + std::to_string(this->getvalue()) +
		"\n Type: " + type + "\n Damage: " + std::to_string(damage_) + "\n Range: " + std::to_string(range_) + "\n Weight: " + std::to_string(weight_);
	return out;
}
