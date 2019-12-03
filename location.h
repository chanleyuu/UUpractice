#pragma once
//#include "world.h"

class location
{
public:
	enum occupier { ground, weapon, water, empty, chest, terrian, vegetation, rock, wall, npc, player, tree, flyingplayer };

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

