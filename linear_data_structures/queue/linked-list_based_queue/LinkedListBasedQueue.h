#ifndef LINKED_LIST_BASED_QUEUE_H_
#define LINKED_LIST_BASED_QUEUE_H_

#include <iostream>

template<typename T>
class LinkedListBasedQueue{
public:
    LinkedListBasedQueue();
    ~LinkedListBasedQueue();

    LinkedListBasedQueue(const LinkedListBasedQueue<T>& other);
    LinkedListBasedQueue<T>& operator=(const LinkedListBasedQueue<T>& other);

    LinkedListBasedQueue(LinkedListBasedQueue<T>&& other) noexcept;
    LinkedListBasedQueue<T>& operator=(LinkedListBasedQueue&& other) noexcept;

    void enqueue(const T& value);
    void dequeue();
    T& front();
    const T& front() const;
    bool empty() const;
    size_t size() const;
private:
    struct Node{
        T data;
        Node* next;
        Node(const T& value): data{value}, next{nullptr} {}
    };

    Node* m_front;
    Node* m_rear;
    size_t m_size;

    void copyFrom(const LinkedListBasedQueue<T>& other);
    void freeMemory();
};



#endif

template<typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue():
    m_front{nullptr},
    m_rear{nullptr},
    m_size{0}
{}

template<typename T>
void LinkedListBasedQueue<T>::copyFrom(const LinkedListBasedQueue<T>& other){
    if (other.m_size == 0){
        m_front = nullptr;
        m_rear = nullptr;
        m_size = 0;
        return;
    }
    if (other.m_front == nullptr){
        return;
    }
    Node* current = other.m_front;
    m_front = new Node(current->data);
    Node* newCurrent = m_front;
    current = current->next;
    while (current != nullptr){
        newCurrent->next = new Node(current->data);
        newCurrent = newCurrent->next;
        current = current->next;
    }

    m_rear = newCurrent;
    m_size = other.m_size;
}



template<typename T>
void LinkedListBasedQueue<T>::freeMemory(){
    Node* current = m_front;
    while (current != nullptr){
        Node* temp = current;
        current = current->next;;
        delete temp;
    }
    m_size = 0;
    m_front = m_rear = nullptr;
}


template<typename T>
LinkedListBasedQueue<T>::~LinkedListBasedQueue(){
    freeMemory();
}

template<typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue(const LinkedListBasedQueue<T>& other): 
    m_front{nullptr}, 
    m_rear{nullptr},
    m_size{0}
{
    copyFrom(other);
}

template<typename T>
LinkedListBasedQueue<T>& LinkedListBasedQueue<T>::operator=(const LinkedListBasedQueue<T>& other){
    if (this != &other){
        freeMemory();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue(LinkedListBasedQueue<T>&& other) noexcept:
    m_front{other.m_front},
    m_rear{other.m_rear},
    m_size{other.m_size}
{
    other.m_front = other.m_rear = nullptr;
    other.m_size = 0;
}

template<typename T>
LinkedListBasedQueue<T>& LinkedListBasedQueue<T>::operator=(LinkedListBasedQueue&& other) noexcept{
    if (this != &other){
        freeMemory();
        m_front = other.m_front;
        m_rear = other.m_rear;
        m_size = other.m_size;
        other.m_front = other.m_rear = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
void LinkedListBasedQueue<T>::enqueue(const T& value){
    Node* newNode = new Node(value);
    if (empty()){
        m_front = m_rear = newNode;
    }
    else{
        m_rear->next = newNode;
        m_rear = newNode;
    }
    ++m_size;
}

template<typename T>
void LinkedListBasedQueue<T>::dequeue(){
    if (empty()) throw std::out_of_range("The deque is empty.");
    Node* current = m_front;
    m_front = m_front->next;
    delete current;
    --m_size;
    if (m_size == 0) m_rear = m_front = nullptr;
}

template<typename T>
T& LinkedListBasedQueue<T>::front(){
    return m_front->data;
}

template<typename T>
const T& LinkedListBasedQueue<T>::front() const{
    return m_front->data;
}

template<typename T>
bool LinkedListBasedQueue<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t LinkedListBasedQueue<T>::size() const{
    return m_size;
}







