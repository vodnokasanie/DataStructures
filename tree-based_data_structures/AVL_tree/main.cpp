#include "AVLtree.h"
#include <iostream>
#include <cassert>

void testInsertionBalancing() {
    AVLtree<int> tree;

    // Insert nodes in an order that will cause the tree to rebalance
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);  // Should trigger a left rotation
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);   // Should balance without rotation
    tree.insert(3);   // Should trigger a right rotation

    // Expected balanced tree structure:
    //       15
    //      /  \
    //     5    20
    //    / \   / \
    //   3  10  18  30
    assert(tree.search(15) == true);
    assert(tree.search(20) == true);
    assert(tree.search(30) == true);
    assert(tree.search(10) == true);
    assert(tree.search(5) == true);
    assert(tree.search(3) == true);
    tree.print(std::cout);
    // Check tree traversal after balancing
    std::cout << "Inorder traversal after insertion balancing (should be sorted): ";
    tree.inorderTraversal(); // Expected output: 3 5 10 15 18 20 30
}

void testDeletionBalancing() {
    AVLtree<int> tree;

    // Build tree with insertions
    tree.insert(80);
    tree.insert(70);
    tree.insert(60);
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(20);
    tree.print(std::cout);
    // Expected balanced tree structure:
    //       50
    //      /  \
    //     30   70
    //    / \   / \
    //   20 40 60 80

    // Remove nodes and check rebalancing
    tree.remove(20);  // No rotation required
    tree.remove(40);  // No rotation required
    tree.remove(30);  // Rotation required to maintain balance
    tree.remove(50);  // Rotation required to maintain balance

    // Check remaining structure and balance:
    //      60
    //     /  \
    //    70   80
    assert(tree.search(60) == true);
    assert(tree.search(70) == true);
    assert(tree.search(80) == true);
    assert(tree.search(20) == false);
    assert(tree.search(40) == false);

    std::cout << "Inorder traversal after deletion balancing (should be sorted): ";
    tree.inorderTraversal(); // Expected output: 60 70 80
}

void testMinMax() {
    AVLtree<int> tree;

    // Insert nodes and verify min and max values
    tree.insert(45);
    tree.insert(10);
    tree.insert(20);
    tree.insert(50);
    tree.insert(60);
    tree.insert(5);

    assert(tree.min() == 5);
    assert(tree.max() == 60);

    std::cout << "Min value: " << tree.min() << " (Expected: 5)" << std::endl;
    std::cout << "Max value: " << tree.max() << " (Expected: 60)" << std::endl;
}

void testTreeEmpty() {
    AVLtree<int> tree;
    assert(tree.empty() == true);

    tree.insert(10);
    assert(tree.empty() == false);

    tree.remove(10);
    assert(tree.empty() == true);
}

void runAllTests() {
    std::cout << "Testing AVL Tree Insertion Balancing..." << std::endl;
    testInsertionBalancing();
    std::cout << "Insertion Balancing Test Passed." << std::endl;

    std::cout << "Testing AVL Tree Deletion Balancing..." << std::endl;
    testDeletionBalancing();
    std::cout << "Deletion Balancing Test Passed." << std::endl;

    std::cout << "Testing AVL Tree Min and Max..." << std::endl;
    testMinMax();
    std::cout << "Min and Max Test Passed." << std::endl;

    std::cout << "Testing AVL Tree Empty Check..." << std::endl;
    testTreeEmpty();
    std::cout << "Empty Check Test Passed." << std::endl;
}

int main() {
    runAllTests();
    return 0;
}
