#ifndef ARRAY_H
#define ARRAY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>

#include <exception>

class OutOfBoundsException : public std::exception
{
    public:
    OutOfBoundsException() {}
    virtual const char* what() const throw()
    {
        return "Out of bounds";
    }
};

template <typename T>
class Array {
public:
    // Constructors and Destructor
    // Default constructor: creates an empty array with capacity 0
    Array() : size1(0), data(NULL) {}

    Array(int length) : size1(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = 0;
        }
    }

    Array(int length, T value) : size1(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = value;
        }
    }

    Array(int length, T* values) : size1(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = values[i];
        }
    }

    Array(const Array& other) : size1(other.size1), data(new T[size1]) {
        for (int i = 0; i < size1; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        if (data != NULL) {
            delete[] data;
            data = NULL;
        }
    }

    Array<T>& operator=(const Array& other);
    Array<T> operator+(const Array& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
        for (int i = 0; i < array.size1(); i++) {
            out << array[i] << ' ';
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Array<T>& array) {
        for (int i = 0; i < array.size1(); i++) {
            in >> array[i];
        }
        return in;
    }

    void append(T x);
    void append(const Array& other);
    int size() const;

private:
    int size1;
    T* data;
};

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        T* newData = new T[other.size1];
        for (int i = 0; i < other.size1; i++) {
            newData[i] = other.data[i];
        }
        delete[] data;
        data = newData;
        size1 = other.size1;
    }
    return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& other) {
    Array<T> result(size1 + other.size1);
    for (int i = 0; i < size1; i++) {
        result[i] = data[i];
    }
    for (int i = 0; i < other.size1; i++) {
        result[size1 + i] = other.data[i];
    }
    return result;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size1) {
        throw OutOfBoundsException();
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= size1) {
        throw OutOfBoundsException();
    }
    return data[index];
}

template <typename T>
void Array<T>::append(T x) {
    T* newData = new T[size1 + 1];
    for (int i = 0; i < size1; i++) {
        newData[i] = data[i];
    }
    newData[size1] = x;
    delete[] data;
    data = newData;
    size1++;
}

template <typename T>
void Array<T>::append(const Array<T>& other) {
    T* newData = new T[size1 + other.size1];
    for (int i = 0; i < size1; i++) {
        newData[i] = data[i];
    }
    for (int i = 0; i < other.size1; i++) {
        newData[size1 + i] = other.data[i];
    }
    delete[] data;
    data = newData;
    size1 += other.size1;
}

template <typename T>
int Array<T>::size() const {
    return size1;
}

#endif

