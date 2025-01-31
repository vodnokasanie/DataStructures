#include "Deque.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

void testPushBack() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    assert(deque.size() == 3);
    assert(deque.front() == 1);
    assert(deque.back() == 3);

    std::cout << "testPushBack: Passed\n";
}

void testPushFront() {
    Deque<int> deque;
    deque.pushFront(1);
    deque.pushFront(2);
    deque.pushFront(3);

    assert(deque.size() == 3);
    assert(deque.front() == 3);
    assert(deque.back() == 1);

    std::cout << "testPushFront: Passed\n";
}

void testPopBack() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    deque.popBack();
    assert(deque.size() == 2);
    assert(deque.back() == 2);

    deque.popBack();
    assert(deque.size() == 1);
    assert(deque.back() == 1);

    deque.popBack();
    assert(deque.empty());

    std::cout << "testPopBack: Passed\n";
}

void testPopFront() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushBack(3);

    deque.popFront();
    assert(deque.size() == 2);
    assert(deque.front() == 2);

    deque.popFront();
    assert(deque.size() == 1);
    assert(deque.front() == 3);

    deque.popFront();
    assert(deque.empty());

    std::cout << "testPopFront: Passed\n";
}

void testFrontBack() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);

    assert(deque.front() == 1);
    assert(deque.back() == 2);

    deque.pushFront(3);
    assert(deque.front() == 3);
    assert(deque.back() == 2);

    std::cout << "testFrontBack: Passed\n";
}

void testEmpty() {
    Deque<int> deque;
    assert(deque.empty());

    deque.pushBack(1);
    assert(!deque.empty());

    deque.popBack();
    assert(deque.empty());

    std::cout << "testEmpty: Passed\n";
}

void testResize() {
    Deque<int> deque(2); // Start with a small capacity
    deque.pushBack(1);
    deque.pushBack(2);
    assert(deque.size() == 2);

    deque.pushBack(3); // This should trigger a resize
    assert(deque.size() == 3);
    assert(deque.front() == 1);
    assert(deque.back() == 3);

    std::cout << "testResize: Passed\n";
}

void testCopyConstructor() {
    Deque<int> original;
    original.pushBack(1);
    original.pushBack(2);
    original.pushBack(3);

    Deque<int> copy = original;

    assert(copy.size() == original.size());
    assert(copy.front() == original.front());
    assert(copy.back() == original.back());

    // Ensure they are independent
    copy.popBack();
    assert(copy.size() == 2);
    assert(original.size() == 3);

    std::cout << "testCopyConstructor: Passed\n";
}

void testCopyAssignment() {
    Deque<int> deque1;
    deque1.pushBack(1);
    deque1.pushBack(2);
    deque1.pushBack(3);

    Deque<int> deque2;
    deque2 = deque1;

    assert(deque2.size() == deque1.size());
    assert(deque2.front() == deque1.front());

    // Ensure they are independent
    deque2.popBack();
    assert(deque2.size() == 2);
    assert(deque1.size() == 3);

    std::cout << "testCopyAssignment: Passed\n";
}

void testMoveConstructor() {
    Deque<int> deque1;
    deque1.pushBack(1);
    deque1.pushBack(2);
    deque1.pushBack(3);

    Deque<int> deque2 = std::move(deque1);

    assert(deque2.size() == 3);
    assert(deque2.front() == 1);

    // deque1 should be in a valid but empty state
    assert(deque1.size() == 0);
    assert(deque1.empty());

    std::cout << "testMoveConstructor: Passed\n";
}

void testMoveAssignment() {
    Deque<int> deque1;
    deque1.pushBack(1);
    deque1.pushBack(2);
    deque1.pushBack(3);

    Deque<int> deque2;
    deque2 = std::move(deque1);

    assert(deque2.size() == 3);
    assert(deque2.front() == 1);

    // deque1 should be in a valid but empty state
    assert(deque1.size() == 0);
    assert(deque1.empty());

    std::cout << "testMoveAssignment: Passed\n";
}

int main() {
    testPushBack();
    testPushFront();
    testPopBack();
    testPopFront();
    testFrontBack();
    testEmpty();
    testResize();
    testCopyConstructor();
    testCopyAssignment();
    testMoveConstructor();
    testMoveAssignment();

    std::cout << "All tests completed.\n";
    return 0;
}
