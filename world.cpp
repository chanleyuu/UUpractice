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

world::world(std::string filepath) {
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
		for (int e = 0; e < Y_; e++) {

			loco_.push_back(squares_);

			for (int i = 0; i < X_; i++) {
				int num1;
				int num2;
				std::getline(worldfile, temp, ',');
				num1 = std::stoi(temp);
				std::getline(worldfile, temp, ',');
				num2 = std::stoi(temp);
				loco_[e].push_back(location((location::occupier)num1, (location::type) num2));
			}
		}

	}

	worldfile.close();
}

void world::saveworld(std::string filepath) {
    std::ofstream worldfile{ filepath, std::ios::out };
    
    if (!worldfile) {
		exit(EXIT_FAILURE);
	}
	
	
	if (worldfile.is_open()){
        
        worldfile << X_ << std::endl;
        worldfile << Y_ << std::endl;
        
        for (int i = 0; i < loco_.size(); i++) {
            for (int e = 0; e < loco_[i].size(); e++){
				worldfile << loco_[i][e].getoccupier();
				worldfile << ",";
				worldfile << loco_[i][e].gettype();
				worldfile << ",";
            }
			worldfile << "\n";
        }
        
    }
	worldfile.close();
}
