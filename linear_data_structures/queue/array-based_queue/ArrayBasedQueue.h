#ifndef ARRAY_BASED_QUEUE_H_
#define ARRAY_BASED_QUEUE_H_

#include <iostream>

template<typename T>
class ArrayBasedQueue{
public:
    ArrayBasedQueue(size_t initialCapacity = 10);
    ~ArrayBasedQueue();

    ArrayBasedQueue(const ArrayBasedQueue<T>& other);
    ArrayBasedQueue<T>& operator=(const ArrayBasedQueue<T>& other);

    ArrayBasedQueue(ArrayBasedQueue<T>&& other) noexcept;
    ArrayBasedQueue<T>& operator=(ArrayBasedQueue<T>&& other) noexcept;

    void enqueue(const T& value);
    void dequeue();
    T& front();
    const T& front() const;
    bool empty() const;
    size_t size() const;
private:
    T* m_data;
    size_t m_capacity;
    size_t m_size;
    size_t m_front;
    size_t m_rear;

    void resize(size_t newCapacity);
    void copyFrom(const ArrayBasedQueue<T>& other);
    void freeMemory();
};





#endif


template<typename T>
void ArrayBasedQueue<T>::resize(size_t newCapacity){
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < m_size; i++){
        newData[i] = m_data[(m_front + i) % m_capacity];
    }
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
    m_front = 0;
    m_rear = m_size;
}

template<typename T>
void ArrayBasedQueue<T>::copyFrom(const ArrayBasedQueue<T>& other){
    delete[] m_data;
    m_data = new T[other.m_capacity];
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_front = other.m_front;
    m_rear = other.m_rear;
    for (size_t i = 0; i < m_size; i++){
        m_data[i] = other.m_data[(other.m_front + i) % other.m_capacity];
    }
}

template<typename T>
void ArrayBasedQueue<T>::freeMemory(){
    delete[] m_data;
    m_data = nullptr;
    m_capacity = 0;
    m_size = 0;
    m_front = 0;
    m_rear = 0;
}

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue(size_t initialCapacity):
    m_data{new T[initialCapacity]},
    m_capacity{initialCapacity},
    m_size{0},
    m_front{0},
    m_rear{0}
{}

template<typename T>
ArrayBasedQueue<T>::~ArrayBasedQueue(){
    freeMemory();
}

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue(const ArrayBasedQueue<T>& other):
    m_data{nullptr},
    m_capacity{0},
    m_size{0},
    m_front{0},
    m_rear{0}
{
    copyFrom(other);
}

template<typename T>
ArrayBasedQueue<T>& ArrayBasedQueue<T>::operator=(const ArrayBasedQueue<T>& other){
    if (this != &other){
        copyFrom(other);
    }
    return *this;
}

template<typename T>
ArrayBasedQueue<T>::ArrayBasedQueue(ArrayBasedQueue<T>&& other) noexcept:
    m_data{other.m_data},
    m_capacity{other.m_capacity},
    m_size{other.m_size},
    m_front{other.m_front},
    m_rear{other.m_rear}
{
    other.m_capacity = 0;
    other.m_size = 0;
    other.m_front = 0;
    other.m_rear = 0;
    other.m_data = nullptr;
}

template<typename T>
ArrayBasedQueue<T>& ArrayBasedQueue<T>::operator=(ArrayBasedQueue<T>&& other) noexcept{
    if (this != &other){
        delete[] m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_front = other.m_front;
        m_rear = other.m_rear;
        m_data = other.m_data;

        other.m_capacity = 0;
        other.m_size = 0;
        other.m_front = 0;
        other.m_rear = 0;
        other.m_data = nullptr;
    }
    return *this;
}

template<typename T>
void ArrayBasedQueue<T>::enqueue(const T& value){
    if (m_size == m_capacity) resize(m_capacity*2);
    m_data[m_rear] = value;
    m_rear = (m_rear + 1) % m_capacity;
    ++m_size;
}

template<typename T>
void ArrayBasedQueue<T>::dequeue(){
    if (empty()) throw std::out_of_range("The queue is empty.");
    m_front = (m_front + 1) % m_capacity;
    --m_size;
    if (m_capacity > 10 && m_size <= m_capacity / 4) {
        resize(m_capacity / 2);
    }
}

template<typename T>
T& ArrayBasedQueue<T>::front(){
    if (empty()) throw std::out_of_range("The queue is empty.");
    return m_data[m_front];
}

template<typename T>
const T& ArrayBasedQueue<T>::front() const{
    if (empty()) throw std::out_of_range("The queue is empty.");
    return m_data[m_front];
}

template<typename T>
bool ArrayBasedQueue<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t ArrayBasedQueue<T>::size() const{
    return m_size;
}
