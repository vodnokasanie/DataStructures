#include "DynamicArray.h"
#include <iostream>

template<typename T>
DynamicArray<T>::DynamicArray(): 
    data{nullptr}, 
    m_size{0}, 
    m_capacity{0} 
{}

template<typename T>
DynamicArray<T>::DynamicArray(size_t initialSize):
    m_data{new T[initialSize]{}},
    m_size{initialSize},
    m_capacity{initialSize}
{}

template<typename T>
DynamicArray<T>::~DynamicArray(){
    delete[] m_data;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other):
    m_data{new T[other.m_capacity]{}},
    m_size{other.m_size},
    m_capacity{other.m_capacity}
{
    for (size_t i = 0; i < m_size; i++){
        m_data[i] = other.m_data[i];
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){
    if (this != &other){
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        delete[] m_data;
        m_data = new T[other.m_capacity];
        for (size_t i = 0; i < m_size; i++){
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) noexcept:
    m_size{other.m_size},
    m_capacity{other.m_capacity},
    m_data{other.m_data}
{
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other) noexcept{
    if (this != &other){
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    return *this;
} 

template<typename T>
void DynamicArray<T>::push_back(const T& value){
    if (m_size == m_capacity){
        reallocate(m_capacity *2);
    }
    m_data[m_size++] = value;
}

template<typename T>
void DynamicArray<T>::reallocate(size_t newCapacity){
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < m_size; i++){
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity; 
}

template<typename T>
void DynamicArray<T>::pop_back(){
    if (m_size > 0)
        m_size--;
}

template<typename T>
void DynamicArray<T>::clear(){
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index){
    return m_data[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const{
    return m_data[index];
}

template<typename T>
T& DynamicArray<T>::at(size_t index){
    if (index >= m_size){
        throw std::out_of_range("Index is out of range");
    }
    return m_data[index];
}

template<typename T>
const T& DynamicArray<T>::at(size_t index) const{
    if (index >= size){
        throw std::out_of_range("Index is out of range");
    }
    return m_data[index];
}

template<typename T>
T& DynamicArray<T>::front(){
    return m_data[0];
}

template<typename T>
const T& DynamicArray<T>::front() const{
    return m_data[0];
}

template<typename T>
T& DynamicArray<T>::back(){
    return m_data[m_size-1];
}

template<typename T>
const T& DynamicArray<T>::back() const{
    return m_data[m_size-1];
}

template<typename T>
bool DynamicArray<T>::empty() const{
    return m_size == 0;
}

template<typename T>
size_t DynamicArray<T>::size() const{
    return m_size;
}

template<typename T>
size_t DynamicArray<T>::capacity() const{
    return m_capacity;
}

template<typename T>
void DynamicArray<T>::resize(size_t newSize){
    if (newSize > m_capacity){
        reallocate(newSize);
    }
    m_size = newSize;
}

template<typename T>
void DynamicArray<T>::reserve(size_t newCapacity){
    if (newCapacity > m_capacity){
        reallocate(newCapacity);
    }
}

template<typename T>
T* DynamicArray<T>::data(){
    return m_data;
}

template<typename T>
const T* DynamicArray<T>::data() const{
    return m_data;
}

template<typename T>
void DynamicArray<T>::print() const{
    for (size_t i = 0; i < m_size; i++){
        std::cout << m_data[i] << ' ';
    }
    std::cout << std::endl;
}
