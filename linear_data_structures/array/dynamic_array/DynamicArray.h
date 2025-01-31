#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <iostream>

template<typename T>
class DynamicArray{
public:
    DynamicArray();
    explicit DynamicArray(size_t initialSize);
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);                    //copy constructor
    DynamicArray& operator=(const DynamicArray<T>& other);         //assignment operator
    DynamicArray(DynamicArray&& other) noexcept;                //move constructor
    DynamicArray& operator=(DynamicArray&& other) noexcept;     //move assignment operator

    void push_back(const T& value);
    void pop_back();
    void clear();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void resize(size_t newSize);
    void reserve(size_t newCapacity);

    T* data();
    const T* data() const;

    void print() const;
private:
    size_t m_size;
    size_t m_capacity;
    T* m_data;

    void reallocate(size_t newCapacity);
};



#endif
