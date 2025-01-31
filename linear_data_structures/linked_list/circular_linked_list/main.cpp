#include "CircularLinkedList.h"
#include <iostream>
#include <cassert>

void test_push_front() {
    CircularLinkedList<int> list;
    list.push_front(10);
    assert(list.front() == 10);
    assert(list.back() == 10);
    assert(list.size() == 1);

    list.push_front(20);
    assert(list.front() == 20);
    assert(list.back() == 10);
    assert(list.size() == 2);

    std::cout << "test_push_front passed.\n";
}

void test_push_back() {
    CircularLinkedList<int> list;
    list.push_back(10);
    assert(list.front() == 10);
    assert(list.back() == 10);
    assert(list.size() == 1);

    list.push_back(20);
    assert(list.front() == 10);
    assert(list.back() == 20);
    assert(list.size() == 2);

    std::cout << "test_push_back passed.\n";
}

void test_pop_front() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    assert(list.front() == 20);
    assert(list.size() == 1);

    list.pop_front();
    assert(list.empty());

    std::cout << "test_pop_front passed.\n";
}

void test_pop_back() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back(); 
    assert(list.back() == 10);
    assert(list.size() == 1);

    list.pop_back();
    assert(list.empty());

    std::cout << "test_pop_back passed.\n";
}

void test_clear() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);

    std::cout << "test_clear passed.\n";
}

void test_front_back() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    assert(list.front() == 10);
    assert(list.back() == 20);

    list.push_front(30);
    assert(list.front() == 30);
    assert(list.back() == 20);

    std::cout << "test_front_back passed.\n";
}

void test_empty_and_size() {
    CircularLinkedList<int> list;
    assert(list.empty());
    assert(list.size() == 0);

    list.push_back(10);
    assert(!list.empty());
    assert(list.size() == 1);

    list.push_back(20);
    assert(list.size() == 2);

    std::cout << "test_empty_and_size passed.\n";
}

void test_copy_constructor() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    CircularLinkedList<int> copyList(list);
    assert(copyList.size() == 2);
    assert(copyList.front() == 10);
    assert(copyList.back() == 20);

    copyList.push_back(30);
    assert(copyList.back() == 30);
    assert(list.back() == 20);  // Original list should remain unchanged

    std::cout << "test_copy_constructor passed.\n";
}

void test_assignment_operator() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    CircularLinkedList<int> assignedList;
    assignedList = list;
    assert(assignedList.size() == 2);
    assert(assignedList.front() == 10);
    assert(assignedList.back() == 20);

    assignedList.push_back(30);
    assert(assignedList.back() == 30);
    assert(list.back() == 20);  // Original list should remain unchanged

    std::cout << "test_assignment_operator passed.\n";
}

void test_move_constructor() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    CircularLinkedList<int> movedList(std::move(list));
    assert(movedList.size() == 2);
    assert(movedList.front() == 10);
    assert(movedList.back() == 20);
    assert(list.empty());  // Original list should be empty after move

    std::cout << "test_move_constructor passed.\n";
}

void test_move_assignment_operator() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    CircularLinkedList<int> movedList;
    movedList = std::move(list);
    assert(movedList.size() == 2);
    assert(movedList.front() == 10);
    assert(movedList.back() == 20);
    assert(list.empty());  // Original list should be empty after move

    std::cout << "test_move_assignment_operator passed.\n";
}

void test_print() {
    CircularLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    std::cout << "Expected output: 10 20 30\nActual output: ";
    list.print();
    std::cout << "test_print passed (verify visually).\n";
}

int main() {
    // Test each functionality independently
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_clear();
    test_front_back();
    test_empty_and_size();

    // Test copy and move constructors and assignment operators
    test_copy_constructor();
    test_assignment_operator();
    test_move_constructor();
    test_move_assignment_operator();

    // Test print function
    test_print();

    std::cout << "All tests passed successfully.\n";
    return 0;
}
