#include "LinkedListBasedQueue.h"
#include <iostream>
#include <cassert>

void testEnqueueDequeue() {
    LinkedListBasedQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    assert(queue.size() == 3);
    assert(queue.front() == 10);
    
    queue.dequeue();
    assert(queue.front() == 20);
    
    queue.dequeue();
    assert(queue.front() == 30);
    
    queue.dequeue();
    assert(queue.empty());

    std::cout << "testEnqueueDequeue passed.\n";
}

void testCopyConstructor() {
    LinkedListBasedQueue<int> originalQueue;
    originalQueue.enqueue(1);
    originalQueue.enqueue(2);
    originalQueue.enqueue(3);
    
    LinkedListBasedQueue<int> copiedQueue(originalQueue);


    assert(copiedQueue.size() == 3);
    assert(copiedQueue.front() == 1);

    originalQueue.dequeue();
    assert(copiedQueue.front() == 1); // Ensure copied queue is unaffected
    
    std::cout << "testCopyConstructor passed.\n";
}




void testAssignmentOperator() {
    LinkedListBasedQueue<int> queue1;
    queue1.enqueue(5);
    queue1.enqueue(10);
    queue1.enqueue(15);
    
    LinkedListBasedQueue<int> queue2;
    queue2 = queue1;  // Assignment
    
    assert(queue2.size() == 3);
    assert(queue2.front() == 5);
    
    queue1.dequeue();
    assert(queue2.front() == 5); // Ensure queue2 is unaffected

    std::cout << "testAssignmentOperator passed.\n";
}

void testMoveConstructor() {
    LinkedListBasedQueue<int> originalQueue;
    originalQueue.enqueue(100);
    originalQueue.enqueue(200);
    
    LinkedListBasedQueue<int> movedQueue(std::move(originalQueue));
    
    assert(movedQueue.size() == 2);
    assert(movedQueue.front() == 100);
    assert(originalQueue.empty());

    std::cout << "testMoveConstructor passed.\n";
}

void testMoveAssignmentOperator() {
    LinkedListBasedQueue<int> queue1;
    queue1.enqueue(1);
    queue1.enqueue(2);
    
    LinkedListBasedQueue<int> queue2;
    queue2 = std::move(queue1);
    
    assert(queue2.size() == 2);
    assert(queue2.front() == 1);
    assert(queue1.empty());

    std::cout << "testMoveAssignmentOperator passed.\n";
}

void testFrontAndSize() {
    LinkedListBasedQueue<int> queue;
    queue.enqueue(42);
    queue.enqueue(43);
    
    assert(queue.front() == 42);
    assert(queue.size() == 2);
    
    queue.dequeue();
    assert(queue.front() == 43);
    assert(queue.size() == 1);
    
    queue.dequeue();
    assert(queue.empty());

    std::cout << "testFrontAndSize passed.\n";
}

void testEmptyQueueDequeue() {
    LinkedListBasedQueue<int> queue;
    try {
        queue.dequeue();
        assert(false); // Should not reach here, as exception is expected
    } catch (const std::out_of_range& e) {
        std::cout << "testEmptyQueueDequeue passed with exception: " << e.what() << "\n";
    }
}

void testMemoryManagement() {
    LinkedListBasedQueue<int> queue;
    for (int i = 0; i < 1000; ++i) {
        queue.enqueue(i);
    }
    
    for (int i = 0; i < 1000; ++i) {
        queue.dequeue();
    }

    assert(queue.empty());
    std::cout << "testMemoryManagement passed.\n";
}



int main() {
    testEnqueueDequeue();
    testCopyConstructor();
    testAssignmentOperator();
    testMoveConstructor();
    testMoveAssignmentOperator();
    testFrontAndSize();
    testEmptyQueueDequeue();
    testMemoryManagement();

    std::cout << "All tests passed successfully.\n";
    return 0;
}
