//include the necessary header file
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;


//implement constructors
Character::Character() {
    occupation = "Cabbage Merchant";
    race = "Human";
    gender = 'M';
}

Character::Character(string occTemp, string raceTemp, char genderTemp) {
    occupation = occTemp;
    race = raceTemp;
    gender = genderTemp;
}

//implement getter functions
string Character::getRace() {
    return race;
}
string Character::getOccupation() {
    return occupation;
}
char Character::getGender() {
    return gender;
}



//implement overloaded operator function
bool Character::operator==(Character tested) {
    if (gender == tested.getGender() && race == tested.getRace()) return true;
    return false;
}
//implement setter functions
void Character::setRace(string tempRace) {
    race = tempRace;
}
void Character::setOccupation(string tempOcc) {
    occupation = tempOcc;
}
void Character::setGender(char tempGender) {
    gender = tempGender;
}


//implement stats function
void Character::stats() {
    cout << "Occupation: " << occupation << endl <<
            "Race: " << race << endl <<
            "Gender: " << gender <<endl;
}
