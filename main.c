#include <stdio>
//#include <random>
#include "world.h"
#include "location.h"
#include "rpgclass.h"
#include "item.h"
#include "weapon.h"

//void attack(rpgclass& a, rpgclass& b);

/*
float genrand(float min, float max) {
	std::random_device r;
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 eng(seed2);
	std::uniform_real_distribution<float> dist(min, max);
	return dist(eng);
} 

void attack(rpgclass& a, rpgclass& b) {
	float hit = genrand(0, 1);
	if (hit > 0.5) {
		b.sethealth(b.gethealth() - a.charweapon_.getdamage() / b.gettotalarmour());
	}
} */

int main(int argc, char** argv) {
	struct rpgclass me;
	struct weapon simple;
	struct item wine;
	printf("%s \n", simple.tostring());
	wine.setname("Wine");
	wine.setdescription("A fine vintage.");
	wine.setvalue(50);
	simple.setname("Simple Staff");
	simple.settype(weapontype::Staff);
	simple.setrange(3);
	me.setname("Harold");
	me.setweapon(simple);
    
    
	printf("Hello, %s \n", me.getname());
	

    printf("Oh No! \n"); 
	return 0;
}



