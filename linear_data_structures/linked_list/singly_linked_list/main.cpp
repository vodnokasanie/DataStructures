#include <iostream>
#include "SinglyLinkedList.h"

void test_push_front() {
    SinglyLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    std::cout << "Test push_front: ";
    list.print();  // Expected: 3 -> 2 -> 1 -> nullptr
}

void test_push_back() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Test push_back: ";
    list.print();  // Expected: 1 -> 2 -> 3 -> nullptr
}

void test_pop_front() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    std::cout << "Test pop_front: ";
    list.print();  // Expected: 2 -> 3 -> nullptr
}

void test_pop_back() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    std::cout << "Test pop_back: ";
    list.print();  // Expected: 1 -> 2 -> nullptr
}

void test_front() {
    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_front(20);
    std::cout << "Test front: " << list.front() << std::endl;  // Expected: 20
}

void test_back() {
    SinglyLinkedList<int> list;
    list.push_front(10);
    list.push_back(20);
    std::cout << "Test back: " << list.back() << std::endl;  // Expected: 20
}

void test_empty() {
    SinglyLinkedList<int> list;
    std::cout << "Test empty: " << (list.empty() ? "true" : "false") << std::endl;  // Expected: true
    list.push_back(1);
    std::cout << "Test empty (after push_back): " << (list.empty() ? "true" : "false") << std::endl;  // Expected: false
}

void test_size() {
    SinglyLinkedList<int> list;
    std::cout << "Test size (empty list): " << list.size() << std::endl;  // Expected: 0
    list.push_back(1);
    list.push_back(2);
    std::cout << "Test size (after 2 pushes): " << list.size() << std::endl;  // Expected: 2
}

void test_clear() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    std::cout << "Test clear: ";
    list.print();  // Expected: -> nullptr
}

void test_copy_constructor() {
    SinglyLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    SinglyLinkedList<int> list2 = list1;
    std::cout << "Test copy constructor: ";
    list2.print();  // Expected: 1 -> 2 -> nullptr
}

void test_assignment_operator() {
    SinglyLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    SinglyLinkedList<int> list2;
    list2 = list1;
    std::cout << "Test assignment operator: ";
    list2.print();  // Expected: 1 -> 2 -> nullptr
}

void test_move_constructor() {
    SinglyLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    SinglyLinkedList<int> list2 = std::move(list1);
    std::cout << "Test move constructor (list1 should be empty): ";
    list1.print();  // Expected: -> nullptr
    std::cout << "Moved list2: ";
    list2.print();  // Expected: 1 -> 2 -> nullptr
}

void test_move_assignment_operator() {
    SinglyLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    SinglyLinkedList<int> list2;
    list2 = std::move(list1);
    std::cout << "Test move assignment operator (list1 should be empty): ";
    list1.print();  // Expected: -> nullptr
    std::cout << "Moved list2: ";
    list2.print();  // Expected: 1 -> 2 -> nullptr
}

void test_combination_push_pop() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.pop_back();
    list.pop_front();
    std::cout << "Test combination push/pop: ";
    list.print();  // Expected: 1 -> nullptr
}

void test_combination_all() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.pop_front();
    list.push_front(10);
    list.pop_back();
    list.push_back(20);
    std::cout << "Test combination all: ";
    list.print();  // Expected: 10 -> 1 -> 20 -> nullptr
}

int main() {
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_front();
    test_back();
    test_empty();
    test_size();
    test_clear();
    test_copy_constructor();
    test_assignment_operator();
    test_move_constructor();
    test_move_assignment_operator();
    test_combination_push_pop();
    test_combination_all();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
