#include "location.h"

location::location() {

}

location::location(occupier occ) : occ_{ occ } {

}

location::occupier location::getoccupier() const {
	return occ_;
}

void location::setoccupier(occupier occ) {
	occ_ = occ;
}

bool location::ispassibleground() {
	if (occ_ < empty) {
		return true;
	}
	return false;
}

bool location::ispassibleair() {
	if (occ_ == wall || occ_ == tree || occ_ == flyingplayer) {
		return false;
	}
	return true;
}
