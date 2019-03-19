#include "DynamicArray.h"
#include <iostream>
#include <string>


using namespace std;

int main() {

    //***********  addElements Function is Tested  ***********

    DynamicArray Darr(1);
    Darr.addElement(1);
    Darr.addElement(2);
    Darr.addElement(3);
    Darr.addElement(4);
    Darr.addElement(5);
    if (Darr.getArraySize() == 8)
    {
        cout << "Correct Result" << endl;
        cout << "array Size after expansion is : 8" << endl << endl;
    }
    else
    {
        cout << "Your addElement Function is not correct" << endl;
        cout << "Your arraySize after Expansion is : " << Darr.getArraySize() << endl;
        cout << "Expected Output : 8 " << endl << endl;
    }
    //*********** Constructor with invalid input  is Tested  ***********
    DynamicArray Darr2(0);
    if (Darr2.getArraySize() == 1)
    {
        cout << "Correct Result" << endl;
        cout << "array Size after given wrong value (less than one) : 1" << endl << endl;
    }
    else
    {
        cout << "Your constrcutor is not Correct" << endl;
        cout << "The arraySize should be at least One" << endl << endl;
    }

    //***********  Method with invalid input  is Tested ***********
    DynamicArray Darr3(3);
    Darr3.addElement(20);
    Darr3.addElement(22);
    if (Darr3.getArraySize() == 3) {
        cout << "Correct Result" << endl;
        cout << "array Size is after given a wrong value (less than actual numOfElements) : 3" << endl << endl;
    }
    else {
        cout << "Your Constrcutor is not Correct" << endl;
        cout << "The value passed for arraySize should be bigger than actual numOfElements" << endl << endl;
    }

    //*********** toString Function  is Tested  ***********
    DynamicArray Darr4(1);
    Darr4.addElement(1);
    Darr4.addElement(2);
    Darr4.addElement(3);
    Darr4.deleteElement(2);
    string s = Darr4.toString();
    string str1 = "1,3";

    if (s == str1) {
        cout << "Correct Result" << endl;
        cout << "Elements of array :1,2,3" << endl << endl;
    }
    else {
        cout << "Result is incorrect " << endl;
        cout << "your function prints:";
        cout << s << endl;
        cout << " But, Expected output should be:" << str1 << endl << endl;

    }

    //*********** Copy Constructor  is Tested  ***********
    DynamicArray Darr5(1);
    Darr5.addElement(10);
    DynamicArray Darr6 = Darr5;
    Darr6.addElement(100);
    Darr6.addElement(1000);
    string s1 = Darr5.toString();
    string output1 = "10";
    string s2 = Darr6.toString();
    string output2 = "10,100,1000";
    //if(Darr.getnumOfElements() == 3 && Darr.getarraySize() == 4)
    if (s1 == output1 && s2 == output2) {
        cout << "Correct Result" << endl;
        cout << "First array has " << Darr5.toString() << endl;
        cout << "Copied array after modification has " << Darr6.toString() << endl << endl;
    }
    else {
        cout << "Result is incorrect " << endl;
        cout << "First array has " << Darr5.toString() << " should have: 10" << endl;
        cout << "Copied array after modification has " << Darr5.toString() << " should have: 10,100,1000";


    }

    return 0;


}
