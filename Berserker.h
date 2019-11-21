#pragma once
#include <string>
#include "rpgclass.h"

class Berserker : public rpgclass {
private:
	int rage;
public:
	Berserker();

	Berserker(std::string name, int health, int maxhealth, int level, race rrace, int rage);

	void berserk(rpgclass target);
	void shout(rpgclass target);
};