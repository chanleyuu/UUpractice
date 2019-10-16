#include <iostream>

#include "rpgclass.h"
//#include "weapon.h"

int main(int argc, char **argv) {
    rpgclass me;
    me.setname("Harold");
    me.setclass("Wizard");
    me.setweapon("Simple Staff", weapon::Staff);
    std::cout << "Hello, " << me.getname() <<std::endl;
    return 0;
}




