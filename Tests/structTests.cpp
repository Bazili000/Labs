#include "structTests.h"

void testDynamicArray() {
    DynamicArray<int> arr1;
    assert(arr1.GetSize() == 0);

    DynamicArray<int> arr2(5);
    assert(arr2.GetSize() == 5);

    for (int i = 0; i < 5; ++i) {
        arr2.Set(i, i + 1);
    }
    for (int i = 0; i < 5; ++i) {
        assert(arr2.Get(i) == i + 1);
    }

    try {
        arr2.Get(10);
        assert(false);
    } catch (const std::out_of_range&) {
        assert(true);
    }

    DynamicArray<int> arr3(arr2);
    assert(arr3.GetSize() == arr2.GetSize());
    for (int i = 0; i < arr2.GetSize(); ++i) {
        assert(arr3.Get(i) == arr2.Get(i));
    }

    arr3.Resize(10);
    assert(arr3.GetSize() == 10);
    for (int i = 0; i < 5; ++i) {
        assert(arr3.Get(i) == i + 1);
    }

    arr3.Resize(3);
    assert(arr3.GetSize() == 3);
    for (int i = 0; i < 3; ++i) {
        assert(arr3.Get(i) == i + 1);
    }

    DynamicArray<int> arr4 = std::move(arr3);
    assert(arr4.GetSize() == 3);
    for (int i = 0; i < 3; ++i) {
        assert(arr4.Get(i) == i + 1);
    }
}

void testArraySequence() {
    ArraySequence<int> seq1;
    assert(seq1.getLength() == 0);

    seq1.append(10);
    seq1.append(20);
    seq1.append(30);
    assert(seq1.getLength() == 3);
    assert(seq1.get(0) == 10);
    assert(seq1.get(1) == 20);
    assert(seq1.get(2) == 30);

    seq1.prepend(5);
    assert(seq1.getLength() == 4);
    assert(seq1.get(0) == 5);
    seq1.insertAt(2, 15);
    assert(seq1.getLength() == 5);
    assert(seq1.get(2) == 15);

    assert(seq1.getFirst() == 5);
    assert(seq1.getLast() == 30);

    auto subSeq = seq1.getSubSequence(1, 3);
    assert(subSeq->getLength() == 3);
    assert(subSeq->get(0) == 10);
    assert(subSeq->get(1) == 15);
    assert(subSeq->get(2) == 20);

    seq1.remove(2);
    assert(seq1.getLength() == 4);
    assert(seq1.get(2) == 20);

    ArraySequence<int> seq2;
    seq2.append(40);
    seq2.append(50);
    
    seq1.concat(UnqPtr<Sequence<int>>(new ArraySequence<int>(seq2)));
    
    assert(seq1.getLength() == 6);
    assert(seq1.get(4) == 40);
    assert(seq1.get(5) == 50);
}

void structTest() {
    testDynamicArray();
    testArraySequence();
    std::cout << "STRUCT TESTS PASSED" << std::endl;
}