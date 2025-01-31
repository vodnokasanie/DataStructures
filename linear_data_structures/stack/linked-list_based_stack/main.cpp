#include <iostream>
#include "LinkedListBasedStack.h"

void testPush() {
    LinkedListBasedStack<int> stack;
    std::cout << "Testing push:\n";
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
        std::cout << "Pushed " << i << ", stack size: " << stack.size() << ", top: " << stack.top() << "\n";
    }
}

void testPop() {
    LinkedListBasedStack<int> stack;
    std::cout << "\nTesting pop:\n";
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
    }
    while (!stack.empty()) {
        std::cout << "Top before pop: " << stack.top() << ", ";
        stack.pop();
        std::cout << "popped, stack size: " << stack.size() << "\n";
    }
}

void testTop() {
    LinkedListBasedStack<int> stack;
    std::cout << "\nTesting top:\n";
    stack.push(10);
    std::cout << "Top element: " << stack.top() << "\n";
    stack.push(20);
    std::cout << "Top element after pushing 20: " << stack.top() << "\n";
}

void testEmpty() {
    LinkedListBasedStack<int> stack;
    std::cout << "\nTesting empty:\n";
    std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << "\n";
    stack.push(1);
    std::cout << "Is stack empty after pushing 1? " << (stack.empty() ? "Yes" : "No") << "\n";
}

void testCopyConstructor() {
    LinkedListBasedStack<int> stack;
    for (int i = 1; i <= 3; ++i) {
        stack.push(i);
    }

    LinkedListBasedStack<int> copiedStack(stack);
    std::cout << "\nTesting copy constructor:\n";
    while (!copiedStack.empty()) {
        std::cout << "Top of copied stack: " << copiedStack.top() << "\n";
        copiedStack.pop();
    }
}

void testAssignmentOperator() {
    LinkedListBasedStack<int> stack1;
    for (int i = 1; i <= 3; ++i) {
        stack1.push(i);
    }

    LinkedListBasedStack<int> stack2;
    stack2 = stack1;

    std::cout << "\nTesting assignment operator:\n";
    while (!stack2.empty()) {
        std::cout << "Top of assigned stack: " << stack2.top() << "\n";
        stack2.pop();
    }
}

void testMoveConstructor() {
    LinkedListBasedStack<int> stack;
    for (int i = 1; i <= 3; ++i) {
        stack.push(i);
    }

    LinkedListBasedStack<int> movedStack(std::move(stack));
    std::cout << "\nTesting move constructor:\n";
    while (!movedStack.empty()) {
        std::cout << "Top of moved stack: " << movedStack.top() << "\n";
        movedStack.pop();
    }
    std::cout << "Original stack size after move: " << stack.size() << "\n";
}

void testMoveAssignmentOperator() {
    LinkedListBasedStack<int> stack1;
    for (int i = 1; i <= 3; ++i) {
        stack1.push(i);
    }

    LinkedListBasedStack<int> stack2;
    stack2 = std::move(stack1);

    std::cout << "\nTesting move assignment operator:\n";
    while (!stack2.empty()) {
        std::cout << "Top of moved-assigned stack: " << stack2.top() << "\n";
        stack2.pop();
    }
    std::cout << "Original stack size after move-assignment: " << stack1.size() << "\n";
}

int main() {
    testPush();
    testPop();
    testTop();
    testEmpty();
    testCopyConstructor();
    testAssignmentOperator();
    testMoveConstructor();
    testMoveAssignmentOperator();
    std::cout << "All tests completed successfully." << std::endl;
    return 0;
}
