#include <iostream>
#include <fstream>
#include <string>
#include <ArgumentManager.h>

using namespace std;

struct ReplaceEvent {
    int replacer;
    int replaced;
    int quarter;
    double timeInQuarter;

    ReplaceEvent() {replacer = 0; replaced = 0; quarter = 0; timeInQuarter = 0;}
    ReplaceEvent(int replacer, int replaced, int quarter, double timeInQuarter) {this->replacer = replacer; this->replaced = replaced; this->quarter = quarter; this->timeInQuarter = timeInQuarter;}
};

struct Player {
    int number;
    int age;
    double minsPlayed;
    bool status; //True = court, False = bench
    Player *next;
    Player *prev;

    Player();
    Player(int number, int age, int minsPlayed, bool status);
};

class baseList {
public:
    Player *head;
    Player *tail;
    baseList();

    void add_beg(Player*);
    void print();
};




class benchList :public baseList{
public:
//    benchList();
    void add_beg(Player*);
    void shimmy();
};



class playList :public baseList{
public:
//    playList();
    void add_beg(Player*);
    Player* checkTime(double&);
    void sort();
};


//---------------------------------------------------------------------------------------------------------------------

void swap(Player *oldest, Player *sub, benchList bench, playList play) {
    Player *temp = new Player;
    temp->number = sub->number;
    temp->age = sub->age;
    temp->minsPlayed = sub->minsPlayed;
    temp->status = sub->status;
    bench.shimmy();

    bench.tail->number = oldest->number;
    bench.tail->age = oldest->age;
    bench.tail->minsPlayed = oldest->minsPlayed;
    bench.tail->status = false;

    Player *current = play.head;
    while (current != oldest) {
        current = current->next;
    }

    current->number = temp->number;
    current->age = temp->age;
    current->minsPlayed = temp->minsPlayed;
    current->status = true;
}



int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Invalid arguments" << endl;
        return 1;
    }

    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");

    srand(time(NULL));
    Player *lockerRoom[12] = {};
    int counter = 0;
    double tTime;
    double cTime;
    int tempVar;
    ReplaceEvent replacements[30];
    int replacementCount = 0;
