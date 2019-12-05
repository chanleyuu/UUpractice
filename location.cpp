#include "location.h"

location::location() : occ_{ empty }, tp_{ ground } {

}

location::location(occupier occ, type tp) : occ_{ occ }, tp_{ tp } {

}

location::occupier location::getoccupier() const {
	return occ_;
}

void location::setoccupier(occupier occ) {
	occ_ = occ;
}

location::type location::gettype() const {
	return tp_;
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
