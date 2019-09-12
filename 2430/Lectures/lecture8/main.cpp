#include <iostream>

using namespace std;

struct Node {
    Node *prev;
    Node *next;
    int information;
};

class List{
public:
    Node *head;
    Node *tail;
    List();
    void add_beg(int information);
    void printRec(Node *current);
};

List::List()
{
    head = 0;
    tail = 0;
}

void List::add_beg(int information) {
    Node *temp = new Node;
    temp->information = information;
    temp->prev = nullptr;

    if (head != 0) head->prev = temp;
    else tail = temp;
    temp->next = head;
    head = temp;
}

void List::printRec(Node *current) { //Recursively print linked list
    if (current == nullptr) return;
    else {
//        cout << current->information << endl;  //Put output here to print backwards
        printRec(current->next);
        cout << current->information << endl; //Put output here to print in order
    }
}

int multAB(int a, int b) { //Recursive function to multiply through addition
    if(b==1) return a;
    else return a+(multAB(a, b-1));
}

int factorial(int a){   //Recursive Factorial
    if (a==1) return 1;
    else return a*(factorial(a-1));
}



int main()
{
    cout << multAB(5,3) << endl;
    cout << factorial(5) << endl;

    List testList;
    testList.add_beg(5);
    testList.add_beg(72);
    testList.add_beg(12);
    testList.printRec(testList.head);
}
