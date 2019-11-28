#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "rpgclass.h"
#include "location.h"

class rpgclass;

class world {
private:
	location squares_[100][100];
	location* origin_ = &squares_[0][0];
	std::vector<int> ID;
public:
	bool move(int dir, rpgclass you);
	void changeloc(location& oldloc, location& newloc);
};
