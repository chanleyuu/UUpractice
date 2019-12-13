#pragma once

#include <string>
#include <vector>

//#include "world.h"

class location
{
public:
	enum occupier { empty, item, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

	enum type { ground, air, water };
	location();

	location(occupier occ, type tp);

	std::string getoccupiers() const;

	occupier getoccupier(int index) const;

	void setoccupier(int occ);

	void setoccupier(std::string occ);

	void removeoccupier(int index);

	int addoccupier(occupier occ);

	location::type gettype() const;
	void settype(type tp);

	bool ispassibleground();

	bool ispassibleair();

private:
	std::vector<occupier> occ_;
	type tp_;
	//bool passabletoground;
	//bool passibletofly;
	
};

