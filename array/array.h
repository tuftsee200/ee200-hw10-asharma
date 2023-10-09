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

    // Constructor with length and initial value: creates an array of the given length, filled with the given initial value
    Array(int length, T value) : size1(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = value;
        }
    }

    // Constructor with length and array: creates an array of the given length, filled with the values from the given array
    Array(int length, T* values) : size1(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = values[i];
        }
    }

    // Copy constructor: creates a deep copy of the given array
    Array(const Array& other) : size1(other.size1), data(new T[size1]) {
        for (int i = 0; i < size1; i++) {
            data[i] = other.data[i];
        }
    }

    // Destructor: frees the memory associated with the array
    ~Array() {
        if (data != NULL) {
            delete[] data;
            data = NULL;
        }
    }

    // Operator Overloads
    Array<T>& operator=(const Array& other);
    Array<T> operator+(const Array& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    // //template<class T>
    // friend std::ostream& operator<<(std::ostream& out, const Array<T>& array);

    // //template<class T>
    // friend std::istream& operator>>(std::istream& in, Array<T>& array);

    // Array Operations
    void append(T x);
    void append(const Array& other);
    int size() const;
    int size1;
private:
    //int size;
    T* data;
    int capacity;
};
# endif
