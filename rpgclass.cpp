#include "rpgclass.h"

rpgclass::rpgclass(void) {
    setname("char");
    setclass("Peasant");
    sethealth(100);
    setmaxhealth(100);
    setlevel(1);
    setweapon( "Fist", weapon::Fist);
}


std::string rpgclass::getname() const {
    return name_;
}

std::string rpgclass::getclass() const {
    return rpgclass_;
}

int rpgclass::gethealth() const {
    return health_;
}

int rpgclass::getlevel() const {
    return level_;
}

////////////////////////////////////////////////////////////////////

void rpgclass::additem(std::string name) {
    item newitem;
//	if (mark >= 0 && mark <= 100) {
	newitem.setname(name);
	inventory_.push_back(newitem);
	
			//	mark_[mark_.size - 1].setmarks(mark);
}

int rpgclass::getvalue(std::string name) const {
	int index;
	for (index = 0; index < inventory_.size(); index++) {
		if (name == inventory_[index].getname()) {
			return inventory_[index].getvalue();
		}
	}
}

std::string rpgclass::getdescription(std::string name) const {
	int index;
	for (index = 0; index < inventory_.size(); index++) {
		if (name == inventory_[index].getname()) {
			return inventory_[index].getdescription();
		}
	}
}

void rpgclass::removeitem(std::string name) {
	int index;
	for (index = 0; index < inventory_.size(); index++) {
		if (name == inventory_[index].getname()) {
			inventory_.erase(inventory_.begin() + index);
		}
	}
}

////////////////////////////////////////////////////////////////////

void rpgclass::setname(std::string name) {
    name_ = name;
}

void rpgclass::setclass(std::string rclass) {
    rpgclass_ = rclass;
}

void rpgclass::sethealth(int health) {
    health_ = health;
}

void rpgclass::setlevel(int level) {
    level_ = level;
}

void rpgclass::setmaxhealth(int maxhealth) {
    maxhealth_ = maxhealth;
}

void rpgclass::setweapon(std::string name, weapon::weapontype type, 
                     float damage, int level,
                    int range, int weight,
                    int durability) {
    charweapon_.setname(name);
    charweapon_.settype(type);
    charweapon_.setdamage(damage);
    charweapon_.setlevel(level);
    charweapon_.setrange(range);
    charweapon_.setweight(weight);
    charweapon_.setdurability(durability);
}
