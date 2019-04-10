#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
using namespace std;

class Character{
   
public:
   //constructors
   Character();
   Character(string occTemp, string raceTemp, char genderTemp);
   
   //getter functions
   string getOccupation();
   string getRace();
   char getGender();
   
   //setter functions
   void setRace(string);
   void setOccupation(string);
   void setGender(char);
   
   //overloaded operator function
   bool operator==(Character);
   
   //stats function
   void stats();
   
private:
   string occupation;
protected:
   string race;
   char gender;

};
#endif