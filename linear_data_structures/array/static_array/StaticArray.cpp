#include "StaticArray.h"
#include <iostream>

template<typename T, size_t N>
StaticArray<T, N>::StaticArray() {}

template<typename T, size_t N>
StaticArray<T, N>::StaticArray(const T (&inputArr)[N]) {
    for (size_t i = 0; i < N; i++){
        arr[i] = inputArr[i];
    }
}

template<typename T, size_t N>
StaticArray<T, N>::~StaticArray() {}

template<typename T, size_t N>
StaticArray<T, N>& StaticArray<T, N>::operator=(const StaticArray<T, N>& other){
    if (this != &other){
        for (size_t i = 0; i < N; i++){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<typename T, size_t N>
StaticArray<T, N>::StaticArray(const StaticArray<T, N>& other){
    for (size_t i = 0; i < N; i++){
        arr[i] = other.arr[i];
    }
}

template<typename T, size_t N>
T& StaticArray<T, N>::operator[](size_t index){
    return arr[index];
}

template<typename T, size_t N>
T& StaticArray<T, N>::at(size_t index){
    if (index >= N){
        throw std::out_of_range("Index is out of bounds");
    }
    return arr[index];
}

template<typename T, size_t N>
T& StaticArray<T, N>::front(){
    return arr[0];
} 

template<typename T, size_t N>
T& StaticArray<T, N>::back(){
    return arr[N-1];
}

template<typename T, size_t N>
T* StaticArray<T, N>::data(){
    return arr;
}

template<typename T, size_t N>
size_t StaticArray<T, N>::size() const{
    return N;
}

template<typename T, size_t N>
size_t StaticArray<T, N>::max_size() const{
    return N;
}

template<typename T, size_t N>
bool StaticArray<T, N>::empty() const{
    return N == 0;
}

template<typename T, size_t N>
void StaticArray<T, N>::fill(const T& value){
    for (size_t i = 0; i < N; i++){
        arr[i] = value;
    }
}

template<typename T, size_t N>
void StaticArray<T, N>::swap(StaticArray<T, N>& other){
    T temp[N];
    for (size_t i = 0; i < N; i++){
        temp[i] = arr[i];
    }
    for (size_t i = 0; i < N; i++){
        arr[i] = other.arr[i];
    }
    for (size_t i = 0; i < N; i++){
        other.arr[i] = temp[i];
    }
}

template<typename T, size_t N>
void StaticArray<T, N>::clear(){
    fill(T{});
}

template<typename T, size_t N>
T* StaticArray<T, N>::begin(){
    return arr;
}

template<typename T, size_t N>
T* StaticArray<T,N>::end(){
    return arr+N;
}

template<typename T, size_t N>
const T* StaticArray<T, N>::begin() const{
    return arr;
}

template<typename T, size_t N>
const T* StaticArray<T,N>::end() const{
    return arr+N;
}

template<typename T, size_t N>
void StaticArray<T, N>::print() const{
    for (size_t i = 0; i < N; i++){
        std::cout << arr[i] << ' ';
    }
}

template<typename T, size_t N>
size_t StaticArray<T, N>::find(const T& value) const{
    for (size_t i = 0; i < N; i++){
        if (arr[i] == value) {
            return i;
        }
    }
    return N;
}
