#include <iostream>
#include <string>
#include <fstream>
#include <ArgumentManager.h>

using namespace std;

class node {
public:
    string fullText;
    string firstWord;
    string lastWord;

    node *next;

    node() {fullText = " "; firstWord = " "; lastWord = " ";}
    node(string full, string first, string last) {fullText = full; firstWord = first; lastWord = last;}
};

class list {
    node *head;
public:
    list() {head = 0;}
    void add(string, string, string);
    void swap(int, int);
    void sort(int);
    void output(string);
};

void list::add(string fullText, string firstWord, string lastWord) {
    node *temp = new node;
    temp->firstWord = firstWord;
    temp->fullText = fullText;
    temp->lastWord = lastWord;

    temp->next = head;
    head = temp;
}

void list::swap(int pos1, int pos2) {
    node *cur1 = head;
    node *cur2 = head;
    node temp;

    for(int i=0; i<pos1; i++) {
        cur1 = cur1->next;
    }
    for(int i=0; i<pos2; i++) {
        cur2 = cur2->next;
    }
    temp.firstWord = cur1->firstWord;
    temp.fullText = cur1->fullText;
    temp.lastWord = cur1->lastWord;

    cur1->firstWord = cur2->firstWord;
    cur1->fullText = cur2->fullText;
    cur1->lastWord = cur2->lastWord;

    cur2->firstWord =temp.firstWord;
    cur2->fullText = temp.fullText;
    cur2->lastWord = temp.lastWord;
}

void list::sort(int thoughts) {
    int count1 = 0;
    int count2 = 0;
    string curWord;

    node *current = head;
    node *cur2 = head;


    while(cur2 != nullptr) {
        if(current->firstWord == cur2->lastWord) {
            current = current->next;
            cur2 = head;
            count1++;
            continue;
        }
        cur2 = cur2->next;
    }
    swap(0, count1);


    current = head;
    cur2 = current->next;
    count1 = 1;
    count2 = 2;
    while(cur2!= nullptr) {
        if (current->lastWord == cur2->firstWord) {
            swap(count1, count2-1);
            count1++;
            count2 = count1;
            current = current->next;
            cur2 = current;
        }
        cur2 = cur2->next;
        count2++;
    }
}

void list::output(string output) {
    node *current = head;
    ofstream ofs(output);
    while(current != nullptr) {
        ofs << current->fullText << endl;
        current = current->next;
    }
    ofs.close();
}

int main(int argc, char *argv[])
{
    if (argc != 3 && argc !=2) {
        cout << "Invalid arguments" << endl;
        return 1;
    }
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");


//    string look = "Hello there I am Obi Wan Kenobi";
//    int found;
//    found = look.find_last_of(" ");
//    string last = look.substr(found+1);
//    cout << last << endl;
//    found = look.find_first_of(" ");
//    string first = look.substr(0, found);
//    cout << first;

    list thoughts;
    int counter;

    string tempStr = " ";
    string fstStr;
    string lstStr;
    int pos;
    ifstream ifs(input);
    while(getline(ifs, tempStr)) {
        fstStr = tempStr.substr(0, tempStr.find_first_of(" "));
        fstStr[0] = tolower(fstStr[0]);
        for(int i=0; i<fstStr.length(); i++) {
            if((fstStr[i]<'a'||fstStr[i]>'z') && (fstStr[i]<'A'||fstStr[i]>'Z')) {
                fstStr.erase(i, i+1);
                i--;
            }
        }
        lstStr = tempStr.substr(tempStr.find_last_of(" "));
        for(int i=0; i<lstStr.length(); i++) {
            if((lstStr[i]<'a'||lstStr[i]>'z') && (lstStr[i]<'A'||lstStr[i]>'Z')) {
                lstStr.erase(i, i+1);
                i--;
            }
        }
        lstStr[0] = tolower(lstStr[0]);
        thoughts.add(tempStr, fstStr, lstStr);
        counter++;
    }
    ifs.close();
    if (tempStr == " ") return 0;
    thoughts.sort(counter);

    thoughts.output(output);
}
