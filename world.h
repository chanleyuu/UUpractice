#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "rpgclass.h"
class rpgclass;

class world {
private:
	int squares[100][100];
	std::vector<int> ID;
public:
	void move(int dir, int speed, rpgclass you);
};