//    ReplaceEvent tempRep = ReplaceEvent(0,0,0,0);


    Player *temp;
    Player *oldest;

    ofstream ofs;

    ofs.open(input);
    ofs << "Age    Number" << endl;
    for(int i=0; i< 12; i++) {
        temp = new Player(i+1, rand() % 30+20, 0, false);
        lockerRoom[i] = temp;
        ofs << temp->age << "\t\t" << temp->number << endl;
    }
    ofs.close();


    playList play;
    benchList bench;

    Player *tempList[12];
    for(int j=0; j<12; j++) {
        tempList[j] = lockerRoom[j];
    }

    while(counter < 5) {
        tempVar = rand() % 12;
        if(tempList[tempVar] != 0) {
            play.add_beg(tempList[tempVar]);
            tempList[tempVar] = 0;
            counter++;
        }
    }

    for(int j=0; j<12; j++) {
        if(tempList[j] != 0) bench.add_beg((tempList[j]));
    }

    play.sort();


    for(int i=0; i<4;i++) { //Each Quarter
        Player *current = new Player;
        tTime = 0;
        cTime = 0;

        while (tTime < 12) {


            cTime = 0;
            oldest = play.checkTime(cTime);
            if (tTime + cTime >= 12) {
                current = play.head;
                do {
                    current->minsPlayed += 12-tTime;
                    current = current->next;
                } while(current != play.head);
                break;
            }
            else {
                current = play.head;
                do {
                    current->minsPlayed += cTime;
                    current = current->next;
                } while(current != play.head);

                replacements[replacementCount++] = ReplaceEvent(bench.head->number, oldest->number, i, tTime+cTime);
                swap(oldest, bench.head, bench, play);
            }
            tTime += cTime;


        }
    }

    ofs.open(output);


    ofs << "----------REPORT 1: PLAYTIME----------" << endl;
    for(int i=1; i<12;i++) {
        temp = lockerRoom[i];
        while(i>0 && temp->minsPlayed < lockerRoom[i-1]->minsPlayed) {
            lockerRoom[i] = lockerRoom[i-1];
            i--;
        }
        lockerRoom[i] = temp;
    }

    ofs << "Age     Number  Playtime" << endl;
    for(int i=0; i<12; i++) {
        ofs << lockerRoom[i]->age << "\t\t" << lockerRoom[i]->number << "\t\t" << lockerRoom[i]->minsPlayed << endl;
    }


    ofs << endl << endl
        << "------------REPORT 2: AGE-------------" << endl;
    for(int i=1; i<12;i++) {
        temp = lockerRoom[i];
        while(i>0 && temp->age < lockerRoom[i-1]->age) {
            lockerRoom[i] = lockerRoom[i-1];
            i--;
        }
        lockerRoom[i] = temp;
    }
    ofs << "Age     Number  Playtime" << endl;
    for(int i=0; i<12; i++) {
        ofs << lockerRoom[i]->age << "\t\t" << lockerRoom[i]->number << "\t\t" << lockerRoom[i]->minsPlayed << endl;
    }


    ofs << endl << endl
        << "-----------REPORT 3: NUMBER-----------" << endl;
    for(int i=1; i<12;i++) {
        temp = lockerRoom[i];
        while(i>0 && temp->number < lockerRoom[i-1]->number) {
            lockerRoom[i] = lockerRoom[i-1];
            i--;
        }
        lockerRoom[i] = temp;
    }
    ofs << "Age     Number  Playtime" << endl;
    for(int i=0; i<12; i++) {
        ofs << lockerRoom[i]->age << "\t\t" << lockerRoom[i]->number << "\t\t" << lockerRoom[i]->minsPlayed << endl;
    }


    ofs << endl << endl
        << "---------REPORT 4: Replacements---------" << endl;
    ofs << "Swap in      Replaced       Replacement Time (Quarter / Total Time)" << endl;
    for(int i=0; i< replacementCount; i++) {
        ofs << replacements[i].replacer << "\t\t\t " << replacements[i].replaced << "\t\t\t\tQ" << replacements[i].quarter+1 << " |||| " << (replacements[i].quarter)*12 + replacements[i].timeInQuarter << " minutes total" << endl;
    }
    ofs.close();
}

//--------------------------------------------------------------------------------------------------------------------------

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

void baseList::print() {
    Player *current = head;
    cout << "--PRINT PLAY--"<<endl;
    if (current != 0) {
        do {
            cout << "NUM: " << current->number << endl << "AGE: " << current->age << endl << "MINS_PLAYED: " << current->minsPlayed << endl << "STATUS: " << current->status << endl;
            current = current->next;
        } while(current != head && current != 0);
    }
}

void benchList::add_beg(Player *adding) {
    adding->prev = nullptr;

    if (head != 0) head->prev = adding;
    else tail = adding;
    adding->next = head;
    head = adding;
}

void benchList::shimmy()
{
    Player *current = head;
    Player *next = current->next;
    while(next != nullptr) {
        current->age = next->age;
        current->number = next->number;
        current->minsPlayed = next->minsPlayed;
        current->status = next->status;
        current = current->next;
        next = next->next;
    }
}

void playList::add_beg(Player *adding) {
    adding->prev = tail;

    if (head != 0) head->prev = adding;
    else tail = adding;
    adding->next = head;
    tail->next = adding;
    head = adding;
}

Player* playList::checkTime(double &time)
{
    Player *oldest =  new Player;
    oldest->age = 0;
    Player *current = head;
    do {
        if (current->age > oldest->age) {
            oldest = current;
        }
        current = current->next;
    } while(current !=head);

    time += (double)oldest->age / 10;

    return oldest;
}

void playList::sort() {
    int tempNum;
    int tempAge;
    double tempTime;
    Player *current = head->next;
    do{
        tempNum = current->number;
        tempAge = current->age;
        tempTime = current->minsPlayed;
        while(current != head && current != 0 && current->prev->number !=0 && current->prev->number > tempNum) {
            current->number = current->prev->number;
            current->age = current->prev->age;
            current->minsPlayed = current->prev->minsPlayed;
            current = current->prev;
        }
        current->number = tempNum;
        current->age = tempAge;
        current->minsPlayed = tempTime;

        current = current->next;
    } while(current != head);
}

baseList::baseList()
{
    head = 0;
    tail = 0;
}
