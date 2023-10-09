#include "array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>

#include <exception>

template <typename T>
int Array<T>::size() const {
    return size1;
}

template <typename T>
void Array<T>::append(T x) {
    // Create a new array with one extra space
    T* newData = new T[size1+1];

    // Copy over the existing data
    for (int i = 0; i < size1; i++) {
        newData[i] = data[i];
    }

    // Add the new element
    newData[size1] = x;

    // Delete the old array and update the size
    delete [] data;
    data = newData;
    size1++;
}

template <typename T>
void Array<T>::append(const Array<T>& other) {
    // Create a new array with enough space for both arrays
    T* newData = new T[size1 + other.size1];

    // Copy over the existing data
    for (int i = 0; i < size1; i++) {
        newData[i] = data[i];
    }

    // Copy over the other array's data
    for (int i = 0; i < other.size1; i++) {
        newData[size1+i] = other.data[i];
    }

    // Delete the old array and update the size
    delete [] data;
    data = newData;
    size1 += other.size1;
}


template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        // Create a new array with the same length and data as other
        T* newData = new T[other.size()];
        for (int i = 0; i < other.size(); i++) {
            newData[i] = other[i];
        }

        // Delete the old data and replace it with the new data
        delete[] data;
        data = newData;
        size1 = other.size();
    }
    return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& other) {
    // Create a new array with the combined length of this and other
    Array<T> result(size1 + other.size());

    // Copy the data from this array into result
    for (int i = 0; i < size1; i++) {
        result[i] = data[i];
    }

    // Copy the data from other into result
    for (int i = 0; i < other.size(); i++) {
        result[size1 + i] = other[i];
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
template class Array<int>;
/*template <typename T>
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
*/
