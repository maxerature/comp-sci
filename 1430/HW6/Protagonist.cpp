#include "Protagonist.h"
#include <iostream>
#include <string>
using namespace std;

//implement constructors
Protagonist::Protagonist() {
    type = "Warrior";
    age = 25;
}
Protagonist::Protagonist(string tempType, int tempAge) {
    type = tempType;
    age  = tempAge;
}

//implement getter functions
int Protagonist::getAge() {
    return age;
}
string Protagonist::getEquipment() {
    return equipment.getWeapon();
}
string Protagonist::getType() {
    return type;
}

//implement setter functions
void Protagonist::setAge(int tempAge) {
    age = tempAge;
}
void Protagonist::setEquipment(string tempEquip) {
    equipment.setWeapon(tempEquip);
}
void Protagonist::setType(string tempType) {
    type = tempType;
}

//implement overloaded operator function
bool Protagonist::operator== (Protagonist tested) {
    if (getRace() == tested.getRace() && getGender() == tested.getGender() && type == tested.type && equipment.getWeapon() == tested.equipment.getWeapon() && age == tested.age) return true;
    return false;
}

//implement stats function
void Protagonist::stats() {
    cout << "Race: " << getRace() << endl <<
            "Gender: " << getGender() << endl <<
            "Class: " << type << endl <<
            "Weapon: " << equipment.getWeapon() << endl <<
            "Age: " << age <<endl;
}
