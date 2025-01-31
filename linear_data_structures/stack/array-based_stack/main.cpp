#include "ArrayBasedStack.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_push_and_top() {
    ArrayBasedStack<int> stack;
    stack.push(10);
    assert(stack.top() == 10);

    stack.push(20);
    assert(stack.top() == 20);

    std::cout << "test_push_and_top passed.\n";
}

void test_pop() {
    ArrayBasedStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.pop();
    assert(stack.top() == 10);

    stack.pop();
    assert(stack.empty());

    std::cout << "test_pop passed.\n";
}

void test_resize() {
    ArrayBasedStack<int> stack;
    for (int i = 0; i < 100; ++i) {
        stack.push(i);
    }
    assert(stack.size() == 100);
    assert(stack.top() == 99);

    std::cout << "test_resize passed.\n";
}

void test_copy_constructor() {
    ArrayBasedStack<int> stack;
    stack.push(10);
    stack.push(20);

    ArrayBasedStack<int> copiedStack(stack);
    assert(copiedStack.size() == 2);
    assert(copiedStack.top() == 20);

    copiedStack.push(30);
    assert(copiedStack.top() == 30);
    assert(stack.top() == 20); // Original stack should remain unchanged

    std::cout << "test_copy_constructor passed.\n";
}

void test_copy_assignment() {
    ArrayBasedStack<int> stack;
    stack.push(10);
    stack.push(20);

    ArrayBasedStack<int> assignedStack;
    assignedStack = stack;
    assert(assignedStack.size() == 2);
    assert(assignedStack.top() == 20);

    assignedStack.push(30);
    assert(assignedStack.top() == 30);
    assert(stack.top() == 20); // Original stack should remain unchanged

    std::cout << "test_copy_assignment passed.\n";
}

void test_move_constructor() {
    ArrayBasedStack<int> stack;
    stack.push(10);
    stack.push(20);

    ArrayBasedStack<int> movedStack(std::move(stack));
    assert(movedStack.size() == 2);
    assert(movedStack.top() == 20);
    assert(stack.empty()); // Original stack should be empty after move

    std::cout << "test_move_constructor passed.\n";
}

void test_move_assignment() {
    ArrayBasedStack<int> stack;
    stack.push(10);
    stack.push(20);

    ArrayBasedStack<int> movedStack;
    movedStack = std::move(stack);
    assert(movedStack.size() == 2);
    assert(movedStack.top() == 20);
    assert(stack.empty()); // Original stack should be empty after move

    std::cout << "test_move_assignment passed.\n";
}

void test_exceptions() {
    ArrayBasedStack<int> stack;

    try {
        stack.pop();
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {
        std::cout << "Pop exception test passed.\n";
    }

    try {
        stack.top();
        assert(false); // Should not reach here
    } catch (const std::out_of_range&) {
        std::cout << "Top exception test passed.\n";
    }
}

void test_empty() {
    ArrayBasedStack<int> stack;
    assert(stack.empty());

    stack.push(1);
    assert(!stack.empty());

    stack.pop();
    assert(stack.empty());

    std::cout << "test_empty passed.\n";
}

int main() {
    test_push_and_top();
    test_pop();
    test_resize();
    test_copy_constructor();
    test_copy_assignment();
    test_move_constructor();
    test_move_assignment();
    test_exceptions();
    test_empty();

    std::cout << "All tests passed.\n";
    return 0;
}
