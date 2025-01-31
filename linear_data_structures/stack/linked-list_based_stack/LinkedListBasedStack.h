#ifndef LINKED_LIST_BASED_STACK_H_
#define LINKED_LIST_BASED_STACK_H_

#include <iostream>

template<typename T>
class LinkedListBasedStack{
public:
    LinkedListBasedStack();
    ~LinkedListBasedStack();

    LinkedListBasedStack(const LinkedListBasedStack<T>& other);   // Copy constructor
    LinkedListBasedStack<T>& operator=(const LinkedListBasedStack<T>& other);         // Copy assignment operator

    LinkedListBasedStack(LinkedListBasedStack<T>&& other) noexcept;        // Move constructor 
    LinkedListBasedStack<T>& operator=(LinkedListBasedStack<T>&& other) noexcept; // Move assignment operator


    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    
    bool empty() const;
    size_t size() const;
private:
    struct Node{
        T data;
        Node* next;
        Node(const T& data): data{data}, next{nullptr} {}
    };

    Node* m_top;
    size_t m_size;

    void clear();
    void copyFrom(const LinkedListBasedStack<T>& other);
};





#endif


template<typename T>
void LinkedListBasedStack<T>::copyFrom(const LinkedListBasedStack<T>& other){
    if (other.m_top == nullptr){
        m_top = nullptr;
        m_size = 0;
        return;
    }
    Node* current = other.m_top;
    m_top = new Node(current->data);
    Node* newCurrent = m_top;
    current = current->next;
    while (current != nullptr){
        newCurrent->next = new Node(current->data);
        current = current->next;
        newCurrent = newCurrent->next;
    }
    m_size = other.m_size;
}

template<typename T>
void LinkedListBasedStack<T>::clear(){
    Node* current = m_top;
    while (current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    m_top = nullptr;
    m_size = 0;
}

template<typename T>
LinkedListBasedStack<T>::LinkedListBasedStack(): m_top{nullptr}, m_size{0} {}

template<typename T>
LinkedListBasedStack<T>::~LinkedListBasedStack(){
    clear();
}

template<typename T>
LinkedListBasedStack<T>::LinkedListBasedStack(const LinkedListBasedStack<T>& other):
    m_top{nullptr},
    m_size{0}
{
    copyFrom(other);
}

template<typename T>
LinkedListBasedStack<T>& LinkedListBasedStack<T>::operator=(const LinkedListBasedStack<T>& other){
    if (this != &other){
        clear();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
LinkedListBasedStack<T>::LinkedListBasedStack(LinkedListBasedStack<T>&& other) noexcept:
    m_top{other.m_top},
    m_size{other.m_size}
{
    other.m_top = nullptr;
    other.m_size = 0;
}

template<typename T>
LinkedListBasedStack<T>& LinkedListBasedStack<T>::operator=(LinkedListBasedStack<T>&& other) noexcept{
    if (this != &other){
        clear();
        m_top = other.m_top;
        m_size = other.m_size;
        other.m_top = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
void LinkedListBasedStack<T>::push(const T& value){
    Node* newNode = new Node(value);
    newNode->next = m_top;
    m_top = newNode;
    ++m_size;
}

template<typename T>
void LinkedListBasedStack<T>::pop(){
    if (m_size == 0) throw std::out_of_range("The stack is empty.");
    Node* temp = m_top;
    m_top = m_top->next;
    delete temp;
    --m_size;
}

template<typename T>
T& LinkedListBasedStack<T>::top(){
    if (empty()) throw std::out_of_range("The stack is empty.");
    return m_top->data;
}

template<typename T>
const T& LinkedListBasedStack<T>::top() const{
    if (empty()) throw std::out_of_range("The stack is empty.");
    return m_top->data;
}

template<typename T>
bool LinkedListBasedStack<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t LinkedListBasedStack<T>::size() const{
    return m_size;
}
