#pragma once

#include <string>
#include <vector>

//#include "world.h"

enum class occupier { empty, item, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

enum class type { ground, air, water };

class location
{
public:
	

	location();

	location(occupier occ, type tp);

	std::string getoccupiers() const;

	occupier getoccupier() const;

	void setoccupier(int occ);

	void setoccupier(std::string occ);

	void removeoccupier(int index);

	int addoccupier(occupier occ);

	location::type gettype() const;
	void settype(type tp);

	bool ispassibleground();

	bool ispassibleair();

private:
    int xlocation;
    int ylocation;
    
	occupier occ_;
	type tp_;
	//bool passabletoground;
	//bool passibletofly;
	
};

