#pragma once

#include <string>
#include <vector>

//#include "world.h"

class location
{
public:
	enum occupier { empty, item, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

    enum smallocc { none, weapon, ditem, chair, candle, lamp };
    
	enum type { ground, air, water };
	location();

	location(occupier occ, type tp, int xloc, int yloc);

	std::string getoccupiers() const;

	occupier getoccupier() const;
    
    void setoccupier(occupier occ);

    smallocc getsmalloccupier(int index) const;
    
	void setsmalloccupier(int occ);

	void setsmalloccupier(std::string occ);

	void removesmalloccupier(int index);
        
    void setxlocation(int xloc);
    
    void setylocation(int yloc);

	int addsmalloccupier(smallocc socc);
    
    int getxlocation();
    
    int getylocation();

	location::type gettype() const;
    
	void settype(type tp);

	bool ispassibleground();

	bool ispassibleair();

private:
    int xlocation_;
    int ylocation_;
    
    std::vector<smallocc> smallocc_;
	occupier occ_;
	type tp_;
	//bool passabletoground;
	//bool passibletofly;
	
};

