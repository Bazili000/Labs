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

void testUnqPtrNullptr() {
    UnqPtr<int> nullPtr(nullptr);
    assert(nullPtr.get() == nullptr);

    try {
        int value = *nullPtr;
        (void)value;
        assert(false); // never
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Empty pointer");
    }

    try {
        int value = *(nullPtr.operator->());
        (void)value;
        assert(false); // never
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Empty pointer");
    }
}

// unique-array tests

void testUnqPtrArrayCreation() {
    UnqPtr<int[]> uPtr(new int[3]{1, 2, 3});
    assert(uPtr.get() != nullptr);
    assert(uPtr[0] == 1);
    assert(uPtr[1] == 2);
    assert(uPtr[2] == 3);
}

void testUnqPtrArrayMove() {
    UnqPtr<int[]> uPtr1(new int[3]{4, 5, 6});
    UnqPtr<int[]> uPtr2 = std::move(uPtr1);
    assert(uPtr1.get() == nullptr);
    assert(uPtr2.get() != nullptr);
    assert(uPtr2[0] == 4);
    assert(uPtr2[1] == 5);
    assert(uPtr2[2] == 6);
}

void testUnqPtrArrayReset() {
    UnqPtr<int[]> uPtr(new int[3]{7, 8, 9});
    uPtr.reset(new int[2]{10, 11});
    assert(uPtr[0] == 10);
    assert(uPtr[1] == 11);
    uPtr.reset();
    assert(uPtr.get() == nullptr);
}

void testUnqPtrArrayRelease() {
    UnqPtr<int[]> uPtr(new int[3]{12, 13, 14});
    int* rawPtr = uPtr.release();
    assert(uPtr.get() == nullptr);
    assert(rawPtr[0] == 12);
    assert(rawPtr[1] == 13);
    assert(rawPtr[2] == 14);
    delete[] rawPtr;
}

void testUnqPtrArraySwap() {
    UnqPtr<int[]> uPtr(new int[2]{15, 16});
    UnqPtr<int[]> uPtr2(new int[2]{17, 18});
    uPtr.swap(uPtr2);
    assert(uPtr[0] == 17);
    assert(uPtr[1] == 18);
    assert(uPtr2[0] == 15);
    assert(uPtr2[1] == 16);
}


void testUnqPtrArrayNullptr() {
    UnqPtr<int[]> nullPtr(nullptr);
    assert(nullPtr.get() == nullptr);

    try {
        int value = nullPtr[0];
        (void)value;
        assert(false); // never
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Empty pointer");
    }
}

int unqTest() {
    testUnqPtrCreation();
    testUnqPtrMove();
    testUnqPtrReset();
    testUnqPtrRelease();
    testUnqPtrSwap();
    testUnqPtrNullptr();

    testUnqPtrArrayCreation();
    testUnqPtrArrayMove();
    testUnqPtrArrayReset();
    testUnqPtrArrayRelease();
    testUnqPtrArraySwap();
    testUnqPtrArrayNullptr();
    
    std::cout << "UNIQUE POINTER TESTS PASSED" << std::endl;
    return 0;
}
