#include "location.h"

location::location() : tp_{ type::ground } {

}

location::location(occupier occ, type tp) : occ_{ occ }, tp_{ tp } {

}

occupier location::getoccupier(int index) const {
	return occ_[index];
}

void location::setoccupier(std::string occ) {
	int begin = 0;
	int current = occ.find('|');

	while (current != std::string::npos) {
		occ_.push_back((occupier)std::stoi(occ.substr(begin, current - 1)));
		begin = current;
		current = occ.find('|', begin);
	}
	
}

std::string location::getoccupiers() const {
	std::string out = std::to_string((int) occ_[0]);
	for (int i = 1; i < occ_.size(); i++) {
		//while ((int)occ_[i] >= pow)
		//	pow *= 10;
		out = out + std::to_string(occ_[0]) + "|";
	}
	return out;
}

int location::addoccupier(occupier occ) {
	//returns index of occupier
	occ_.push_back(occ);
	return occ_.size();
}

void location::removeoccupier(int index) {
	occ_.erase(occ_.begin() + index);
}

location::type location::gettype() const {
	return tp_;
}

void location::settype(type tp) {
	tp_ = tp;
}

bool location::ispassibleground() {

	for (int i = 0; i < occ_.size(); i++) {
		if (occ_[i] == empty || occ_[i] == item || occ_[i] == vegetation || occ_[i] == flyingplayer) {
			return true;
		}
	}
	return false;
}

bool location::ispassibleair() {
	for (int i = 0; i < occ_.size(); i++) {
		if (occ_[i] == wall || occ_[i] == tree || occ_[i] == flyingplayer) {
			return false;
		}
	}
	return true;
}
