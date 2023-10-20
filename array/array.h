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

    //template<class T>
    friend std::ostream& operator<<(std::ostream& out, const Array<T>& array);

    //template<class T>
    friend std::istream& operator>>(std::istream& in, Array<T>& array);

    // Array Operations
    void append(T x);
    void append(const Array& other);
    int getSize() const;

private:
    T* data;
    int size;
    int capacity;
};

template <typename T>
int Array<T>::getSize() const {
    return size;
}

template <typename T>
void Array<T>::append(const Array<T>& other) {
    // Create a new array with enough space for both arrays
    T* newData = new T[size + other.size];

    // Copy over the existing data
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    // Copy over the other array's data
    for (int i = 0; i < other.size; i++) {
        newData[size+i] = other.data[i];
    }

    // Delete the old array and update the size
    delete [] data;
    data = newData;
    size += other.size;
}

template <typename T>
void Array<T>::append(T x) {
    // Create a new array with one extra space
    T* newData = new T[size+1];

    // Copy over the existing data
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    // Add the new element
    newData[size] = x;

    // Delete the old array and update the size
    delete [] data;
    data = newData;
    size++;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        // Create a new array with the same length and data as other
        T* newData = new T[other.getSize()];
        for (int i = 0; i < other.getSize(); i++) {
            newData[i] = other[i];
        }

        // Delete the old data and replace it with the new data
        delete[] data;
        data = newData;
        size = other.getSize();
    }
    return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& other) {
    // Create a new array with the combined length of this and other
    Array<T> result(size + other.getSize());

    // Copy the data from this array into result
    for (int i = 0; i < size; i++) {
        result[i] = data[i];
    }

    // Copy the data from other into result
    for (int i = 0; i < other.getSize(); i++) {
        result[size + i] = other[i];
    }
    return result;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw OutOfBoundsException();
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw OutOfBoundsException();
    }
    return data[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
    out << "[";
    for (int i = 0; i < array.getSize(); i++) {
        if (i > 0) {
            out << ", ";
        }
        out << array[i];
    }
    out << "]";
    return out;
}


template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array) {
  // Read in values from the stream and append them to the array
  T value;
  while (in >> value) {
    array.append(value);
  }
  return in;
}
#endif





/*#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>


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
*/
