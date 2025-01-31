#include "CircularQueue.h"
#include <iostream>
#include <stdexcept>
#include <cassert>


void testEnqueue() {
    CircularQueue<int> queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Check that queue is full and throws an exception if overfilled
    try {
        queue.enqueue(4);
        std::cout << "testEnqueue: Failed (should have thrown)\n";
    } catch (const std::out_of_range&) {
        std::cout << "testEnqueue: Passed\n";
    }
}

void testDequeue() {
    CircularQueue<int> queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.dequeue();
    assert(queue.size() == 2);

    queue.dequeue();
    assert(queue.size() == 1);

    queue.dequeue();
    assert(queue.size() == 0);

    // Check that dequeueing from an empty queue throws an exception
    try {
        queue.dequeue();
        std::cout << "testDequeue: Failed (should have thrown)\n";
    } catch (const std::out_of_range&) {
        std::cout << "testDequeue: Passed\n";
    }
}

void testFront() {
    CircularQueue<int> queue(3);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    assert(queue.front() == 10);
    queue.dequeue();
    assert(queue.front() == 20);

    queue.dequeue();
    assert(queue.front() == 30);

    std::cout << "testFront: Passed\n";
}

void testEmpty() {
    CircularQueue<int> queue(3);
    assert(queue.empty());

    queue.enqueue(5);
    assert(!queue.empty());

    queue.dequeue();
    assert(queue.empty());

    std::cout << "testEmpty: Passed\n";
}

void testFull() {
    CircularQueue<int> queue(2);
    queue.enqueue(1);
    queue.enqueue(2);

    assert(queue.full());

    queue.dequeue();
    assert(!queue.full());

    std::cout << "testFull: Passed\n";
}

void testSize() {
    CircularQueue<int> queue(3);
    assert(queue.size() == 0);

    queue.enqueue(5);
    assert(queue.size() == 1);

    queue.enqueue(10);
    assert(queue.size() == 2);

    queue.dequeue();
    assert(queue.size() == 1);

    std::cout << "testSize: Passed\n";
}

void testCopyConstructor() {
    CircularQueue<int> original(3);
    original.enqueue(1);
    original.enqueue(2);
    original.enqueue(3);

    CircularQueue<int> copy = original;

    assert(copy.size() == original.size());
    assert(copy.front() == original.front());

    // Test independence of copies
    copy.dequeue();
    assert(copy.size() == 2);
    assert(original.size() == 3);

    std::cout << "testCopyConstructor: Passed\n";
}

void testCopyAssignment() {
    CircularQueue<int> queue1(3);
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    CircularQueue<int> queue2;
    queue2 = queue1;

    assert(queue2.size() == queue1.size());
    assert(queue2.front() == queue1.front());

    // Test independence of copies
    queue2.dequeue();
    assert(queue2.size() == 2);
    assert(queue1.size() == 3);

    std::cout << "testCopyAssignment: Passed\n";
}

void testMoveConstructor() {
    CircularQueue<int> queue1(3);
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    CircularQueue<int> queue2 = std::move(queue1);

    assert(queue2.size() == 3);
    assert(queue2.front() == 1);

    // queue1 should be in a valid but empty state
    assert(queue1.size() == 0);
    assert(queue1.empty());

    std::cout << "testMoveConstructor: Passed\n";
}

void testMoveAssignment() {
    CircularQueue<int> queue1(3);
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    CircularQueue<int> queue2;
    queue2 = std::move(queue1);

    assert(queue2.size() == 3);
    assert(queue2.front() == 1);

    // queue1 should be in a valid but empty state
    assert(queue1.size() == 0);
    assert(queue1.empty());

    std::cout << "testMoveAssignment: Passed\n";
}


int main() {
    testEnqueue();
    testDequeue();
    testFront();
    testEmpty();
    testFull();
    testSize();
    testCopyConstructor();
    testCopyAssignment();
    testMoveConstructor();
    testMoveAssignment();

    std::cout << "All tests completed.\n";
    return 0;
}
