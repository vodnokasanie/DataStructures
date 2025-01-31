#include <iostream>
#include "DoublyLinkedList.h"

void testEmptyAndSize() {
    DoublyLinkedList<int> list;
    std::cout << "Test empty and size on an empty list:\n";
    std::cout << "Initial size: " << list.size() << std::endl;  // Expected: 0
    std::cout << "Is empty? " << list.empty() << std::endl;     // Expected: 1 (true)
    std::cout << std::endl;
}

void testPushBackAndPushFront() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    std::cout << "Test push_back(1): front = " << list.front() << ", back = " << list.back() << "\n";  // Expected: front = 1, back = 1
    list.push_front(2);
    std::cout << "Test push_front(2): front = " << list.front() << ", back = " << list.back() << "\n"; // Expected: front = 2, back = 1
    list.push_back(3);
    list.push_front(4);
    std::cout << "After push_back(3) and push_front(4): ";
    list.printForward();
    list.printBackward();  // Expected order: 4 -> 2 -> 1 -> 3 -> nullptr
    std::cout << std::endl;
}

void testPopBackAndPopFront() {
    DoublyLinkedList<int> list;
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);

    list.pop_back();
    std::cout << "After pop_back: ";
    list.printForward();
    list.printBackward();  // Expected order: 4 -> 3 -> 2 -> nullptr

    list.pop_front();
    std::cout << "After pop_front: ";
    list.printForward();
    list.printBackward();  // Expected order: 3 -> 2 -> nullptr
    std::cout << std::endl;
}

void testCopyConstructor() {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);

    DoublyLinkedList<int> listCopy(list);
    std::cout << "Test copy constructor, copied list: ";
    list.printForward();
    list.printBackward();  // Expected order: 2 -> 1 -> nullptr

    list.push_back(5);
    std::cout << "Original list after push_back(5): ";
    list.printForward();
    list.printBackward();  // Expected order: 2 -> 1 -> 5 -> nullptr

    std::cout << "Copied list remains unchanged: ";
    listCopy.printForward();
    listCopy.printBackward(); // Expected order: 2 -> 1 -> nullptr
    std::cout << std::endl;
}

void testAssignmentOperator() {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    list.push_back(5);

    DoublyLinkedList<int> listCopy;
    listCopy = list;
    std::cout << "After assigning original list to copied list: ";
    list.printForward();
    list.printBackward(); // Expected order: 2 -> 1 -> 5 -> nullptr
    std::cout << std::endl;
}

void testMoveConstructor() {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    list.push_back(5);
    std::cout << "Moved list: ";
    list.printForward();
    list.printBackward();
    DoublyLinkedList<int> listMoved(std::move(list));  // Expected order: 2 -> 1 -> 5 -> nullptr
    std::cout << "Original list after move: ";
    list.printForward();
    list.printBackward(); 
    std::cout << "New emerged list: " << std::endl; 
    listMoved.printForward();
    listMoved.printBackward(); 
    std::cout << std::endl;
}

void testMoveAssignmentOperator() {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    list.push_back(5);

    DoublyLinkedList<int> listAssigned;
    listAssigned = std::move(list);
    std::cout << "List after move assignment: ";
    list.printForward();
    list.printBackward();  // Expected order: 2 -> 1 -> 5 -> nullptr
    std::cout << "Moved-from list should now be empty: ";
    list.printForward();
    list.printBackward();          // Expected: empty list (nullptr)
    std::cout << std::endl;
}

void testClearFunction() {
    DoublyLinkedList<int> list;
    list.push_back(2);
    list.push_back(1);
    list.push_back(5);

    list.clear();
    std::cout << "After clear, list size: " << list.size() << std::endl;  // Expected: 0
    std::cout << "Is empty? " << list.empty() << std::endl;  // Expected: 1 (true)
    list.printForward();
    list.printBackward();  // Expected: nullptr
    std::cout << std::endl;
}

void testChainingOperations() {
    DoublyLinkedList<int> list;
    list.push_back(6);
    list.push_back(7);
    list.push_front(5);

    std::cout << "Chaining push_back and push_front operations: ";
    list.printForward();
    list.printBackward();  // Expected order: 5 -> 6 -> 7 -> nullptr
    std::cout << std::endl;
}

void testEdgeCases() {
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.pop_front();
    std::cout << "After push_back(10) and pop_front on single-item list: ";
    list.printForward();
    list.printBackward();  // Expected: nullptr

    list.push_back(20);
    list.pop_back();
    std::cout << "After push_back(20) and pop_back on single-item list: ";
    list.printForward();
    list.printBackward();  // Expected: nullptr
    std::cout << std::endl;
}

int main() {
    std::cout << "Running tests for DoublyLinkedList...\n" << std::endl;

    testEmptyAndSize();
    testPushBackAndPushFront();
    testPopBackAndPopFront();
    testCopyConstructor();
    testAssignmentOperator();
    testMoveConstructor();
    testMoveAssignmentOperator();
    testClearFunction();
    testChainingOperations();
    testEdgeCases();

    std::cout << "All tests successfully completed.\n";
    return 0;
}
