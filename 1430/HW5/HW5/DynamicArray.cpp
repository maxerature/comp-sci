#include "stdafx.h"
#include "DynamicArray.h"
#include <iostream>
#include <string>


using namespace std;



//Constructors
DynamicArray::DynamicArray() {
	arraySize = 1;
	int *arr = new int[arraySize] {NULL};
}

DynamicArray::DynamicArray(int arraySize) {
	if (arraySize < 1) {
		arraySize = 1;
	}

	int *arr = new int[arraySize] {NULL};
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
	//arr = new int;
	//*arr = *(rhs.arr);
	//arraySize = rhs.arraySize;
	//numOfElements = rhs.numOfElements;
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
	output += to_string(arr[1]);
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
	int *tempArray = new int[arraySize];
	for (int i = 0; i < arraySize; i++) {
		tempArray[i] = arr[i];
	}
	delete[] arr;

	int newNum;
	cin >> newNum;
	int empty = -1;

	for (int i = 0; i < arraySize; i++) {
		if (tempArray[i] == NULL) {
			empty = i;
			break;
		}
	}

	if (empty != -1) {
		tempArray[empty] = newNum;
	}
}

void DynamicArray::deleteElement(int num) {

}

//Destructor
DynamicArray::~DynamicArray() {
	delete arr;
}




//int getArraySize()