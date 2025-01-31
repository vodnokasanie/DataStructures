#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include <iostream>

template<typename T>
class CircularLinkedList{
public:
    CircularLinkedList();
    ~CircularLinkedList();

    CircularLinkedList(const CircularLinkedList<T>& other);
    CircularLinkedList<T>& operator=(const CircularLinkedList<T>& other);

    CircularLinkedList(CircularLinkedList<T>&& other) noexcept;
    CircularLinkedList<T>& operator=(CircularLinkedList<T>&& other) noexcept;

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void clear();

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    bool empty() const;
    size_t size() const;

    void print() const;
private:
    struct Node{
        T data;
        Node* next;

        Node(const T& value): data{value}, next{nullptr} {}
    };

    Node* m_tail;
    size_t m_size;

    void copyFrom(const CircularLinkedList& other);
    void freeList();
};




#endif


template<typename T>
void CircularLinkedList<T>::copyFrom(const CircularLinkedList<T>& other) {
    if (other.m_tail == nullptr) {
        m_tail = nullptr;
        m_size = 0;
        return;
    }
    Node* current = other.m_tail->next;
    m_tail = new Node(current->data);
    Node* newCurrent = m_tail;
    current = current->next;
    while (current != other.m_tail->next){
        newCurrent->next = new Node(current->data);
        current = current->next;
        newCurrent = newCurrent->next;
    }
    newCurrent->next = m_tail;
    m_tail = newCurrent;
    m_size = other.m_size;
}


template<typename T>
void CircularLinkedList<T>::freeList(){
    if (m_tail == nullptr) return;
    Node* current = m_tail->next;
    Node* start = current;
    do{
        Node* temp = current;
        current = current->next;
        delete temp;
    } while (current != start);
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
CircularLinkedList<T>::CircularLinkedList():
    m_tail{nullptr},
    m_size{0}
{}

template<typename T>
CircularLinkedList<T>::~CircularLinkedList(){
    freeList();
}

template<typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& other):
    m_tail{nullptr},
    m_size{0}
{
    copyFrom(other);
}

template<typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& other){
    if (this != &other){
        freeList();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
CircularLinkedList<T>::CircularLinkedList(CircularLinkedList<T>&& other) noexcept:
    m_tail{other.m_tail},
    m_size{other.m_size}
{
    other.m_tail = nullptr;
    other.m_size = 0;
}

template<typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(CircularLinkedList<T>&& other) noexcept{
    if (this != &other){
        freeList();
        m_tail = other.m_tail;
        m_size = other.m_size;
        other.m_tail = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
void CircularLinkedList<T>::push_front(const T& value){
    Node* newNode = new Node(value);
    if (m_tail == nullptr){
        m_tail = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = m_tail->next;
        m_tail->next = newNode;
    }
    ++m_size;
}

template<typename T>
void CircularLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    
    if (m_tail == nullptr) {  // Empty list
        newNode->next = newNode;  // Point to itself, circular link
        m_tail = newNode;
    } else {
        newNode->next = m_tail->next;  // Link new node to the current head
        m_tail->next = newNode;        // Link tail to the new node
        m_tail = newNode;              // Update tail to be the new node
    }
    
    ++m_size;
}


template<typename T>
void CircularLinkedList<T>::pop_front() {
    //if (m_tail == nullptr) throw std::runtime_error("The list is empty");
    Node* temp = m_tail->next;
    if (m_tail == temp) { // Only one node
        m_tail = nullptr;
    } else {
        m_tail->next = temp->next;
    }
    delete temp;
    --m_size;
}

template<typename T>
void CircularLinkedList<T>::pop_back() {
    if (m_tail == nullptr) {
        throw std::runtime_error("The list is empty");
    }
    
    // Handle single-node case
    if (m_tail == m_tail->next) {
        delete m_tail;
        m_tail = nullptr;
    } else {
        // Traverse to the node before m_tail
        Node* current = m_tail->next;
        while (current->next != m_tail) {
            current = current->next;
        }
        current->next = m_tail->next;
        delete m_tail;
        m_tail = current;
    }
    --m_size;
}


template<typename T>
void CircularLinkedList<T>::clear(){
    freeList();
}

template<typename T>
T& CircularLinkedList<T>::front(){
    return m_tail->next->data;
}

template<typename T>
const T& CircularLinkedList<T>::front() const{
    return m_tail->next->data;
}

template<typename T>
T& CircularLinkedList<T>::back(){
    return m_tail->data;
}

template<typename T>
const T& CircularLinkedList<T>::back() const{
    return m_tail->data;
}

template<typename T>
bool CircularLinkedList<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t CircularLinkedList<T>::size() const{
    return m_size;
}

template<typename T>
void CircularLinkedList<T>::print() const{
    if (m_tail == nullptr) return;
    Node* current = m_tail->next;
    Node* start = current;
    do{
        std::cout << current->data << ' ';
        current = current->next;
    } while (current != start);
    std::cout << std::endl;
}
