#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>

template<typename T>
class Deque{
public:
    Deque(size_t capacity = 10);
    ~Deque();

    Deque(const Deque<T>& other);
    Deque<T>& operator=(const Deque<T>& other);

    Deque(Deque<T>&& other) noexcept;
    Deque<T>& operator=(Deque<T>&& other) noexcept;

    void pushFront(const T& value);
    void pushBack(const T& value);
    void popFront();
    void popBack();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    bool empty() const;
    bool full() const;
    size_t size() const;
private:
    T* m_data;
    size_t m_capacity;
    size_t m_size;
    size_t m_front;
    size_t m_rear;

    void resize(size_t newCapacity);
    void copyFrom(const Deque<T>& other);
    void freeMemory();
};



#endif


template<typename T>
void Deque<T>::resize(size_t newCapacity){
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
void Deque<T>::copyFrom(const Deque<T>& other){
    delete[] m_data;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_front = other.m_front;
    m_rear = other.m_rear;
    m_data = new T[m_capacity];
    for (size_t i = 0; i < m_size; i++){
        m_data[(m_front + i) % m_capacity] = other.m_data[(other.m_front + i) % m_capacity];
    }
}

template<typename T>
void Deque<T>::freeMemory(){
    delete[] m_data;
    m_data = nullptr;
    m_front = 0;
    m_rear = 0;
    m_capacity = 0;
    m_size = 0;
}


template<typename T>
Deque<T>::Deque(size_t capacity):
    m_data{new T[capacity]},
    m_capacity{capacity},
    m_size{0},
    m_front{0},
    m_rear{0}
{}

template<typename T>
Deque<T>::~Deque(){
    freeMemory();
}

template<typename T>
Deque<T>::Deque(const Deque<T>& other):
    m_data{nullptr},
    m_capacity{0},
    m_size{0},
    m_front{0},
    m_rear{0}
{
    copyFrom(other);
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other){
    if (this != &other){
        freeMemory();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
Deque<T>::Deque(Deque<T>&& other) noexcept:
    m_data{other.m_data},
    m_capacity{other.m_capacity},
    m_size{other.m_size},
    m_front{other.m_front},
    m_rear{other.m_rear}
{
    other.m_data = nullptr;
    other.m_capacity = other.m_size = other.m_front = other.m_rear = 0;
}

template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T>&& other) noexcept{
    if (this != &other){
        freeMemory();
        m_data = other.m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_front = other.m_front;
        m_rear = other.m_rear;

        other.m_data = nullptr;
        other.m_capacity = other.m_size = other.m_front = other.m_rear = 0;
    }
    return *this;
}

template<typename T>
void Deque<T>::pushFront(const T& value){
    if (full()) resize(m_capacity * 2);
    m_front = (m_front + m_capacity - 1) % m_capacity;
    m_data[m_front] = value;
    ++m_size;
}

template<typename T>
void Deque<T>::pushBack(const T& value){
    if (full()) resize(m_capacity * 2);
    m_data[m_rear] = value;
    m_rear = (m_rear + 1) % m_capacity;
    ++m_size;
}

template<typename T>
void Deque<T>::popFront(){
    if (empty()) throw std::out_of_range("The deque is empty.");
    m_front = (m_front + 1) % m_capacity;
    --m_size;
}

template<typename T>
void Deque<T>::popBack(){
    if (empty()) throw std::out_of_range("The deque is empty.");
    m_rear = (m_rear + m_capacity - 1) % m_capacity;
    --m_size;
}

template<typename T>
T& Deque<T>::front(){
    return m_data[m_front];
}

template<typename T>
const T& Deque<T>::front() const{
    return m_data[m_front];
}

template<typename T>
T& Deque<T>::back() {
    return m_data[(m_rear + m_capacity - 1) % m_capacity]; // Access last element
}

template<typename T>
const T& Deque<T>::back() const {
    return m_data[(m_rear + m_capacity - 1) % m_capacity]; // Access last element
}

template<typename T>
bool Deque<T>::empty() const{
    return m_size == 0;
}

template<typename T>
bool Deque<T>::full() const{
    return m_size == m_capacity;
}

template<typename T>
size_t Deque<T>::size() const{
    return m_size;
}
