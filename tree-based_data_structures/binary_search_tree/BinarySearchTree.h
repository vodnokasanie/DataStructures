#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions for recursive operations
    Node* insert(Node* node, const T& value);
    Node* remove(Node* node, const T& value);
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    bool search(Node* node, const T& value) const;
    void inorderTraversal(Node* node) const;
    void preorderTraversal(Node* node) const;
    void postorderTraversal(Node* node) const;
    void clear(Node* node);

public:
    // Constructors and Destructor
    BinarySearchTree();
    ~BinarySearchTree();

    // Public Interface Functions
    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;
    bool empty() const;
    T min() const;
    T max() const;

    // Traversals
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;

    // Clear tree
    void clear();
};




#endif


template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insert(Node* node, const T& value){
    if (!node) return new Node(value);

    if (value < node->data){
        node->left = insert(node->left, value);
    }
    else if (value > node->data){
        node->right = insert(node->right, value);
    }
    return node;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove(Node* node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (!node->left) {
            Node* rightNode = node->right;
            delete node;
            return rightNode;
        } else if (!node->right) {
            Node* leftNode = node->left;
            delete node;
            return leftNode;
        } else {
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = remove(node->right, minRight->data);
        }
    }
    return node;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMin(Node* node) const{
    while (node && node->left) node = node->left;
    return node;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMax(Node* node) const{
    while (node && node->right) node = node->right;
    return node;
}


template<typename T>
bool BinarySearchTree<T>::search(Node* node, const T& value) const{
    if (!node) return false;
    if (node->data == value) return true;

    if (value < node->data){
        return search(node->left, value);
    }
    else{
        return search(node->right, value);
    }
}

template<typename T>
void BinarySearchTree<T>::inorderTraversal(Node* node) const{
    if (!node) return;

    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

template<typename T>
void BinarySearchTree<T>::preorderTraversal(Node* node) const{
    if (!node) return;
    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

template<typename T>
void BinarySearchTree<T>::postorderTraversal(Node* node) const{
    if (!node) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void BinarySearchTree<T>::clear(Node* node){
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(): root{nullptr} {}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    clear(root);
}

template<typename T>
void BinarySearchTree<T>::insert(const T& value){
    root = insert(root, value);
}

template<typename T>
void BinarySearchTree<T>::remove(const T& value){
    root = remove(root, value);
}

template<typename T>
bool BinarySearchTree<T>::search(const T& value) const{
    return search(root, value);
}

template<typename T>
bool BinarySearchTree<T>::empty() const{
    return root == nullptr;
}

template<typename T>
T BinarySearchTree<T>::min() const{
    if (!root) throw std::out_of_range("The tree is empty.");
    Node* minNode = findMin(root);
    return minNode->data;
}

template<typename T>
T BinarySearchTree<T>::max() const{
    if (!root) throw std::out_of_range("The tree is empty.");
    Node* maxNode = findMax(root);
    return maxNode->data;
}

template<typename T>
void BinarySearchTree<T>::inorderTraversal() const{
    inorderTraversal(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::preorderTraversal() const{
    preorderTraversal(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::postorderTraversal() const{
    postorderTraversal(root);
    std::cout << std::endl;
}

