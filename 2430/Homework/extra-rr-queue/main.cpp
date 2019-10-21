#include <iostream>
#include <fstream>

using namespace std;

class node {
public:
    int jobnum;
    int length;
    int beg_time;
    int wait_time;
    int end_time;
    node *next;

    node(int length, int inbnum);
};
node::node(int inlength, int innum)
{
    length = inlength;
    jobnum = innum;
    beg_time = -1;
    wait_time = 0;
    end_time = 0;
}


class listQueue{
public:
    node *head;
    node *tail;

    //Constructors
    listQueue();
    ~listQueue();
    //Maintenance
    bool isEmpty();
    //Main
    void enqueue(node*);
    void rmqueue();
    void shift(node*);
};

//Constructors
listQueue::listQueue() {
    head = tail = nullptr;
}
listQueue::~listQueue() {
    while(!isEmpty()) rmqueue();
}
//Maintenance
bool listQueue::isEmpty() {
    if(head == nullptr) return true;
    return false;
}

//Main
void listQueue::enqueue(node* temp)
{
    if(isEmpty()) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
}

void listQueue::rmqueue() { //Implement case for only one node?//
    if(isEmpty()) return;
    node *temp = head;
    if(head->next == nullptr) {
        tail = nullptr;
        head = nullptr;
    }
    else head = head->next;
    delete temp;
}
void listQueue::shift(node *temp) {
    node *temp2 = head;
    if(temp2 == temp) {
        head = head->next;
        delete temp;
        return;
    }
    else {
        while(temp2->next != temp) temp2 = temp2->next;
        temp2->next = temp->next;
        delete temp;
    }
}

int main()
{
    node *nodes[10];
    int temp;
    node *tempnode;
    node *tempnode2;
    listQueue rrobin;
    for(int i=0; i<10; i++) {
        temp = rand()%20 +1;
        tempnode = new node(temp, i+1);
        tempnode2 = new node(temp, i+1);
        nodes[i] = tempnode2;
        rrobin.enqueue(tempnode);
    }

    int tottime;
    int curtime;

    node *current;
    while(rrobin.head != nullptr) {
        tottime = 0;
        current = rrobin.head;
        while(current != nullptr) {
            if(current->beg_time == -1) current->beg_time = tottime;
            if(current->length <= 3) curtime = current->length;
            else curtime = 3;

            current->wait_time += tottime;
            tottime += curtime;

            current->length -= curtime;
            if(current->length <= 0) {
                nodes[current->jobnum-1]->beg_time = current->beg_time;
                nodes[current->jobnum-1]->end_time = current->wait_time+nodes[current->jobnum-1]->length;
                nodes[current->jobnum-1]->wait_time = current->wait_time;
                tempnode = current;
                current = current->next;
                rrobin.shift(tempnode);
            }
            else current = current->next;
        }
    }
    ofstream ofs("output.txt");
    for(int i=0; i<10; i++) {
        ofs << "beg: " << nodes[i]->beg_time << "   wait: " << nodes[i]->wait_time << "     length: " << nodes[i]->length << "  end: " << nodes[i]->end_time << endl;
    }
}
