#include "sharedTests.h"

void testSharedPtrCreation() {
    SharedPtr<int> sp(new int(10));
    assert(sp.get() != nullptr);
    assert(*sp == 10);
    assert(sp.countsSize() == 1);
}

void testSharedPtrCopy() {
    SharedPtr<int> sp1(new int(5));
    SharedPtr<int> sp2 = sp1;
    assert(sp1.get() != nullptr);
    assert(sp2.get() != nullptr);
    assert(*sp1 == 5);
    assert(*sp2 == 5);
    assert(sp1.countsSize() == 2);
    assert(sp2.countsSize() == 2);
}

void testSharedPtrReset() {
    SharedPtr<int> sp(new int(20));
    sp.reset(new int(30));
    assert(*sp == 30);
    assert(sp.countsSize() == 1);
    sp.reset();
    assert(sp.get() == nullptr);
    assert(sp.countsSize() == 0);
}


void testSharedPtrSwap() {
    SharedPtr<int> sp1(new int(50));
    SharedPtr<int> sp2(new int(60));
    sp1.swap(sp2);
    assert(*sp1 == 60);
    assert(*sp2 == 50);
    assert(sp1.countsSize() == 1);
    assert(sp2.countsSize() == 1);
}

int shrTest() {
    testSharedPtrCreation();
    testSharedPtrCopy();
    testSharedPtrReset();
    testSharedPtrSwap();

    std::cout << "SHARED POINTER TESTS PASSED" << std::endl;
    return 0;
}
