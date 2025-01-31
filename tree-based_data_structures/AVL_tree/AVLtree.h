#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <iostream>

template<typename T>
class AVLtree{
public:
    AVLtree();
    ~AVLtree();

    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;

    T min() const;
    T max() const;
    bool empty() const;

    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    void print(std::ostream& out) const;
    
private:
    struct Node{
        T data;
        Node* left;
        Node* right;
        int height;

        Node(const T& value): data{value}, left{nullptr}, right{nullptr}, height{1} {}
    };

    Node* root;

    int height(Node* node) const;
    int balanceFactor(Node* node) const;
    Node* simpleRightRotation(Node* y);
    Node* simpleLeftRotation(Node* x);
    Node* rightLeftRotation(Node* a);
    Node* leftRightRotation(Node* b);
    Node* balance(Node* node);

    Node* insert(Node* node, const T& value);
    Node* remove(Node* node, const T& value);
    bool search(Node* node, const T& value) const;
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;

    void inorderTraversal(Node* node) const;
    void preorderTraversal(Node* node) const;
    void postorderTraversal(Node* node) const;
    void clear(Node* node);

    void printTree(std::ostream& out, Node* node, int level, int direction) const;
};

template<class T>
inline std::ostream& operator<<(std::ostream& out, const AVLtree<T>& tree){
    tree.print(out);
    return out;
}



#endif


template<typename T>
int AVLtree<T>::height(Node* node) const{
    return node ? node->height : 0;
}

template<typename T>
int AVLtree<T>::balanceFactor(Node* node) const{
    return height(node->left) - height(node->right);
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::simpleRightRotation(Node* y){
    Node* current = y->left;
    y->left = current->right;
    current->right = y;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    current->height = std::max(height(current->left), height(current->right)) + 1;

    return current;
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::simpleLeftRotation(Node* x){
    Node* current = x->right;
    x->right = current->left;
    current->left = x;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    current->height = std::max(height(current->left), height(current->right)) + 1;

    return current;
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::leftRightRotation(Node* b){
    b->left = simpleLeftRotation(b->left);

    return simpleRightRotation(b);
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::rightLeftRotation(Node* a) {
    a->right = simpleLeftRotation(a->right);  // This should be `simpleLeftRotation`
    return simpleRightRotation(a);  // This should be `simpleRightRotation`
}


template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::balance(Node* node){
    if (!node) return nullptr;
    int bf = balanceFactor(node);

    if (bf > 1 && node->left->left != nullptr){
        node = simpleRightRotation(node);
    }
    if (bf < -1 && node->right->right != nullptr){
        node = simpleLeftRotation(node);
    }
    if (bf > 1 && node->left->right != nullptr){
        node = leftRightRotation(node);
    }
    if (bf < -1 && node->right->left != nullptr){
        node = rightLeftRotation(node);
    }

    node->height = std::max(height(node->left), height(node->right)) + 1;
    return node;
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::insert(Node* node, const T& value){
    if (!node) return new Node(value);
    if (value > node->data){
        node->right = insert(node->right, value);
    }
    else if (value < node->data){
        node->left = insert(node->left, value);
    }
    else return node;

    return balance(node);
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::remove(Node* node, const T& value){
    if (!node) return nullptr;

    if (value < node->data){
        node->left = remove(node->left, value);
    }
    else if (value > node->data){
        node->right = remove(node->right, value);
    }
    else{
        if (node->left == nullptr && node->right == nullptr){ //node has no children
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr){ //node has only right child
            Node* nodeRight = node->right;
            delete node;
            return nodeRight;
        }
        else if (node->right == nullptr){ //node has only left child
            Node* nodeLeft = node->left;
            delete node;
            return nodeLeft;
        }
        else{
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = remove(node->right, minRight->data);
        }
    }
    node->height = std::max(height(node->left), height(node->right)) + 1;
    return balance(node);
}



template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::findMin(Node* node) const{
    while (node && node->left) node = node->left;
    return node; 
}

template<typename T>
typename AVLtree<T>::Node* AVLtree<T>::findMax(Node* node) const{
    while (node && node->right) node = node->right;
    return node;
}

template<typename T>
bool AVLtree<T>::search(Node* node, const T& value) const{
    if (!node) return false;
    if (value == node->data) return true;

    if (value < node->data){
        return search(node->left, value);
    }
    else{
        return search(node->right, value);
    }
}

template<typename T>
void AVLtree<T>::inorderTraversal(Node* node) const{
    if (!node) return;

    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

template<typename T>
void AVLtree<T>::preorderTraversal(Node* node) const{
    if (!node) return;

    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

template<typename T>
void AVLtree<T>::postorderTraversal(Node* node) const{
    if (!node) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void AVLtree<T>::clear(Node* node){
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}


template<typename T>
AVLtree<T>::AVLtree(): root{nullptr} {}

template<typename T>
AVLtree<T>::~AVLtree(){
    clear(root);
}

template<typename T>
void AVLtree<T>::insert(const T& value){
    root = insert(root, value);
}

template<typename T>
void AVLtree<T>::remove(const T& value){
    root = remove(root, value);
}

template<typename T>
bool AVLtree<T>::search(const T& value) const{
    return search(root, value);
}

template<typename T>
T AVLtree<T>::min() const{
    if (!root) throw std::out_of_range("The tree is empty.");
    Node* minNode = findMin(root);
    return minNode->data;
}

template<typename T>
T AVLtree<T>::max() const{
    if (!root) throw std::out_of_range("The tree is empty.");
    Node* maxNode = findMax(root);
    return maxNode->data;
}

template<typename T>
bool AVLtree<T>::empty() const{
    return root == nullptr;
}

template<typename T>
void AVLtree<T>::inorderTraversal() const{
    inorderTraversal(root);
    std::cout << std::endl;
}

template<typename T>
void AVLtree<T>::preorderTraversal() const{
    preorderTraversal(root);
    std::cout << std::endl;
}

template<typename T>
void AVLtree<T>::postorderTraversal() const{
    postorderTraversal(root);
    std::cout << std::endl;
}

template<typename T>
void AVLtree<T>::printTree(std::ostream& out, Node* node, int level, int direction) const {
    if (node != nullptr) {
        printTree(out, node->right, level + 1, 1);
        
        for (int i = 0; i < level; i++) {
            out << "  ";
        }

        if (level > 0) {
            if (direction == 1) {
                out << " /--";
            } else {
                out << " \\--";
            }
        }
        
        out << node->data;
        out << "\n";
        
        printTree(out, node->left, level + 1, -1);
    }
}

template <class T>
void AVLtree<T>::print(std::ostream& out) const {
    printTree(out, root, 0, 0);
}



