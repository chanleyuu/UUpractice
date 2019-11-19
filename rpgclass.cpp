#include "rpgclass.h"

rpgclass::rpgclass(void) {
    setname("char");
  //  setclass("Peasant");
    sethealth(100);
    setmaxhealth(100);
    setlevel(1);
    setweapon( charweapon_ );
}

rpgclass::rpgclass(std::string name, int health, int maxhealth, int level, race rrace) {
    this->name_ = name;
    this->thisrace_ = rrace;
    this->health_ = health;
    this->maxhealth_ = maxhealth;
    this->level_ = level;
	weapon fist;
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


float rpgclass::gettotalarmour() {
	float total = 0.0;
	for (int i = 0; i < armour_.size(); i++) {
		total += armour_[i].getprotect();
	}
	return total;
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
	return 0;
}

std::string rpgclass::getdescription(std::string name) const {
	int index;
	for (index = 0; index < inventory_.size(); index++) {
		if (name == inventory_[index].getname()) {
			return inventory_[index].getdescription();
		}
	}
	return "Could not find item!";
}

void rpgclass::removeitem(std::string name) {
	int index;
	for (index = 0; index < inventory_.size(); index++) {
		if (name == inventory_[index].getname()) {
			inventory_.erase(inventory_.begin() + index);
		}
	}
}


void rpgclass::equiparmour(armour a) {
	int index;
	for (index = 0; index < armour_.size(); index++) {
		if (a.gettype() == armour_[index].gettype()) {
			armour_[index].remove();
			armour_.erase(armour_.begin() + index);
		}
	}
	armour_.push_back(a);
}

void rpgclass::unequiparmour(std::string name) {
	int index;
	for (index = 0; index < armour_.size(); index++) {
		if (name == armour_[index].getname()) {
			armour_[index].remove();
			armour_.erase(armour_.begin() + index);
		}
	}
}
////////////////////////////////////////////////////////////////////

void rpgclass::setname(std::string name) {
    name_ = name;
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

void rpgclass::setrace(race rrace) {
	thisrace_ = rrace;
}

void rpgclass::setweapon(weapon w) {
	//dropweapon();
    charweapon_.setname(w.getname());
    charweapon_.settype(w.gettype());
    charweapon_.setdamage(w.getdamage());
    charweapon_.setlevel(w.getlevel());
    charweapon_.setrange(w.getrange());
    charweapon_.setweight(w.getweight());
    charweapon_.setdurability(w.getdurability());
}

void rpgclass::dropweapon() {
	/*
	"Some code placing weapon in game world"
	*/
	charweapon_.setname("Fists");
	charweapon_.settype(weapon::Fist);
	charweapon_.setdamage(1.0);
	charweapon_.setlevel(this->getlevel());
	charweapon_.setrange(0);
	charweapon_.setweight(0);
	charweapon_.setdurability(-1);
}
