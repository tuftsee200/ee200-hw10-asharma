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
    Array() : size(0), data(NULL) {}

    Array(int length) : size(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = 0;
        }
    }

    // Constructor with length and initial value: creates an array of the given length, filled with the given initial value
    Array(int length, T value) : size(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = value;
        }
    }

    // Constructor with length and array: creates an array of the given length, filled with the values from the given array
    Array(int length, T* values) : size(length), data(new T[length]) {
        for (int i = 0; i < length; i++) {
            data[i] = values[i];
        }
    }

    // Copy constructor: creates a deep copy of the given array
    Array(const Array& other) : size(other.size), data(new T[size]) {
        for (int i = 0; i < size; i++) {
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
    int getSize() const;

private:
    T* data;
    int size;
    int capacity;
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.
};


#endif
