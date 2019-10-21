#include <iostream>

using namespace std;

template <class Type>

template <class Type>
struct node {
    Type f1;
    node<Type> *next;
};
template <class Type>
class sstack {
public:
    node <Type> *top;
    sstack() {top=nullptr;}
    void push(Type);
    void pop(Type&);
    bool isempty();
    void reverse();
    void print();
};


template <class Type>
void sstack<Type>::push(Type val) {
    node <Type> *temp = new node<Type>;

    temp->f1 = val;
    temp->next = top;
    top = temp;
}

template <class Type>
void sstack<Type>::pop(Type &val) {
    node<Type> *temp = top;
    val = temp->f1;
    top = temp->next;
    delete temp;
}

template <class Type>
bool sstack<Type>::isempty() {
    if (top == nullptr) return true;
    return false;
}

template <class Type>
void sstack<Type>::reverse() {
    Type temp;
    sstack<Type> reverse;
    while(!isempty()) {
        pop(temp);
        reverse.push(temp);
    }
}

template <class Type>
void sstack<Type>::print() {
    Type temp;
    while(!isempty()) {
        pop(temp); {
            cout << temp;
        }
    }
}
