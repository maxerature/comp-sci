#ifndef PROTAGONIST_H
#define PROTAGONIST_H
#include "Weapon.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Protagonist : public Character{
public:
    //constructors
    Protagonist();
    Protagonist(string, int);

    //getter functions
    int getAge();
    string getEquipment();
    string getType();

    //setter functions
    void setAge(int);
    void setEquipment(string);
    void setType(string);

    //overloaded operator function
    bool operator== (Protagonist);

    //stats function
    void stats();

private:
    int age;
    Weapon equipment;

protected:
    string type;
};

#endif
