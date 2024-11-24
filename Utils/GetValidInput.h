#pragma once
#include <iostream>
#include <limits>
#include <type_traits>

template <typename T>
T GetValidInput(T minValue, T maxValue) {
    T userInput;

    while (true) {
        std::cout << "Выберите значение (от " << minValue << " до " << maxValue << "): ";
        std::cin >> userInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Попробуйте снова." << std::endl;
            continue;
        }

        if (userInput >= minValue && userInput <= maxValue) {
            std::cout << "\n" << std::endl;
            return userInput;
        } else {
            std::cout << "Число вне диапазона. Выберите значение (от " << minValue << " до " << maxValue << "): "<< std::endl;
        }
    }
}
