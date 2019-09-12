#include <iostream>

using namespace std;

struct Player {
    int number;
    int age;
    int minsPlayed;
    bool status; //True = court, False = bench
    Player *next;
    Player *prev;

    void addPlayTime(int);
    Player();
    Player(int number, int age, int minsPlayed, bool status);
};




class benchList {
public:
    Player *head;
    Player *tail;
public:
    benchList();
    void add_beg(Player*);
    void printRec(Player*);
};



class playList {
private:
    Player *head;
    Player *tail;
public:
    playList();
    void add_beg(Player);
};




void quarter() {}

int main()
{
    srand(time(NULL));
    Player *lockerRoom[12] = {};


    Player *temp;
    for(int i=1; i< 13; i++) {
        temp = new Player(i, rand() % 30+20, 0, false);
        lockerRoom[i-1] = temp;
    }

    benchList bench;
    bench.add_beg(lockerRoom[1]);
    bench.add_beg(lockerRoom[2]);

    bench.printRec(bench.head);
}

Player::Player()
{
    number = 0;
    age = 0;
    minsPlayed = 0;
    status = false;
    next = nullptr;
    prev = nullptr;
}

Player::Player(int number, int age, int minsPlayed, bool status)
{
    this->number = number;
    this->age = age;
    this->minsPlayed = minsPlayed;
    this->status = status;
    next = nullptr;
    prev = nullptr;
}

benchList::benchList()
{
    head = 0;
    tail = 0;
}

void benchList::add_beg(Player *adding) {
    adding->prev = nullptr;

    if (head != 0) head->prev = adding;
    else tail = adding;
    adding->next = head;
    head = adding;
}

void benchList::printRec(Player *current) { //Recursively print linked list
    if (current == nullptr) return;
    else {
//        cout << current->information << endl;  //Put output here to print backwards
        printRec(current->next);
        cout << current->number << endl << current->age << endl << current->minsPlayed << endl << current->status << endl; //Put output here to print in order
    }
}

playList::playList()
{
    head = 0;
    tail = 0;
}
