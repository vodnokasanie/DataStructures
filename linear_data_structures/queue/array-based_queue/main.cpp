#include <iostream>
#include <cassert>
#include "ArrayBasedQueue.h"

// Test the basic constructor and initial conditions
void testConstructor() {
    ArrayBasedQueue<int> queue;
    assert(queue.size() == 0);
    assert(queue.empty());
    std::cout << "testConstructor passed.\n";
}

// Test enqueue functionality and front element access
void testEnqueue() {
    ArrayBasedQueue<int> queue;
    queue.enqueue(10);
    assert(queue.size() == 1);
    assert(queue.front() == 10);
    
    queue.enqueue(20);
    assert(queue.size() == 2);
    assert(queue.front() == 10);

    std::cout << "testEnqueue passed.\n";
}

// Test dequeue functionality
void testDequeue() {
    ArrayBasedQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.dequeue();
    assert(queue.size() == 2);
    assert(queue.front() == 20);

    queue.dequeue();
    assert(queue.size() == 1);
    assert(queue.front() == 30);

    queue.dequeue();
    assert(queue.size() == 0);
    assert(queue.empty());

    std::cout << "testDequeue passed.\n";
}

// Test resizing of the queue
void testResize() {
    ArrayBasedQueue<int> queue(2); // Small initial capacity to trigger resizing
    queue.enqueue(10);
    queue.enqueue(20);

    // Queue should resize when capacity is reached
    queue.enqueue(30);
    assert(queue.size() == 3);
    assert(queue.front() == 10);

    std::cout << "testResize passed.\n";
}

// Test the copy constructor
void testCopyConstructor() {
    ArrayBasedQueue<int> originalQueue;
    originalQueue.enqueue(10);
    originalQueue.enqueue(20);

    ArrayBasedQueue<int> copiedQueue(originalQueue);
    assert(copiedQueue.size() == originalQueue.size());
    assert(copiedQueue.front() == originalQueue.front());

    originalQueue.dequeue();
    assert(copiedQueue.front() == 10); // Verify deep copy

    std::cout << "testCopyConstructor passed.\n";
}

// Test the copy assignment operator
void testCopyAssignment() {
    ArrayBasedQueue<int> queue1;
    queue1.enqueue(10);
    queue1.enqueue(20);

    ArrayBasedQueue<int> queue2;
    queue2 = queue1;

    assert(queue2.size() == queue1.size());
    assert(queue2.front() == queue1.front());

    queue1.dequeue();
    assert(queue2.front() == 10); // Verify deep copy

    std::cout << "testCopyAssignment passed.\n";
}

// Test the move constructor
void testMoveConstructor() {
    ArrayBasedQueue<int> queue1;
    queue1.enqueue(10);
    queue1.enqueue(20);

    ArrayBasedQueue<int> movedQueue(std::move(queue1));
    assert(movedQueue.size() == 2);
    assert(movedQueue.front() == 10);
    assert(queue1.size() == 0); // queue1 should be empty after move

    std::cout << "testMoveConstructor passed.\n";
}

// Test the move assignment operator
void testMoveAssignment() {
    ArrayBasedQueue<int> queue1;
    queue1.enqueue(10);
    queue1.enqueue(20);

    ArrayBasedQueue<int> queue2;
    queue2 = std::move(queue1);

    assert(queue2.size() == 2);
    assert(queue2.front() == 10);
    assert(queue1.size() == 0); // queue1 should be empty after move

    std::cout << "testMoveAssignment passed.\n";
}

// Test enqueueing and dequeuing in combination to trigger wrap-around behavior
void testWrapAround() {
    ArrayBasedQueue<int> queue(5); // Small capacity for easy wrap-around testing
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.dequeue();
    queue.dequeue();
    
    queue.enqueue(60);
    queue.enqueue(70);

    assert(queue.size() == 5);
    assert(queue.front() == 30);

    std::cout << "testWrapAround passed.\n";
}

// Test front element access
void testFront() {
    ArrayBasedQueue<int> queue;
    queue.enqueue(10);
    assert(queue.front() == 10);

    queue.enqueue(20);
    queue.dequeue();
    assert(queue.front() == 20);

    std::cout << "testFront passed.\n";
}

// Main function to run all test cases
int main() {
    testConstructor();
    testEnqueue();
    testDequeue();
    testResize();
    testCopyConstructor();
    testCopyAssignment();
    testMoveConstructor();
    testMoveAssignment();
    testWrapAround();
    testFront();

    std::cout << "All tests passed successfully.\n";
    return 0;
}
