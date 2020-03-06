#pragma once

#include <string>
#include "location.h"

class item {
public:
    item(); //Constructor

	item(std::string name, std::string desc, int value);

    std::string getname() const;
    std::string getdescription() const;
    int getvalue() const;
	int getweight() const;
    location* getlocation() const;

    void setname(std::string name);
    void setdescription(std::string description);
    void setvalue(int value);
	void setweight(int weight);
    void setlocation(location* loc);

	std::string tostring();

private:
    std::string name_;
    std::string description_;
    int value_;
	int weight_;
    bool held_;
    location* location_;
};
