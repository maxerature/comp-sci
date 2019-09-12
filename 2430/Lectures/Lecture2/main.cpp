#include <iostream>

using namespace std;

class point {
public:
    int x;
    int y;
    point *next;
public:
    point(int, int, point *);
    void setall(int a, int b, point *c);
    void print();
};

//-------------------------Linking---------------------------------

int main()
{
    point *head=0;
    point *currenthead = 0;
    head = new point(5, 7, 0);  //create point
    currenthead = head;

    head->next=new point(8,20,0);   //create new point linked to first
    cout << head->next->x << endl;

    head->next->next = new point(44, 55, 0);    //create new point linked to second

    cout << endl;

    for(int i = 0; i < 3; i++){ //print
        currenthead->print();
        currenthead = currenthead->next; //Essentially p++
    }

    point *cu= currenthead;

    while(cu->next !=0){ //Identical to above, terminates on last point (when next = 0)
        cu->print();
        cu=cu->next;
    }
}


void point::setall(int a, int b, point *c) {
    if (a<0)
        x = 0;
    else
        x=a;
    if (b<0)
        y = 0;
    else
        y=b;
}

void point::print() {
    cout << "(" << x << "," << y << ")\n";
}

point::point(int a, int b , point *c) {
    this->setall(a, b, *c);
}


