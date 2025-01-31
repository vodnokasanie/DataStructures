#include <iostream>
#include "BinarySearchTree.h"

void testInsert() {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);
    std::cout << "In-order traversal after insertions: ";
    tree.inorderTraversal();
}

void testRemove() {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);
    std::cout << "In-order traversal before removal: ";
    tree.inorderTraversal();

    tree.remove(15);
    std::cout << "In-order traversal after removing 15: ";
    tree.inorderTraversal();

    tree.remove(20);
    std::cout << "In-order traversal after removing 20: ";
    tree.inorderTraversal();
}

void testSearch() {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);

    std::cout << "Search for 15: " << (tree.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 25: " << (tree.search(25) ? "Found" : "Not Found") << std::endl;
}

void testMinMax() {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);

    try {
        std::cout << "Minimum value in the tree: " << tree.min() << std::endl;
        std::cout << "Maximum value in the tree: " << tree.max() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testEmpty() {
    BinarySearchTree<int> tree;
    std::cout << "Tree is empty: " << (tree.empty() ? "Yes" : "No") << std::endl;

    tree.insert(10);
    std::cout << "Tree is empty after insertion: " << (tree.empty() ? "Yes" : "No") << std::endl;

    tree.remove(10);
    std::cout << "Tree is empty after removal: " << (tree.empty() ? "Yes" : "No") << std::endl;
}

void testTraversal() {
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);

    std::cout << "In-order traversal: ";
    tree.inorderTraversal();

    std::cout << "Pre-order traversal: ";
    tree.preorderTraversal();

    std::cout << "Post-order traversal: ";
    tree.postorderTraversal();
}

int main() {
    std::cout << "Testing BinarySearchTree" << std::endl;

    // Sequentially calling the test functions
    testInsert();
    testRemove();
    testSearch();
    testMinMax();
    testEmpty();
    testTraversal();
    std::cout << "All tests are completed successfully." << std::endl;
    return 0;
}
