#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

template<typename T>
class SinglyLinkedList{
public:
    struct Node{
        T data;
        Node* next;

        Node(const T& value): data{value}, next{nullptr} {}
    };

    SinglyLinkedList();
    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList<T>& other);
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& other);

    SinglyLinkedList(SinglyLinkedList&& other) noexcept;
    SinglyLinkedList<T>& operator=(SinglyLinkedList&& other) noexcept;

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
    Node* m_head;
    Node* m_tail;
    size_t m_size;

    void copyFrom(const SinglyLinkedList<T>& other);
    void freeList();
};



#endif


template<typename T>
SinglyLinkedList<T>::SinglyLinkedList():
    m_head{nullptr},
    m_tail{nullptr},
    m_size{0}
{}

template<typename T>
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T>& other){
    if (other.m_size == 0){
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        return;
    }
    if (other.m_head == nullptr){
        return;
    }
    Node* current = other.m_head;
    m_head = new Node(current->data);
    Node* newCurrent = m_head;
    current = current->next;
    while (current != nullptr){
        newCurrent->next = new Node(current->data);
        newCurrent = newCurrent->next;
        current = current->next;
    }

    m_tail = newCurrent;
    m_size = other.m_size;
}

template<typename T>
void SinglyLinkedList<T>::freeList(){
    Node* current = m_head;
    while (current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    freeList();
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other): 
    m_head{nullptr}, 
    m_tail{nullptr},
    m_size{0}
{
    copyFrom(other);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other){
    if (this != &other){
        freeList();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList&& other) noexcept:
    m_head{other.m_head},
    m_tail{other.m_tail},
    m_size{other.m_size}
{
    other.m_size = 0;
    other.m_head = nullptr;
    other.m_tail = nullptr;
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList&& other) noexcept{
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
void SinglyLinkedList<T>::push_front(const T& value){
    Node* newNode = new Node(value);
    newNode->next = m_head;
    m_head = newNode;
    ++m_size;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T& value){
    Node* newNode = new Node(value);
    if (m_tail){
        m_tail->next = newNode;
    }
    else{
        m_head = newNode;
    }
    m_tail = newNode;
    ++m_size;
}

template<typename T>
void SinglyLinkedList<T>::pop_front(){
    if (m_head == nullptr){
        return;
    }
    Node* temp = m_head;
    m_head = m_head->next;
    delete temp;
    --m_size;
    if (m_head == nullptr){
        m_tail = nullptr;
    }
}

template<typename T>
void SinglyLinkedList<T>::pop_back(){
    if (m_head == nullptr){
        return;
    }
    if (m_head == m_tail){
        delete m_head;
        m_head = m_tail = nullptr;
    }
    else{
        Node* current = m_head;
        while (current->next != m_tail){
            current = current->next;
        }
        delete m_tail;
        m_tail = current;
        m_tail->next = nullptr;
    }
    --m_size;
}

template<typename T>
T& SinglyLinkedList<T>::front(){
    return m_head->data;
}

template<typename T>
const T& SinglyLinkedList<T>::front() const{
    return m_head->data;
}

template<typename T>
T& SinglyLinkedList<T>::back(){
    return m_tail->data;
}

template<typename T>
const T& SinglyLinkedList<T>::back() const{
    return m_tail->data;
}

template<typename T>
bool SinglyLinkedList<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t SinglyLinkedList<T>::size() const{
    return m_size;
}

template<typename T>
void SinglyLinkedList<T>::print() const{
    Node* current = m_head;
    while (current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<typename T>
void SinglyLinkedList<T>::clear(){
    freeList();
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
