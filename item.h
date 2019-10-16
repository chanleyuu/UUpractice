#pragma once 

#include <string>

class item {
public:
    item(); //Constructor
    
    std::string getname() const;
    std::string getdescription() const;
    int getvalue() const;
    
    void setname(std::string name);
    void setdescription(std::string description);
    void setvalue(int value);
private:
    std::string name_;
    std::string description_;
    int value_;
};
