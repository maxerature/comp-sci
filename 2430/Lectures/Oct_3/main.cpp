#include <iostream>
#include <string>

using namespace std;

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

int priority(char x) {
    if (x== '^') return 3;
    else if (x == '*' || x == '/') return 2;
    else if (x == '+' || x == '-') return 1;
}

string infixToPostfix(string infix) {
    string postfix;
    char tempchar;
    sstack<char> stack;
    for(int i=0; i<infix.length(); i++) {
        if (isdigit(infix[i]))  {postfix.push_back(infix[i]);}   //If character is int move to output
        else {
            stack.pop(tempchar);
            if(priority(infix[i]) <= (priority(tempchar))) {
                stack.push(tempchar);
                stack.pop(tempchar);
                postfix.push_back(tempchar);
                stack.push(infix[i]);
            }
            else {
                stack.push(tempchar);
                postfix.push_back(infix[i]);
            }
        }     //If char check priority to top of stack
            //If priority <= stack
                //move from stack to output
                //push to stack
            //if > stack
                //Push to stack

    }
    while(!stack.isempty()) {
        stack.pop(tempchar);
        postfix.push_back(tempchar);
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    int result;
    int temp1;
    int temp2;
    sstack<int> stack;

    for(int i=0; i<postfix.length(); i++) {
        if(isdigit(postfix[i])) {
            stack.push(int(postfix[i]- '0'));
        }
        else {
            stack.pop(temp2);
            stack.pop(temp1);
            if (postfix[i] ==  '^') {
                temp1 = temp1 ^ temp2;
            }
            else if (postfix[i] == '*')  {
                temp1 = temp1 * temp2;
            }
            else if (postfix[i] ==  '/') {
                temp1 = temp1/temp2;
            }
            else if (postfix[i] ==  '+') {
                temp1 = temp1 + temp2;
            }
            else if (postfix[i] ==  '-') {
                temp1 = temp2 - temp2;
            }
            stack.push(temp1);
            }

            //push back to stack
        }
    stack.pop(result);
    return result;
}

string postfixToInfix(string postfix) {
    string infix;
    string temp1;
    string temp2;

    sstack<string> stack;

    for(int i=0; i<postfix.length(); i++) {
        if(isdigit(postfix[i])) {
            stack.push(to_string(postfix[i]));
        }
        else {
            stack.pop(temp1);
            stack.pop(temp2);
            temp2.push_back(infix[i]);
            for (int j=0; i<temp1.length();j++) {
                temp2.push_back(temp1[i]);
            }
            stack.push(temp2);
        }
    }
    stack.pop(infix);
    return infix;
}

int main()
{
//    cout << evaluatePostfix("42+3*85/8*") << endl;
    cout << postfixToInfix("42+3*85/8*");
}
