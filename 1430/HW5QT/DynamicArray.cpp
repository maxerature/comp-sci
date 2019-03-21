#include "DynamicArray.h"
#include <iostream>
#include <string>


using namespace std;



//Constructors
DynamicArray::DynamicArray() {
    arraySize = 1;
    arr = new int[arraySize] {};
}

DynamicArray::DynamicArray(int arrSize) {
    if (arrSize < 1) {
        arraySize = 1;
    }
    else {
        arraySize = arrSize;
    }

    arr = new int[arraySize] {};
}

DynamicArray::DynamicArray(const DynamicArray &a) {
    arr = new int;
    *arr = *(a.arr);
    arraySize = a.arraySize;
    numOfElements = a.numOfElements;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs) {
    DynamicArray newboii;
    newboii = DynamicArray(rhs);
    return newboii;
}


//Getters
int DynamicArray::getArraySize() const{
    return arraySize;
}

int DynamicArray::getNumOfElements() const {
    return numOfElements;
}


//Printers
string DynamicArray::toString() const{
    string output = "";
    output += to_string(arr[0]);
    for (int i = 1; i < numOfElements; i++) {
        output += ",";
        output += to_string(arr[i]);
    }
    return output;
}

string DynamicArray::toString(int pos) const {
    return to_string(arr[pos]);
}


//Elementals
void DynamicArray::addElement(int num) {
    if (arraySize < (numOfElements+1)) {

        int *tempArray = new int[arraySize];

        for (int i = 0; i < arraySize; i++) {
            tempArray[i] = arr[i];
        }
        delete[] arr;

        arraySize *= 2;

        arr = new int[arraySize];

        for (int i = 0; i < arraySize/2; i++) {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    }

    arr[numOfElements] = num;
    ++numOfElements;
}

void DynamicArray::deleteElement(int num) {
    int deleted = -1;
    for(int i=0; i<arraySize;i++) {
        if(arr[i] == num) {
            deleted = i;
            break;
        }
    }

    if (deleted == -1) return;

    if (deleted != numOfElements-1) {
        int current = arr[numOfElements-1];
        for (int i=numOfElements-2; i>= deleted; i--) {
            arr[i] = current;
            current = arr[i-1];
        }
    }
    numOfElements -=1;

    if (numOfElements <= (arraySize / 2)) {
        int *tempArray = new int[arraySize];

        for (int i = 0; i < arraySize; i++) {
            tempArray[i] = arr[i];
        }
        delete[] arr;

        arraySize *= 2;

        arr = new int[arraySize];

        for (int i = 0; i < arraySize/2; i++) {
            arr[i] = tempArray[i];
        }
        delete[] tempArray;
    }
}

//Destructor
DynamicArray::~DynamicArray() {
    delete arr;
}
