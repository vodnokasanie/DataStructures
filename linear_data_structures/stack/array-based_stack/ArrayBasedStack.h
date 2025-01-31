#ifndef ARRAY_BASED_STACK_H_
#define ARRAY_BASED_STACK_H_

#include <iostream>


template<typename T>
class ArrayBasedStack{
public:
    ArrayBasedStack(size_t initialCapacity = 10);
    ~ArrayBasedStack();

    ArrayBasedStack(const ArrayBasedStack<T>& other);
    ArrayBasedStack<T>& operator=(const ArrayBasedStack<T>& other);

    ArrayBasedStack(ArrayBasedStack<T>&& other) noexcept;
    ArrayBasedStack<T>& operator=(ArrayBasedStack<T>&& other) noexcept;

    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;
    size_t size() const;
private:
    T* m_data;
    size_t m_capacity;
    size_t m_size;

    void resize(size_t newCapacity);
    void copyFrom(const ArrayBasedStack<T>& other);
    void freeMemory();
};





#endif



template<typename T>
void ArrayBasedStack<T>::resize(size_t newCapacity){
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < m_size; i++){
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

template<typename T>
void ArrayBasedStack<T>::copyFrom(const ArrayBasedStack<T>& other) {
    // Ensure m_data is already allocated with the correct capacity before calling this
    for (size_t i = 0; i < other.m_size; i++) {
        m_data[i] = other.m_data[i];
    }
    m_size = other.m_size;
}

template<typename T>
void ArrayBasedStack<T>::freeMemory() {
    if (m_data != nullptr) { // Check if m_data is not null
        delete[] m_data;
        m_data = nullptr; // Reset to null to avoid dangling pointer
        m_size = 0;       // Reset size to zero
        m_capacity = 0;   // Reset capacity to zero
    }
}

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack(size_t initialCapacity): 
    m_data{new T[initialCapacity]},
    m_capacity{initialCapacity}, 
    m_size{0}
{}

template<typename T>
ArrayBasedStack<T>::~ArrayBasedStack(){
    freeMemory();
}

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack(const ArrayBasedStack<T>& other):
    m_capacity{other.m_capacity},
    m_size{other.m_size}
{
    m_data = new T[m_capacity];
    copyFrom(other);
}

template<typename T>
ArrayBasedStack<T>& ArrayBasedStack<T>::operator=(const ArrayBasedStack<T>& other) {
    if (this != &other) {
        freeMemory();  // Clean up existing data

        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_data = new T[m_capacity];
        copyFrom(other);
    }
    return *this;
}

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack(ArrayBasedStack<T>&& other) noexcept:
    m_capacity{other.m_capacity},
    m_size{other.m_size},
    m_data{other.m_data}
{
    other.m_capacity = 0;
    other.m_size = 0;
    other.m_data = nullptr;
}

template<typename T>
ArrayBasedStack<T>& ArrayBasedStack<T>::operator=(ArrayBasedStack<T>&& other) noexcept{
    if (this != &other){
        freeMemory();
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;
        other.m_capacity = 0;
        other.m_size = 0;
        other.m_data = nullptr;
    }
    return *this;
}

template<typename T>
void ArrayBasedStack<T>::push(const T& value){
    if (m_size == m_capacity){
        resize(m_capacity*2);
    }
    m_data[m_size++] = value;
}

template<typename T>
void ArrayBasedStack<T>::pop(){
    if (empty()) throw std::out_of_range("The stack is empty.");
    --m_size;
}

template<typename T>
T& ArrayBasedStack<T>::top(){
    if (empty()) throw std::out_of_range("The stack is empty.");
    return m_data[m_size-1];
}

template<typename T>
const T& ArrayBasedStack<T>::top() const{
    if (empty()) throw std::out_of_range("The stack is empty.");
    return m_data[m_size-1];
}

template<typename T>
bool ArrayBasedStack<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t ArrayBasedStack<T>::size() const{
    return m_size;
}

