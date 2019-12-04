#include "world.h"

world::world() : X_{ 100 }, Y_ { 100 }  {
	squares_.resize(X_);
	for (int i = 0; i < Y_; i++) {
		loco_.push_back(squares_);
	}

}


world::world(int x, int y) : X_{ x }, Y_{ y }  {
	squares_.resize(X_);
	for (int i = 0; i < Y_; i++) {
		loco_.push_back(squares_);
	}

}


bool world::move(int dir, rpgclass you)
{
	location* loc = you.getlocation();
	location* newloc = nullptr;

	switch (dir) {
	case 1: 
		if ((loc - origin_) % 101 != 0) {
			newloc = loc - 1;
			if (newloc->getoccupier() == location::occupier::empty) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
			}
		}
		break;
	case 2:
		if (loc - origin_ > 100) {
			newloc = loc - 100;
			if (newloc->getoccupier() == location::occupier::empty) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
			}
		}
		break;
	case 3:
		if ((loc - origin_) % 100 != 0) {
			newloc = loc + 1;
			if (newloc->getoccupier() == location::occupier::empty) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
			}
		}
		break;
	case 4:
		if ((loc - origin_) <= 9900) {
			newloc = loc + 100;
			if (newloc->getoccupier() == location::occupier::empty) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
			}
		}
		break;
	default :
		you.setrotation(1);
		break;
	}

	loc = nullptr;
	newloc = nullptr;
	delete loc;
	delete newloc;

	return false;
}

void world::changeloc(location& oldloc, location& newloc) {
	oldloc.setoccupier(location::occupier::empty);
	newloc.setoccupier(location::occupier::player);
}

void world::loadworld(std::string filepath) {
	std::string temp;
	std::ifstream worldfile{ filepath, std::ios::in };

	if (!worldfile) {
		exit(EXIT_FAILURE);
	}

	std::getline(worldfile, temp);
	X_ = std::stoi(temp);
	
	std::getline(worldfile, temp);
	Y_ = std::stoi(temp);

	while (!worldfile.eof()) {
		std::getline(worldfile, temp);
	}
}
