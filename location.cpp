#include "location.h"

location::location() : occ_{ occupier::empty }, tp_{ type::ground } {

}

location::location(occupier occ, type tp) : occ_{ occ }, tp_{ tp } {

}

location::occupier location::getoccupier(int index) const {
	return occ_[index];
}

long location::getoccupiers() const {
	long out = (int) occ_[0];
	for (int i = 1; i < occ_.size(); i++) {
		int pow = 100;
		//while ((int)occ_[i] >= pow)
		//	pow *= 10;
		out = out * pow + (int) occ_[i];
	}
	return out;
}

int location::addoccupier(occupier occ) {
	//returns index of occupier
	occ_.push_back(occ);
	return occ_.size();
}

location::type location::gettype() const {
	return tp_;
}

void location::settype(type tp) {
	tp_ = tp;
}

bool location::ispassibleground() {
	if (occ_ == empty) {
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
