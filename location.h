#pragma once
//#include "world.h"

class location
{
public:
	enum occupier { empty, weapon, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

	enum type { ground, air, water };
	location();

	location(occupier occ);

	occupier getoccupier() const;

	void setoccupier(occupier occ);

	bool ispassibleground();

	bool ispassibleair();

private:
	occupier occ_;
	//bool passabletoground;
	//bool passibletofly;
	
};

