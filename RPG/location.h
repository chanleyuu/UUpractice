#pragma once
class location
{
	location();

	location(int locx, int locy);

	enum occupier { empty, npc, player, chest, terrian, vegetation, weapon, wall, water };

	occupier getoccupier() const;
	int getlocationx() const;
	int getlocationy() const;

	void setoccupier(occupier occ) const;
	void setlocationx(int locx);
	void setlocationy(int locy);

private:
	occupier occ_;

	int locx_;
	int locy_;

	
};

