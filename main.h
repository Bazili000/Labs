#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>
#include <string>
#include <algorithm>

#include "Tests/tests.h"
#include "Utils/GetValidInput.h"
#include "Structures/ArraySequence.h"

template <typename T>
void ArrayPrint(const Sequence<T>& sequence) {
    int length = sequence.getLength();
    if (length == 0) {
        std::cout << "Array is empty." << std::endl;
        return;
    }

    for (int i = 0; i < length; ++i) {
        std::cout << sequence.get(i) << " ";
    }
    std::cout << std::endl;
}
int ArrayUI();
int main();