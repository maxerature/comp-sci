#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
using namespace std;

struct Player {
    string information;
    Player *next;
    Player *prev;
};

class dList{
private:
    Player* head;
    Player* tail;
public:
    dList();

    void add_beg(string information);
    void add_end(string information);

    void del_beg(string &held);
    void del_end(string &held);

    void print_all();
    void sort();
    bool checkUnOrdered(string first, string compared);
    void checkNames(ifstream &cms, ofstream &ofs);
};

dList::dList()
{
    head = 0;
    tail = head;
}


void dList::add_beg(string information) {
    Player *temp = new Player;
    temp->information = information;
    temp->prev = nullptr;

    if (head != 0) head->prev = temp;
    else tail = temp;
    temp->next = head;
    head = temp;
}

void dList::add_end(string information) {
    Player *temp = new Player;
    temp->information = information;
    temp->next = 0;
    temp->prev = tail;

    if (tail != 0)
        tail->next = temp;
    else head = temp;
    tail = temp;
}

void dList::del_beg(string &held)
{
    held = head->information;
    Player *temp = head;
    head = head->next;
    head->prev = 0;
    delete temp;
}

void dList::del_end(string &held)
{
    held = tail->information;
    Player *temp = tail;
    tail = tail->prev;
    tail->next = 0;
    delete temp;
}

void dList::print_all() {
    Player *current = head;
    cout << "--PRINT--"<<endl;
    while(current != 0) {
        cout << current->information << endl;
        current = current->next;
    }
}


void dList::sort() {
    string temp;
    Player *current = head->next;
    while(current != 0) {
        temp = current->information;
        while(current != head && current != 0 && current->prev !=0 && checkUnOrdered(current->prev->information, temp)) {
            current->information = current->prev->information;
            current = current->prev;
        }
        current->information = temp;

        current = current->next;
    }
}

bool dList::checkUnOrdered(string first, string compared) {
    if (first > compared) return true;
    return false;
}

void dList::checkNames(ifstream &cms, ofstream &ofs)
{
    string checkName;
    string listName;
    int counter;
    bool found;
    Player *current;

    while (getline(cms, checkName)) {
        current = head;
        if(checkName[checkName.length()-1] == '\r') checkName.pop_back();
        counter = 0;
        found = false;
        while (current != 0) {

            listName = current->information;
            listName.erase(listName.find(","), listName.length());
            if (listName == checkName) {
                ofs << checkName << ": " << counter << endl;
                found = true;
                break;
            }
            counter++;
            current = current->next;
        }
        if (!found) ofs << checkName << ": -1" << endl;
    }
}

int main(int argc, char *argv[])
{
//    if (argc != 3 && argc !=2) {
    if (argc < 2) {
        cout << "Invalid arguments" << endl;
        return 1;
    }
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    string command = am.get("command");

    ifstream ifs(input);

    dList playerList;


    string curLine;
    while(getline(ifs, curLine)) {
        playerList.add_beg(curLine);
    };
    playerList.print_all();
    cout << endl << endl << "Sorted: " << endl;
    playerList.sort();
    playerList.print_all();

    ifstream cms(command);
    ofstream ofs(output);
    playerList.checkNames(cms, ofs);

    ofs.close();
}
