#include <cmath>
#include <iostream>

using namespace std;

struct node {
    char f1;
    node *next;
};
class stack {
public:
    node *head;

    stack();

    void push(char);
    void pop(char&);
    bool isempty();
    void reverse();
    void print();
};

stack::stack()
{
    head=0;
}
void stack::push(char add) {
    node *temp = new node;
    temp->f1 = add;
    temp->next = head;
    head = temp;
}
void stack::pop(char &popped) {
    popped = head->f1;
    node *temp = head;
    head = head->next;
    delete temp;
}
bool stack::isempty() {
    if (head ==nullptr) return true;
    return false;
}
void stack::reverse() {
    stack reversed;
    char temp;

    while (!isempty()) {
        pop(temp);
        reversed.push(temp);
    }
    head = reversed.head;
}
void stack::print() {
    stack temp;
    char tempchar;
    while(!isempty()) {
        pop(tempchar);
        temp.push(tempchar);
        cout << tempchar << "   ";
    }
    while(!temp.isempty()) {
        temp.pop(tempchar);
        push(tempchar);
    }
}


int converttoint(string s) {
    int num = 0;
    int temp;
    for(int i=0; i<s.length(); i++) {
        temp = s[i]-'0';
        num += temp*pow(10,s.length()-(i+1));
    }
    return num;
}

int main()
{
    stack temp;
    temp.push('a');
    temp.push('b');
    temp.push('c');
    temp.push('d');
    temp.push('e');
    temp.push('f');
    temp.push('g');


    temp.print();
    temp.reverse();
    cout << endl;
    temp.print();
}

