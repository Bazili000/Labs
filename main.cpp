#include "main.h"

int ArrayUI() {
    std::cout << "Welcome to the ArraySequence UI Test Program!" << std::endl;
    std::cout << "Please choose the type of ArraySequence:" << std::endl;
    std::cout << "1. Integer" << std::endl;
    std::cout << "2. Double" << std::endl;
    std::cout << "3. String" << std::endl;

    int choice = GetValidInput(1, 3);

    if (choice == 1) {
        ArraySequence<int> sequence;
        int option;
        
        while (true) {
            std::cout << "\nMenu:\n";
            std::cout << "1. Add element\n";
            std::cout << "2. Remove element\n";
            std::cout << "3. Get element\n";
            std::cout << "4. ArrayPrint sequence\n";
            std::cout << "5. Get size\n";
            std::cout << "6. Get subsequence\n";
            std::cout << "7. Exit\n";
            
            option = GetValidInput(1, 7);

            if (option == 1) {
                int value = GetValidInput(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                sequence.append(value);
                std::cout << "Element added: " << value << std::endl;
            } 
            else if (option == 2) {
                int index = GetValidInput(0, sequence.getLength() - 1);
                sequence.remove(index);
                std::cout << "Element at index " << index << " removed." << std::endl;
            } 
            else if (option == 3) {
                int index = GetValidInput(0, sequence.getLength() - 1);
                std::cout << "Element at index " << index << " is: " << sequence.get(index) << std::endl;
            } 
            else if (option == 4) {
                std::cout << "Current sequence: ";
                ArrayPrint(sequence);
            } 
            else if (option == 5) {
                std::cout << "Size of the sequence: " << sequence.getLength() << std::endl;
            } 
            else if (option == 6) {
                std::cout << "Enter start index: " << std::endl;
                int startIndex = GetValidInput(0, sequence.getLength() - 1);
                std::cout << "Enter end index: " << std::endl;
                int endIndex = GetValidInput(startIndex, sequence.getLength() - 1);
                UnqPtr<Sequence<int>> subsequence = sequence.getSubSequence(startIndex, endIndex);
                std::cout << "Subsequence from " << startIndex << " to " << endIndex << ": ";
                ArrayPrint(*subsequence);
            } 
            else if (option == 7) {
                std::cout << "Exiting program..." << std::endl;
                break;
            }
        }
    } 
    else if (choice == 2) {
        ArraySequence<double> sequence;
        int option;

        while (true) {
            std::cout << "\nMenu:\n";
            std::cout << "1. Add element\n";
            std::cout << "2. Remove element\n";
            std::cout << "3. Get element\n";
            std::cout << "4. ArrayPrint sequence\n";
            std::cout << "5. Get size\n";
            std::cout << "6. Get subsequence\n";
            std::cout << "7. Exit\n";

            option = GetValidInput(1, 7);

            if (option == 1) {
                double value = GetValidInput(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
                sequence.append(value);
                std::cout << "Element added: " << value << std::endl;
            } 
            else if (option == 2) {
                int index = GetValidInput(0, sequence.getLength() - 1);
                sequence.remove(index);
                std::cout << "Element at index " << index << " removed." << std::endl;
            } 
            else if (option == 3) {
                int index = GetValidInput(0, sequence.getLength() - 1);
                std::cout << "Element at index " << index << " is: " << sequence.get(index) << std::endl;
            } 
            else if (option == 4) {
                std::cout << "Current sequence: ";
                ArrayPrint(sequence);
            } 
            else if (option == 5) {
                std::cout << "Size of the sequence: " << sequence.getLength() << std::endl;
            } 
            else if (option == 6) {
                std::cout << "Enter start index: " << std::endl;
                int startIndex = GetValidInput(0, sequence.getLength() - 1);
                std::cout << "Enter end index: " << std::endl;
                int endIndex = GetValidInput(startIndex, sequence.getLength() - 1);
                UnqPtr<Sequence<double>> subsequence = sequence.getSubSequence(startIndex, endIndex);
                std::cout << "Subsequence from " << startIndex << " to " << endIndex << ": ";
                ArrayPrint(*subsequence);
            } 
            else if (option == 7) {
                std::cout << "Exiting program..." << std::endl;
                break;
            }
        }
    } 
    else if (choice == 3) {
        ArraySequence<std::string> sequence;
        int option;

        while (true) {
            std::cout << "\nMenu:\n";
            std::cout << "1. Add element\n";
            std::cout << "2. Remove element\n";
            std::cout << "3. Get element\n";
            std::cout << "4. ArrayPrint sequence\n";
            std::cout << "5. Get size\n";
            std::cout << "6. Get subsequence\n";
            std::cout << "7. Exit\n";

            option = GetValidInput(1, 7);

            if (option == 1) {
                std::string value;
                std::cout << "Enter value to add: ";
                std::cin >> value;
                sequence.append(value);
                std::cout << "Element added: " << value << std::endl;
            } 
            else if (option == 2) {
                int index = GetValidInput(0, sequence.getLength() - 1);
                sequence.remove(index);
                std::cout << "Element at index " << index << " removed." << std::endl;
            } 
            else if (option == 3) {
                int index = GetValidInput(0, sequence.getLength() - 1);
                std::cout << "Element at index " << index << " is: " << sequence.get(index) << std::endl;
            } 
            else if (option == 4) {
                std::cout << "Current sequence: ";
                ArrayPrint(sequence);
            } 
            else if (option == 5) {
                std::cout << "Size of the sequence: " << sequence.getLength() << std::endl;
            } 
            else if (option == 6) {
                std::cout << "Enter start index: " << std::endl;
                int startIndex = GetValidInput(0, sequence.getLength() - 1);
                std::cout << "Enter end index: " << std::endl;
                int endIndex = GetValidInput(startIndex, sequence.getLength() - 1);
                UnqPtr<Sequence<std::string>> subsequence = sequence.getSubSequence(startIndex, endIndex);
                std::cout << "Subsequence from " << startIndex << " to " << endIndex << ": ";
                ArrayPrint(*subsequence);
            } 
            else if (option == 7) {
                std::cout << "Exiting program..." << std::endl;
                break;
            }
        }
    }

    return 0;
}

int main() {
    int choice;
    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Run Tests\n";
        std::cout << "2. UI Testing\n";
        std::cout << "3. Exit\n";

        choice = GetValidInput(1, 3);

        if (choice == 1) {
            std::cout << "Running tests...\n";
            try {
                test();
                std::cout << "All tests passed successfully!\n";
            } catch (const std::exception& e) {
                std::cout << "Test failed: " << e.what() << std::endl;
            }
        } 

        else if (choice == 2) {
            ArrayUI();
        }

        else if (choice == 3) {
            std::cout << "Exiting program..." << std::endl;
            break;
        }
    }

    return 0;
}
