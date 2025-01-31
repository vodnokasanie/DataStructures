#include <iostream>
#include "DynamicArray.h"
#include <cassert>

int main() {
    // Testing default constructor
    DynamicArray<int> arr1;
    assert(arr1.size() == 0);
    assert(arr1.capacity() == 0);
    assert(arr1.empty());

    // Testing constructor with initial size
    DynamicArray<int> arr2(5);
    assert(arr2.size() == 5);
    assert(arr2.capacity() == 5);
    for (size_t i = 0; i < arr2.size(); ++i) {
        assert(arr2[i] == 0); // Default initialized to zero
    }

    // Testing push_back
    arr2.push_back(10);
    assert(arr2.size() == 6);
    assert(arr2.back() == 10);

    // Testing pop_back
    arr2.pop_back();
    assert(arr2.size() == 5);

    // Testing clear
    arr2.clear();
    assert(arr2.size() == 0);
    assert(arr2.capacity() == 0);
    assert(arr2.empty());

    // Testing copy constructor
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    DynamicArray<int> arr3(arr2);
    assert(arr3.size() == arr2.size());
    for (size_t i = 0; i < arr2.size(); ++i) {
        assert(arr3[i] == arr2[i]);
    }

    // Testing copy assignment operator
    DynamicArray<int> arr4;
    arr4 = arr2;
    assert(arr4.size() == arr2.size());
    for (size_t i = 0; i < arr2.size(); ++i) {
        assert(arr4[i] == arr2[i]);
    }

    // Testing move constructor
    DynamicArray<int> arr5(std::move(arr2));
    assert(arr5.size() == arr3.size());
    assert(arr2.size() == 0); // Moved-from object should be empty

    // Testing move assignment operator
    DynamicArray<int> arr6;
    arr6 = std::move(arr3);
    assert(arr6.size() == arr5.size());
    assert(arr3.size() == 0); // Moved-from object should be empty

    // Testing reserve
    arr6.reserve(10);
    assert(arr6.capacity() >= 10);

    // Testing resize
    arr6.resize(8);
    assert(arr6.size() == 8);

    // Testing at() with valid and invalid indices
    try {
        arr6.at(0) = 100;
        std::cout << "arr6.at(0): " << arr6.at(0) << std::endl;
        assert(arr6.at(0) == 100);

        // This should throw an exception
        arr6.at(20) = 200;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception for out-of-bounds access: " << e.what() << std::endl;
    }

    // Testing front() and back()
    arr6.front() = 500;
    arr6.back() = 600;
    assert(arr6.front() == 500);
    assert(arr6.back() == 600);

    // Testing data() method
    int* rawData = arr6.data();
    assert(rawData == arr6.data());

    // Testing empty() method
    DynamicArray<int> emptyArr;
    assert(emptyArr.empty());

    // Testing print() method
    std::cout << "arr6 contents: ";
    arr6.print();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
