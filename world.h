#pragma once

//#include <string>
#include <fstream>
//#include <vector>
#include <stdio>
#include <stdbool.h>

#include "rpgclass.h"
#include "location.h"

//class rpgclass;

typedef struct world {

	int X_;
	int Y_;
	typedef struct location* loco;
	loco* squares_;
    rpgclass characters_;
	//std::vector<std::vector<location>> map_;
	location* origin_ = *squares_;
	std::vector<int> ID;
	
	//world();

	//world(int x, int y);

	//world(std::string filepath);

    //~world();//destructor 
    
	//void loadworld(std::string filepath);
	
   // std::vector<int> getlocations (location* loc);//This functions is needed for saving and loading.
};

void world_init(world w, int x, int y);
void world_saveworld(char[] filepath);
bool world_move(int dir, rpgclass you);
void world_changeloc(location& oldloc, location& newloc);
void world_addcharacter(rpgclass character, int x, int y);
//void addcharacter(rpgclass );
int& world_getlocation(int x, int y);
