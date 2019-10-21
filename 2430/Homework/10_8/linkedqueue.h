#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

using namespace std;

class node {
public:
    //Data//
    int id;
    float gpa;
    //End_Data//

    node *next;

    node(/*Data types*/ int, float);
    void print();
};

node::node(/*Data types*/int a, float b) {
    id = a;
    gpa = b;
    next=nullptr;
}
void node::print() {
    cout << "id: " << id << endl << "gpa: " << gpa << endl<<endl;
}

class listQueue{
public:
    node *head;
    node *tail;

    //Constructors
    ListQueue();
    ~ListQueue();
    //Maintenance
    bool isEmpty();
    void print();
    void printRec(node*);
    //Main
    void enqueue(int newID, float newGPA);
    void rmqueue();
};

//Constructors
listQueue::ListQueue() {
    head = tail = nullptr;
}
listQueue::~ListQueue() {
    while(!isEmpty()) rmqueue();
}
//Maintenance
bool listQueue::isEmpty() {
    if(head == nullptr) return true;
    return false;
}
void listQueue::print() {
    node *current = head;
    while(current != nullptr) {
        current->print();
    }
}
void listQueue::printRec(node* current) {
    if(current == nullptr) {
        return;
    }
    else {
        current->print(); //Print forwards
        printRec(current->next);
//        current->print(); //Print backwards
    }
}
//Main
void listQueue::enqueue(int newID, float newGPA)
{
    node *temp = new node(newID, newGPA);

    if(isEmpty()) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void listQueue::rmqueue() { //Implement case for only one node?//
    if(isEmpty()) return;
    node *temp = head;
    else if(head == tail) {
        tail = nullptr;
    }
    head = head->next;
    delete head;
}

#endif // LINKEDQUEUE_H
