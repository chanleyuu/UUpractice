#pragma once
//#include "world.h"

class location
{
public:
	enum occupier { empty, ground, npc, player, chest, terrian, vegetation, weapon, wall, water, rock };

	location();

	location(occupier occ);

	occupier getoccupier() const;

	void setoccupier(occupier occ) const;

private:
	occupier occ_;
	bool passabletoground;
	bool passibletofly;
	
};

