#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_


#include <iostream>

template<typename T>
class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    DoublyLinkedList(DoublyLinkedList&& other) noexcept;
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

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

    void printForward() const;
    void printBackward() const;
private:
    struct Node{
        T data;
        Node* next;
        Node* previous;

        Node(const T& value): data{value}, next{nullptr}, previous{nullptr} {}
    };

    Node* m_head;
    Node* m_tail;
    size_t m_size;

    void copyFrom(const DoublyLinkedList& other);
    void freeList();
};









#endif


template<typename T>
void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other){
    if (other.m_size == 0){
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        return;
    }
    Node* current = other.m_head;
    m_head = new Node(current->data);
    m_head->previous = nullptr;
    Node* newCurrent = m_head;
    current = current->next;
    while (current != nullptr){
        newCurrent->next = new Node(current->data);
        newCurrent->next->previous = newCurrent;
        current = current->next;
        newCurrent = newCurrent->next;
    }
    m_size = other.m_size;
    m_tail = newCurrent;
}

template<typename T>
void DoublyLinkedList<T>::freeList(){
    Node* current = m_head;
    while (current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList():
    m_head{nullptr},
    m_tail{nullptr},
    m_size{0}
{}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    freeList();
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other):
    m_head{nullptr},
    m_tail{nullptr},
    m_size{0}
{
    copyFrom(other);
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other){
    if (this != &other){
        freeList();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept:
    m_head{other.m_head},
    m_tail{other.m_tail},
    m_size{other.m_size}
{
    other.m_head = nullptr;
    other.m_tail = nullptr;
    m_size = 0;
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& other) noexcept{
    if (this != &other){
        freeList();
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_size = other.m_size;
        other.m_head = nullptr;
        other.m_tail = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    if (m_head == nullptr) {  // List is empty
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode->next = m_head;
        m_head->previous = newNode;
        m_head = newNode;
    }
    ++m_size;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (m_tail == nullptr) {  // List is empty
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode->previous = m_tail;
        m_tail->next = newNode;
        m_tail = newNode;
    }
    ++m_size;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (m_head == nullptr) return;  // List is empty, nothing to pop
    Node* temp = m_head;
    if (m_head == m_tail) {  // Only one element in the list
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_head = m_head->next;
        m_head->previous = nullptr;
    }
    delete temp;
    --m_size;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (m_tail == nullptr) return;  // List is empty, nothing to pop
    Node* temp = m_tail;
    if (m_head == m_tail) {  // Only one element in the list
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_tail = m_tail->previous;
        m_tail->next = nullptr;
    }
    delete temp;
    --m_size;
}

template<typename T>
void DoublyLinkedList<T>::clear(){
    freeList();
}

template<typename T>
T& DoublyLinkedList<T>::front(){
    return m_head->data;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const{
    return m_head->data;
}

template<typename T>
T& DoublyLinkedList<T>::back(){
    return m_tail->data;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const{
    return m_tail->data;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t DoublyLinkedList<T>::size() const{
    return m_size;
}

template<typename T>
void DoublyLinkedList<T>::printForward() const{
    Node* current = m_head;
    while (current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::printBackward() const{
    Node* current = m_tail;
    while (current != nullptr){
        std::cout << current->data << " <- ";
        current = current->previous;
    }
    std::cout << "nullptr" << std::endl;
}
