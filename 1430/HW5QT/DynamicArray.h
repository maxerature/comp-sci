#ifndef DynamicArray_H
#define DynamicArray_H

#include <string>
using namespace std;

class DynamicArray {
    public:
        DynamicArray();
        DynamicArray(int arraySize);
        DynamicArray(const DynamicArray &a);
        DynamicArray& operator=(const DynamicArray& rhs);

        int getArraySize() const;
        int getNumOfElements() const;

        string toString() const;
        string toString(int pos) const;

        void addElement(int num);
        void deleteElement(int num);

        ~DynamicArray();

    private:
        int *arr;
        int arraySize;
        int numOfElements = 0;
};

#endif
