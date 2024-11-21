#include <iostream>
#include "Tests/tests.h"

int main() {
    try {
        test();
        return 0;
    }

    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}