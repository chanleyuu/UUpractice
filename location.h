#pragma once
//#include "world.h"

class location
{
public:
	enum occupier { empty, weapon, chest, vegetation, rock, wall, npc, player, tree, flyingplayer, portal };

	enum type { ground, air, water };
	location();

	location(occupier occ, type tp);

	occupier getoccupier() const;

	void setoccupier(occupier occ);

	type gettype() const;
	void settype(type tp);

	bool ispassibleground();

	bool ispassibleair();

private:
	occupier occ_;
	type tp_;
	//bool passabletoground;
	//bool passibletofly;
	
};

