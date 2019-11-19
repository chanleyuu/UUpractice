#include "item.h"

item::item() {
    setname("Gold coin");
    setdescription("A small disc made of lustrous metal");
    setvalue(1);
}

item::item(std::string name, std::string desc, int value) :
	name_{ name }, description_{ desc }, value_{ value } {

}


std::string item::getname() const {
    return name_;
}
 
std::string item::getdescription() const {
    return description_;
}

int item::getvalue() const {
    return value_;
}

void item::setname(std::string name) {
    name_ = name;
}

void item::setdescription(std::string description) {
    description_ = description;
}

void item::setvalue(int value) {
    value_ = value;
}

std::string item::tostring() {
	std::string out = "Name: " + this->name_ + " Description: " + this->description_ + " Value: " + std::to_string(value_);
	return out;
}