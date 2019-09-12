#include <iostream>

using namespace std;

struct dNode {
    char letter;
    dNode *prev;
    dNode *next;
};

class dList{
private:
    dNode* head;
    dNode* tail;
public:
    dList();

    void add_beg(char letter);
    void add_end(char letter);

    void del_beg(char &held);
    void del_end(char &held);

    void print_all();
    bool searchLetter(char key);
};

dList::dList()
{
    head = 0;
    tail = head;
}


void dList::add_beg(char letter) {
    dNode *temp = new dNode;
    temp->letter = letter;
    temp->prev = nullptr;

    if (head != 0) head->prev = temp;
    else tail = temp;
    temp->next = head;
    head = temp;
}

void dList::add_end(char letter) {
    dNode *temp = new dNode;
    temp->letter = letter;
    temp->next = 0;
    temp->prev = tail;

    if (tail != 0)
        tail->next = temp;
    else head = temp;
    tail = temp;
}

void dList::del_beg(char &held)
{
    held = head->letter;
    dNode *temp = head;
    head = head->next;
    head->prev = 0;
    delete temp;
}

void dList::del_end(char &held)
{
    held = tail->letter;
    dNode *temp = tail;
    tail = tail->prev;
    tail->next = 0;
    delete temp;
}

void dList::print_all() {
    dNode *current = head;
    cout << "--PRINT--"<<endl;
    while(current != 0) {
        cout << "Letter: " << current->letter << endl;
        current = current->next;
    }
}

bool dList::searchLetter(char key)
{
    dNode *current = head;
    while(current != nullptr && current->letter !=key ) {
        current = current->next;
    }
    if (current == nullptr) return false;
    else return true;tggggg
}

int main()
{
    char held;
    dList list;
    list.add_end('c');
    list.add_beg('b');
    list.add_beg('a');
    list.add_end('d');
    list.print_all();
    if (list.searchLetter('a')) cout << "A Found" << endl;
    else cout << "A not found" << endl;
    list.del_beg(held);
    list.del_end(held);
    if (list.searchLetter('a')) cout << "A found" << endl;
    else cout << "A not found" << endl;
    list.print_all();
}
