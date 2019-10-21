#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    char cha;
    Node *next;

    Node();
    bool isVowel();
};

class SingleList {
public:
    Node *head;
    Node *tail;


    SingleList();
    void add_beg(char);
    void add_end(char);
    void del_beg();

    bool isEmpty();
    int search();
    void rotate();

    void debug_print();
};

//------------------------Node
Node::Node() {
    cha = ' ';
    next = nullptr;
}

bool Node::isVowel() {
    switch (cha) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
        return true;
    }
    return false;
}

//--------------------------SingleList
SingleList::SingleList()
{
    head = nullptr;
    tail = nullptr;
}

void SingleList::add_beg(char cha) {
    Node *temp = new Node;
    temp->cha = cha;

    if (head != 0) tail = temp;
    temp->next = head;
    head = temp;
}

void SingleList::add_end(char cha) {
    Node *temp = new Node;
    temp->cha = cha;

    if (head == nullptr) {
        head = temp;
    }
    else tail->next = temp;
    tail = temp;
}

void SingleList::del_beg() {
    Node *temp = head;
    head = head->next;
    delete temp;
}

int SingleList::search() {
    Node *current = head;
    if (head->isVowel()) return 0;
    current = current->next;
    while(current != nullptr) {
        if (current->isVowel()) return 1;
        current = current->next;
    }
    return 2;
}

void SingleList::rotate() {
    char heldCha = head->cha;
    del_beg();
    add_end(heldCha);
}

void SingleList::debug_print() {
    Node *current = head;

    while(current != nullptr) {
        cout << current->cha << endl;
        current = current->next;
    }
}

//-----------------------Program
int main()
{
    string input;
    SingleList list;

    SingleList way;
    way.add_end('-');
    way.add_end('w');
    way.add_end('a');
    way.add_end('y');

    cout << "Input a word: ";
    cin >> input;

    for(int i=0; i<input.length(); i++) {
        list.add_end(input[i]);
    }

    if (list.search() == 0 || list.search() == 2) list.tail->next = way.head;
    else {
        Node *current = list.head;
        list.add_end('-');
        while (!current->isVowel()) {
            current = current->next;
            list.rotate();
        }
        list.add_end('a');
        list.add_end('y');
    }
    list.debug_print();
}
