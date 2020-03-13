#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "rpgclass.h"
#include "location.h"

class rpgclass;

class world {
private:
	int X_;
	int Y_;
	std::vector< std::vector<location> > loco_ ;
	std::vector<location> squares_;
    std::vector<rpgclass> characters_;
	//std::vector<std::vector<location>> map_;
	location* origin_ = &loco_[0][0];
	std::vector<int> ID;
public:
	world();

	world(int x, int y);

	world(std::string filepath);

	//void loadworld(std::string filepath);
	void saveworld(std::string filepath);
	bool move(int dir, rpgclass you);
	void changeloc(location& oldloc, location& newloc);
    void addcharactertoworld(rpgclass character, int x, int y);
    void addcharacter(rpgclass );
    std::vector<int> getlocation (location* loc, int index);//This functions is needed for saving and loading.
};
