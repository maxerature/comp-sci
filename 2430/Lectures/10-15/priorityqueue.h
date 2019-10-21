#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

using namespace std;

struct arrayNode {
    char * data;
    int priority;
    int pos;
};

class priorityQueueArray{
private:
    arrayNode queue[10];
    int front;
    int rear;
public:
    priorityQueueArray();
    void add(node);  //sort while adding (insertion sort)
    ~priorityQueueArray();
    void search(node key);  //linear search
    void print();
};

priorityQueueArray::priorityQueueArray(){
    front=0;
    rear=-1;
}
void priorityQueueArray::add(arrayNode adding) {
    queue[++rear] = arrayNode;
}

//-----------------------------------------------------------------------------------

struct linkedNode {
    char* data;
    int priority;
    linkedNode *next;
};

class priorityQueueLinked{
private:
    linkedNode *head;
    linkedNode *tail;
public:
    priorityQueueLinked();
    void add(node);  //sort while adding (insertion sort)
    ~priorityQueueLinked();
    void search(node key);  //linear search
    void print();
};

priorityQueueLinked::priorityQueueLinked(){
    head=tail=nullptr;
}
void priorityQueueLinked::add(linkedNode *adding) {
    if(head == nullptr) head = adding;
    else{
        tail->next = adding;
    }
    tail = adding;
}


#endif // PRIORITYQUEUE_H
