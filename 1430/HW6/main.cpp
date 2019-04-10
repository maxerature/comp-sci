//DO NOT ALTER THIS FILE
//This file is to help you see how some tidbits of code are ran and allow you to see how this program should work
#include "Character.h"
#include "Weapon.h"
#include "Protagonist.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
   /*Protagonist Aang("Airbender", 12);
   Aang.setRace("Avatar");
   Aang.setEquipment("Airbender Staff");
   Aang.stats();*/
   
   /*Character Daenerys_Targaryen("Princess", "Valyrian", 'F');
   Daenerys_Targaryen.stats();
   Daenerys_Targaryen.setOccupation("Dragon Tamer");
   Daenerys_Targaryen.stats();
   
   Protagonist BeastBoy;
   BeastBoy.setType("Shapeshifter");
   BeastBoy.setAge(19);
   BeastBoy.setRace("Human");
   BeastBoy.setEquipment("None");
   BeastBoy.setGender('M');
   BeastBoy.stats();
   BeastBoy.setType("Shapeshifter");
   BeastBoy.setRace("Tiger");
   BeastBoy.setEquipment("Fangs");
   BeastBoy.stats();
   BeastBoy.setType("Shapeshifter");
   BeastBoy.setRace("Grizzly Bear");
   BeastBoy.setEquipment("Claws");
   BeastBoy.stats();*/

   Character Thirius("Draconic Sorceror", "Hill Dwarf", 'M');
   Protagonist Olo ("Arcane Trickster", 25);
   Olo.setOccupation("Draconic Sorceror");
   Olo.setRace("Hill Dwarf");
   Olo.setGender('M');

   if (Thirius == Olo) cout << "True";
   else cout << "False";


}
