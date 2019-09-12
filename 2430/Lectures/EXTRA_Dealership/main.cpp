#include <iostream>

using namespace std;

struct Car {
    int color;
    char *make;
    Car *next;
};

class Dealership {
private:
    Car* head;
public:
    Dealership() {head=0;}
    bool add_beg(int, char*);
    bool add_end(int, char*);
    bool add_at(int, char*, int);
    bool add_make(int, char*, char*);
    bool add_color(int, char*, int);

    bool del_beg(int &a, char* &b);
    bool del_end(int &a, char* &b);
    bool del_at(int &a, char* &b, int);
    bool del_make(int &a, char* &b, char*);

    bool is_empty();
    void print_all();
};


bool Dealership::add_beg(int a, char* b) {
    Car *temp = new Car;
    temp->color = a;
    temp->make = b;
    temp->next = 0;

    temp->next = head;
    head = temp;

    return true;
}

bool Dealership::add_end(int a, char* b) {
    if (is_empty()) {add_beg(a, b); return true;}
    Car *current = head;
    while (current->next != 0) {
        current = current->next;
    }
    Car *temp = new Car;
    temp->color = a;
    temp->make = b;
    temp->next = 0;

    current->next = temp;
    return true;
}

bool Dealership::add_at(int a, char* b, int num) {
    if (is_empty()) {add_beg(a, b); return true;};
    Car *current = head;

    for (int i = 1; i < num-1; i++) {
        current = current->next;
        if (current->next == 0) break;
    }
    Car *temp = new Car;
    temp->color = a;
    temp->make = b;
    temp->next = 0;

    temp->next = current->next;
    current->next = temp;
    return true;
}

bool Dealership::add_make(int a, char* b, char* make) {
    if (is_empty()) {add_beg(a, b); return true;};
    Car *current = head;

    while (current->make != make && current->next != 0) {
        current = current->next;
        if (current->next == 0) break;
    }

    Car *temp = new Car;
    temp->color = a;
    temp->make = b;
    temp->next = 0;

    temp->next = current->next;
    current->next = temp;
    return true;
}

bool Dealership::add_color(int a, char* b, int color) {
    if (is_empty()) {add_beg(a, b); return true;};
    Car *current = head;

    while (current->color != color && current->next != 0) {
        current = current->next;
        if (current->next == 0) break;
    }

    Car *temp = new Car;
    temp->color = a;
    temp->make = b;
    temp->next = 0;

    temp->next = current->next;
    current->next = temp;
    return true;
}

bool Dealership::del_beg(int &a, char* &b) {
    if (is_empty()) return false;
    Car *temp = head;
    a = temp->color;
    b = temp->make;
    head = head->next;
    delete temp;
    return true;
}

bool Dealership::del_end(int &a, char* &b) {
    if (is_empty()) return false;
    Car *current = head;
    if (current->next == 0) {
        del_beg(a, b);
        return true;
    }
    Car *prev = new Car;
    while(current->next != 0) {
        prev = current;
        current = current->next;
    }
    a = current->color;
    b = current->make;
    prev->next = 0;
    delete current;
    return true;
}

bool Dealership::del_at(int &a, char* &b, int num) {
    if(is_empty()) return false;
    Car *current = head;
    for(int i = 1; i < num-1; i++) {
        current = current->next;
        if (current->next == 0) return false;
    }
    Car *temp = current->next;
    a = temp->color;
    b = temp->make;
    current->next = temp->next;
    delete temp;
    return true;
}

bool Dealership::del_make(int &a, char* &b, char* make) {
    if (is_empty()) return false;
    Car *current = head;
    Car *prev = new Car;
    while (current->make != make) {
        prev = current;
        current = current->next;
        if (current == 0) return false;
    }
    prev->next = current->next;
    a = current->color;
    b = current->make;

    delete current;
    return true;
}

bool Dealership::is_empty() {
    if (head == 0) return true;
    return false;
}

void Dealership::print_all() {
    if (is_empty()) return;
    Car *current = head;
//    int DEBUG = 0;
    while (current != 0) {
//        DEBUG++;
        cout << "color: " << current->color << endl << "make: " << current->make << endl << "-------------------" << endl;
//        cout << "Test" << DEBUG << endl;
        current = current->next;
    }
}

int main()
{
    int heldColor;
    char* heldMake;
    Dealership redLine;
    cout << endl << "/--Add_beg (Empty) Test--\\" << endl;
    redLine.add_beg(2, "toyota");
    redLine.print_all();
    cout << endl << "/--Add_beg (Populated) Test--\\" << endl;
    redLine.add_beg(1, "hyundai");
    redLine.print_all();
    cout << endl << "/--Add_end (Populated) Test--\\" << endl;
    redLine.add_end(3, "Tesla");
    redLine.print_all();
    cout << endl << "/del_beg (2+) Test--\\" << endl;
    redLine.del_beg(heldColor, heldMake);
    redLine.print_all();
    cout << endl << "/--del_end (2+) Test--\\" << endl;
    redLine.del_end(heldColor, heldMake);
    redLine.print_all();
    cout << endl << "/--del_end (1) Test--\\" << endl;
    redLine.del_end(heldColor, heldMake);
    redLine.print_all();
    cout << endl << "/--del_end (Empty) Test--\\" << endl;
    redLine.del_end(heldColor, heldMake);
    redLine.print_all();
    cout << endl << "/--del_beg (Empty) Test--\\" << endl;
    redLine.print_all();
    cout << endl << "/--add_at (Missing) Test--\\" << endl;
    redLine.add_at(0, "noU", 5);
    redLine.print_all();
    cout << endl << "/--add_make (Missing) Test--\\" << endl;
    redLine.add_make(3, "nomake", "pass1");
    redLine.print_all();
    cout << endl << "/add_color (Missing) Test--\\" << endl;
    redLine.add_color(10, "nocolor", 30);
    cout << endl << "/--add_at Test--\\" << endl;
    redLine.add_at(1, "correct", 1);
    redLine.print_all();
    cout << endl << "/--add_make Test--\\" << endl;
    redLine.add_make(2, "makePres", "correct");
    redLine.print_all();
    cout << endl << "/--add_color Test--\\" << endl;
    redLine.add_color(2, "res", 2+++++++++++);
    redLine.print_all();
    cout << endl << "/--del_at (Missing) Test--\\" << endl;
    redLine.del_at(heldColor, heldMake, 5);
    redLine.print_all();
    cout << endl << "/--del_make (Missing) Test--\\" << endl;
    redLine.del_make(heldColor, heldMake, "Missing");
    redLine.print_all();
    cout << endl << "/--del_at Test--\\" << endl;
    redLine.del_at(heldColor, heldMake, 2);
    redLine.print_all();
    cout << endl << "/--del_make Test--\\" << endl;
    redLine.del_make(heldColor, heldMake, "makePres");
    redLine.print_all();


//    redLine.add_end(1, "eleventeen");
//    redLine.add_beg(2, "twelvteen");
//    redLine.print_all();
}
