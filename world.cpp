#include "world.h"

world::world() : X_{ 100 }, Y_ { 100 }  {

	for (int i = 0; i < Y_; i++) {
        for (int e = 0; e < X_; e++){
            location L(e, i);
            L.settype(location::ground);
            L.setoccupier(location::empty);
            squares_.push_back(L);
        }
		loco_.push_back(squares_);
		squares_.clear();
	}

}


world::world(int x, int y) : X_{ x }, Y_{ y }  {
	//squares_.resize(X_);

	for (int i = 0; i < Y_; i++) {
        for (int e = 0; e < X_; e++){
            location L(e, i);
            L.settype(location::ground);
            L.setoccupier(location::empty);
            squares_.push_back(L);
        }
		loco_.push_back(squares_);
		squares_.clear();
	}

}


bool world::move(int dir, rpgclass you)
{
	location* loc = you.getlocation();
	location* newloc = nullptr;
	int index = you.getoccindex();

    //Switch case in based on direction
	switch (dir) {
	case 1:
		if ((loc - origin_) % X_ + 1 != 0) {
			newloc = loc - 1;
			if (newloc->ispassibleground() == true) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
				loc->setoccupier(location::empty);
				newloc->setoccupier(location::player);
				//you.setoccindex(index);
			}
		}
		break;
	case 2:
		if (loc - origin_ > X_) {
			newloc = loc - X_;
			if (newloc->ispassibleground() == true) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
				loc->setoccupier(location::empty);
				newloc->setoccupier(location::player);
				//you.setoccindex(index);
			}
		}
		break;
	case 3:
		if ((loc - origin_) % X_ != 0) {
			newloc = loc + 1;
			if (newloc->ispassibleground() == true) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
				loc->setoccupier(location::empty);
				newloc->setoccupier(location::player);
				//you.setoccindex(index);
			}
		}
		break;
	case 4:
		if ((loc - origin_) <= X_ * Y_ - X_) {
			newloc = loc + 100;
			if (newloc->ispassibleground() == true) {
				changeloc(*loc, *newloc);
				you.setlocation(newloc);
				loc->setoccupier(location::empty);
				newloc->setoccupier(location::player);
				//you.setoccindex(index);
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
				loco_[e].push_back(location((location::occupier)num1, (location::type) num2, i, e));
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
				worldfile << loco_[i][e].getoccupiers();
				worldfile << ",";
				worldfile << loco_[i][e].gettype();
				worldfile << ",";
            }
			worldfile << "\n";
        }

        
        for (int i = 0; i < loco_.size(); i++) {
            
        }
    }
	worldfile.close();
}

void world::addcharactertoworld(rpgclass character, int x, int y) {

    if (x < this-> X_ && y < this-> Y_) {
        if (loco_[y][x].getoccupier() == 0) {
            loco_[y][x].setoccupier(location::player);
            character.setlocation(&loco_[y][x]);
        }
    }
}

/*
std::vector<int> world::getlocations(location* loc) {
    std::vector<int> out;
    out.push_back(loc->getxlocation());
    out.push_back(loc->getylocation());
    
    return out;
} */

