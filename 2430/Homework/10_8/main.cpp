#include <iostream>
#include <assert.h>

using namespace std;


template <class type>
class Queue {
private:

public:
};

template <class type>
class listQueue {
private:
    int frontIndex;
    int backIndex;
    int maxQueueSize;
    int queue[maxQueueSize];
public:
    listQueue();
    ~ListQueue();
    void addQueue();
    void delQueue();
    bool isEmptyQueue();
    bool isFullQueue();
    type getFront();

};

template<class type>
ListQueue<type>::ListQueue(int size) {
    queue
}

template<class type>
bool listQueue<type>::isEmptyQueue()
{
    if (backIndex == 0) return true;
    return false;
}
template<class type>
bool listQueue<type>::isFullQueue() {
    if (backIndex == maxQueueSize) return true;
    return false;
}
template<class type>
type listQueue<type>::getFront() {
    assert(!isEmptyQueue());
    return queue[frontIndex];
}

template<class type>
void listQueue<type>::addQyeye(const type& newElement) {
    if (!isFullQueue()) {
        backIndex++;

    }
}


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

