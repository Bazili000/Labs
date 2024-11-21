#include "uniqueTests.h"

void testUnqPtrCreation() {
    UnqPtr<int> uPtr(new int(10));
    assert(uPtr.get() != nullptr);
    assert(*uPtr == 10);
}

void testUnqPtrMove() {
    UnqPtr<int> uPtr1(new int(5));
    UnqPtr<int> uPtr2 = std::move(uPtr1);
    assert(uPtr1.get() == nullptr);
    assert(uPtr2.get() != nullptr);
    assert(*uPtr2 == 5);
}

void testUnqPtrReset() {
    UnqPtr<int> uPtr(new int(20));
    uPtr.reset(new int(30));
    assert(*uPtr == 30);
    uPtr.reset();
    assert(uPtr.get() == nullptr);
}

void testUnqPtrRelease() {
    UnqPtr<int> uPtr(new int(40));
    int* rawPtr = uPtr.release();
    assert(uPtr.get() == nullptr);
    assert(*rawPtr == 40);
    delete rawPtr;
}

void testUnqPtrSwap() {
    UnqPtr<int> uPtr(new int(50));
    int* rawPtr = new int(60);
    uPtr.swap(rawPtr);
    assert(*rawPtr == 50);
    assert(*uPtr == 60);
    delete rawPtr;
}

int unqTest() {
    testUnqPtrCreation();
    testUnqPtrMove();
    testUnqPtrReset();
    testUnqPtrRelease();
    testUnqPtrSwap();
    
    std::cout << "UNIQUE POINTER TESTS PASSED" << std::endl;
    return 0;
}
