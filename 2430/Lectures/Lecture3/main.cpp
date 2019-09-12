#include <iostream>

using namespace std;
\
struct Point{
    int x;
    int y;
    Point *next;
};

class list{
private:
    Point *head;
public:
    list(){head=0;}
    bool isempty(){if (head == 0)
                  return true;
                  else return false;}
    void add_beg(int,int); //add one point
    //vpod add_mid();
    void add_end(int,int);
    void Print_allpoints();
    //void del_point();
};

void list::add_beg(int a, int b){
    Point *temp;
    temp = new Point;
    temp->x = a;
    temp->y = b;
    temp->next = head;

    head = temp;
}

void list::add_end(int a, int b){
    Point *copy = head;
    if (copy == 0) {add_beg(a,b); return;};
    while(copy->next !=0) copy = copy->next;

    Point *temp;
    temp = new Point;
    temp->x = a;
    temp->y = b;
    temp->next = 0;
    copy->next = temp;
}

void list::Print_allpoints(){
    Point *current = head;
    while (current != 0) {
        cout << "(" << current->x << "," << current->y << ")" << endl;
        current = current->next;
    }
}

void Print(Point *current) {
    cout << "---Printing---" << endl;
    while(current != 0){
        cout << "(" << current->x << "," << current->y << ")" << endl;
        current = current->next;
    }
    cout << endl;
}
float averageX(Point *current) {
    float total = 0;
    int iteration = 0;
    while(current !=0){
          total += current->x;
          iteration++;
          current = current->next;
    }
    return(total/iteration);
}

int main()
{
    list n;
    n.add_beg(5,6);
    n.add_end(7,8);
    n.add_beg(3,4);
    n.add_beg(1,2);
    n.Print_allpoints();

//    Point *head = new Point;
//    Point *carbon = head;
//    carbon->x = 5;
//    carbon->y = 6;
//    carbon->next = 0;

//    carbon->next = new Point;
//    carbon->next->x = 7;
//    carbon->next->y = 8;
//    carbon->next->next = 0;

//    carbon->next->next = new Point;
//    carbon->next->next->x = 9;
//    carbon->next->next->y = 10;
//    carbon->next->next->next = 0;

//    carbon = head;
//    Print(carbon);
//    carbon = head;
//    cout << "X Average: " << averageX(carbon) << endl;

}
