#include "Weapon.h"
#include <iostream>
#include <string>
using namespace std;

//implement constructors
Weapon::Weapon(){type = "Sword";}
Weapon::Weapon(string weapTemp){type = weapTemp;}

//implement getter function
string Weapon::getWeapon(){return type;}

//implement setter function
void Weapon::setWeapon(string newWeap){type = newWeap;}

//implement stats function
void Weapon::stats(){
   cout << "Weapon: " << type << endl;   
}
