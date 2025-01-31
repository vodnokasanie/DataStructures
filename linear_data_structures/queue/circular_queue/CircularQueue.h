#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#include <iostream>

template<typename T>
class CircularQueue{
public:
    CircularQueue();
    CircularQueue(size_t capacity);
    ~CircularQueue();

    CircularQueue(const CircularQueue<T>& other);
    CircularQueue<T>& operator=(const CircularQueue<T>& other);

    CircularQueue(CircularQueue<T>&& other) noexcept;
    CircularQueue<T>& operator=(CircularQueue<T>&& other) noexcept;

    void enqueue(const T& value);
    void dequeue();
    T& front();
    const T& front() const;
    bool empty() const;
    bool full() const;
    size_t size() const;
private:
    T* m_data;
    size_t m_capacity;
    size_t m_front;
    size_t m_rear;
    size_t m_size;

    void copyFrom(const CircularQueue<T>& other);
    void freeMemory();
};





#endif

template<typename T>
CircularQueue<T>::CircularQueue():
    m_data{new T[m_capacity]},
    m_capacity{0},
    m_front{0},
    m_rear{0},
    m_size{0}
{}

template<typename T>
void CircularQueue<T>::copyFrom(const CircularQueue<T>& other){
    if (other.m_size == 0){
        m_data = nullptr;
        m_capacity = m_front = m_rear = m_size = 0;
        return;
    }
    m_data = new T[other.m_capacity];
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_front = other.m_front;
    m_rear = other.m_rear;
    for (size_t i = 0; i < m_size; i++){
        m_data[(m_front + i) % m_capacity] = other.m_data[(other.m_front + i) % other.m_capacity];
    }
}

template<typename T>
void CircularQueue<T>::freeMemory(){
    delete[] m_data;
    m_data = nullptr;
    m_capacity = m_front = m_rear = m_size = 0;
}

template<typename T>
CircularQueue<T>::CircularQueue(size_t capacity):
    m_data{new T[capacity]},
    m_capacity{capacity},
    m_front{0},
    m_rear{0},
    m_size{0}
{}

template<typename T>
CircularQueue<T>::~CircularQueue(){
    freeMemory();
}

template<typename T>
CircularQueue<T>::CircularQueue(const CircularQueue<T>& other):
    m_data{nullptr},
    m_capacity{0},
    m_front{0},
    m_rear{0},
    m_size{0} 
{
    copyFrom(other);
}

template<typename T>
CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue<T>& other){
    if (this != &other){
        freeMemory();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
CircularQueue<T>::CircularQueue(CircularQueue<T>&& other) noexcept:
    m_data{other.m_data},
    m_capacity{other.m_capacity},
    m_front{other.m_front},
    m_rear{other.m_rear},
    m_size{other.m_size}
{
    other.m_data = nullptr;
    other.m_capacity = 0;
    other.m_front = 0;
    other.m_rear = 0;
    other.m_size = 0;
}

template<typename T>
CircularQueue<T>& CircularQueue<T>::operator=(CircularQueue<T>&& other) noexcept{
    if (this != &other){
        freeMemory();
        m_data = other.m_data;
        m_capacity = other.m_capacity;
        m_front = other.m_front;
        m_rear = other.m_rear;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_capacity = 0;
        other.m_front = 0;
        other.m_rear = 0;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
void CircularQueue<T>::enqueue(const T& value){
    if (full()) throw std::out_of_range("The queue is full. Unable to add a value");
    m_data[m_rear] = value;
    m_rear = (m_rear+1) % m_capacity;
    ++m_size; 
}

template<typename T>
void CircularQueue<T>::dequeue(){
    if (empty()) throw std::out_of_range("The queue is empty.");
    m_front = (m_front + 1) % m_capacity;
    --m_size;
}

template<typename T>
T& CircularQueue<T>::front(){
    if (empty()) throw std::out_of_range("The queue is empty.");
    return m_data[m_front];
}

template<typename T>
const T& CircularQueue<T>::front() const{
    if (empty()) throw std::out_of_range("The queue is empty.");
    return m_data[m_front];
}

template<typename T>
bool CircularQueue<T>::empty() const{
    return m_size == 0;
}

template<typename T>
bool CircularQueue<T>::full() const{
    return m_size == m_capacity;
}

template<typename T>
size_t CircularQueue<T>::size() const{
    return m_size;
}
