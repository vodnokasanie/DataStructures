#include <iostream>
#include "StaticArray.h"

int main() {
    // Create a StaticArray of integers with a size of 5
    constexpr size_t size = 5;
    StaticArray<int, size> arr1;

    // Test the fill function
    arr1.fill(3);
    std::cout << "Array after fill(3): ";
    arr1.print();

    // Test front and back functions
    std::cout << "Front element: " << arr1.front() << std::endl;
    std::cout << "Back element: " << arr1.back() << std::endl;

    // Test operator[] and at() functions
    arr1[2] = 10;
    std::cout << "Array after setting arr1[2] = 10: ";
    arr1.print();

    try {
        std::cout << "Accessing element at index 2 using at(): " << arr1.at(2) << std::endl;
        std::cout << "Accessing element at index 6 using at(): ";
        arr1.at(6);  // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // Test size, max_size, and empty functions
    std::cout << "Array size: " << arr1.size() << std::endl;
    std::cout << "Max size of the array: " << arr1.max_size() << std::endl;
    std::cout << "Is array empty? " << (arr1.empty() ? "Yes" : "No") << std::endl;

    // Test copy constructor
    StaticArray<int, size> arr2 = arr1;
    std::cout << "Copied array using copy constructor: ";
    arr2.print();

    // Test assignment operator
    StaticArray<int, size> arr3;
    arr3 = arr1;
    std::cout << "Array after assignment (arr3 = arr1): ";
    arr3.print();

    // Test swap function
    StaticArray<int, size> arr4;
    arr4.fill(7);
    std::cout << "arr4 before swap: ";
    arr4.print();
    arr1.swap(arr4);
    std::cout << "arr1 after swap with arr4: ";
    arr1.print();
    std::cout << "arr4 after swap with arr1: ";
    arr4.print();

    // Test find function
    size_t pos = arr1.find(3);
    if (pos < arr1.size()) {
        std::cout << "Value 3 found at position: " << pos << std::endl;
    } else {
        std::cout << "Value 3 not found in arr1." << std::endl;
    }

    // Test clear function (filling with default values)
    arr1.clear();
    std::cout << "Array after clear(): ";
    arr1.print();

    // Test begin and end functions
    std::cout << "Iterating over array using begin() and end(): ";
    for (auto it = arr3.begin(); it != arr3.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
