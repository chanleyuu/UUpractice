#include <iostream>
#include <random>
#include "rpgclass.h"

#include "weapon.h"

float genrand(float min, float max) {
	std::random_device r;
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 eng(seed2);
	std::uniform_real_distribution<float> dist(min, max);
	return dist(eng);
}

void attack(rpgclass a, rpgclass b) {
	float hit = genrand(0, 1);
	if (hit > 0.5) {
		b.sethealth(b.gethealth() - a.charweapon_.getdamage() / b.gettotalarmour());
	}
}

int main(int argc, char** argv) {
	rpgclass me;
	weapon simple;
	simple.setname("Simple Staff");
	simple.settype(weapon::Staff);
	simple.setrange(3);
	me.setname("Harold");
	me.setclass("Wizard");
	me.setweapon(simple);
	std::cout << "Hello, " << me.getname() << std::endl;
	
	rpgclass* classes{new rpgclass[500] };
    delete[] classes;
    std::cout << "Oh No!" << std::endl; 
	return 0;
}



