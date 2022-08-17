#pragma once

#include <string>
#include <vector>

//#include "world.h"

enum  occupier { empty, item, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

enum smallocc { none, weapon, ditem, chair, candle, lamp };

enum type { ground, air, water };

typedef struct location
{	
	//location();

    //location(occupier occ, type tp, int locx, int locy);

    int xlocation_;
    int ylocation_;
    
    std::vector<smallocc> smallocc_;
	occupier occ_;
	type tp_;
	//bool passabletoground;
	//bool passibletofly;
	
};

	char[] getoccupiers();

	occupier getoccupier() ;
    
    void setoccupier(occupier occ);

    smallocc getsmalloccupier(int index) ;
    
	void setsmalloccupier(int occ);

	void setsmalloccupier(std::string occ);

	void removesmalloccupier(int index);
        
    void setxlocation(int xloc);
    
    void setylocation(int yloc);

	int addsmalloccupier(smallocc socc);
    
    int getxlocation();
    
    int getylocation();

	type gettype() ;
    
	void settype(type tp);

	bool ispassibleground();

	bool ispassibleair();
