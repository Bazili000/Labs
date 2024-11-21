#include "listTests.h"

void listTestPushFront() {
    LinkedList<int> list;
    list.pushFront(10);
    list.pushFront(20);

    assert(list.size() == 2);
    assert(list.getFront() == 20);
}

void listTestPopFront() {
    LinkedList<int> list;
    list.pushFront(10);
    list.pushFront(20);
    list.popFront();

    assert(list.size() == 1);
    assert(list.getFront() == 10);

    list.popFront();
    assert(list.size() == 0);
}

void listTestGetFront() {
    LinkedList<int> list;
    list.pushFront(5);
    list.pushFront(15);

    assert(list.getFront() == 15);
    list.popFront();
    assert(list.getFront() == 5);
}

void listTestDestroy() {
    LinkedList<int> list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    
    list.destroy();
    assert(list.size() == 0);
}

void listTestSize() {
    LinkedList<int> list;
    assert(list.size() == 0);

    list.pushFront(1);
    assert(list.size() == 1);

    list.pushFront(2);
    assert(list.size() == 2);

    list.popFront();
    assert(list.size() == 1);
}

void listTest() {
    listTestPushFront();
    listTestPopFront();
    listTestGetFront();
    listTestDestroy();
    listTestSize();

    std::cout << "LINKED LIST TESTS PASSED.\n";
}
