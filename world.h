#pragma once

//#include <string>
#include <fstream>
//#include <vector>
#include <stdio>

#include "rpgclass.h"
#include "location.h"

//class rpgclass;

typedef struct world {

	int X_;
	int Y_;
	typedef struct loco_ ;
	std::vector<location> squares_;
    std::vector<rpgclass> characters_;
	//std::vector<std::vector<location>> map_;
	location* origin_ = &loco_[0][0];
	std::vector<int> ID;
	
	//world();

	//world(int x, int y);

	//world(std::string filepath);

    //~world();//destructor 
    
	//void loadworld(std::string filepath);
	
   // std::vector<int> getlocations (location* loc);//This functions is needed for saving and loading.
};

void world_saveworld(char[] filepath);
bool world_move(int dir, rpgclass you);
void world_changeloc(location& oldloc, location& newloc);
void world_addcharacter(rpgclass character, int x, int y);
//void addcharacter(rpgclass );
int& world_getlocation(int x, int y);
