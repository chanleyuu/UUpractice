#include "rpgclass.h"
#include <random>

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
	weapon fist("Fist", "Bare Hands", 0, (weapon::weapontype) 6, 1.2f, 1,
		1, 0, -1);
    this->setweapon(fist);
}

rpgclass::~rpgclass()
{
    delete location_;
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

int rpgclass::getstregnth() const {
	return strength_;
}

int rpgclass::getfaith() const {
	return faith_;
}

int rpgclass::getexp() const {
	return exp_;
}

int rpgclass::getintelligence() const {
	return intelligence_;
}

int rpgclass::getdexterity() const {
	return dexterity_;
}

int rpgclass::getendurance() const {
	return endurance_;
}

location* rpgclass::getlocation() {

	return location_;
}

int rpgclass::getstanima() const {
	return stanima_;
}

int rpgclass::getrotation() const {
	return rotation_;
}

rpgclass::race rpgclass::getrace() const {
	return thisrace_;
}

std::string rpgclass::getracename() const {
	return racenames[thisrace_];
}

float rpgclass::gettotalarmour() {
	float total = 0.0;
	for (int i = 0; i < armour_.size(); i++) {
		total += armour_[i].getprotect();
	}
	return total;
}

int rpgclass::getoccindex() const {
	return occindex_;
}
////////////////////////////////////////////////////////////////////

void rpgclass::additem(std::string name) {
    item newitem;
//	if (mark >= 0 && mark <= 100) {
	newitem.setname(name);
	inventory_.push_back(newitem);
	weight_ += newitem.getweight();
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

void rpgclass::setlocation(location *loc) {
	location_ = loc;
}

void rpgclass::setfaith(int faith) {
	faith_ = faith;
}

void rpgclass::eat(item food) {
	removeitem(food.getname());
}

void rpgclass::setexp(int exp) {
	exp_ = exp;
}

void rpgclass::setstregnth(int strength) {
	strength_ = strength;
}

void rpgclass::setinelligence(int intel) {
	intelligence_ = intel;
}

void rpgclass::setoccindex(int index) {
	occindex_ = index;
}

void rpgclass::setdexterity(int dex) {
	dexterity_ = dex;
}

void rpgclass::setendurance(int end) {
	endurance_ = end;
}


void rpgclass::setstanima(int stan) {
	stanima_ = stan;
}

void rpgclass::setrotation(int spin) {
	rotation_ = spin;
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
	location* loc = this->getlocation();
    charweapon_.setlocation(loc);
    
	charweapon_.setname("Fists");
	charweapon_.settype(weapon::Fist);
	charweapon_.setdamage(1.0);
	charweapon_.setlevel(this->getlevel());
	charweapon_.setrange(0);
	charweapon_.setweight(0);
	charweapon_.setdurability(-1);

	;
}

void rpgclass::setstate(state st) {
	if (thisstate_[st] == false) {
		thisstate_[st] = true;
	}
	else {
		thisstate_[st] = false;
	}

}

bool rpgclass::getstate(state st) {
	return thisstate_[st];
}

void rpgclass::sleep() {
	health_ += 10;
}

void rpgclass::walk(world w) {
	w.move(rotation_, *this);
}

void rpgclass::attack(rpgclass& target) {
	if (genrand(0.0f, 1.0f) > (float)dexterity_ / 100.0f) {
		target.sethealth(target.gethealth() - charweapon_.getdamage() / target.gettotalarmour());
	}
}

float rpgclass::genrand(float min, float max) {
	std::random_device r;
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 eng(seed2);
	std::uniform_real_distribution<float> dist(min, max);
	return dist(eng);
}

void rpgclass::defend() {
	setstate(defending);
}
