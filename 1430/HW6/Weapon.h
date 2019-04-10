#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
using namespace std;

class Weapon{
   
public:
   //constructors
   Weapon();
   Weapon(string);
   
   //getter function
   string getWeapon();
   
   //setter function
   void setWeapon(string);
   //stats function
   void stats();
   
private:
   string type;
};


#endif