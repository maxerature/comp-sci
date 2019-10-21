#include <iostream>

using namespace std;

template <class Type>


class sarray {  //Stack based on array
public:
    int top;
    int size;
    Type *element;
    sarray();
    bool isempty();
    bool isfull();
    void push(Type);
    void pop (Type&);
    void print();
};

template <class Type>
sarray<Type>::sarray() {
    size=10;
    top=-1;

    element = new Type[size];   //Not strictly necessary
}

template <class Type>
bool sarray<Type>::isempty() {
    if (top == -1) return true;
    return false;
}

template <class Type>
bool sarray<Type>::isfull() {
    if (top == size-1) return true;
    return false;
}

template <class Type>
void sarray<Type>::push(Type val) {
    if (!isfull()) {
        top++;
        element[top] = val;
    }
}

template <class Type>
void sarray<Type>::pop(Type &val) {
    if (!isempty()) {
        val = element[top];
        top--;
    }
}

template <class Type>
void sarray<Type>::print() {
    Type temp;
    while(!isempty()) {
        pop(temp); {
            cout << temp;
        }
    }
}
