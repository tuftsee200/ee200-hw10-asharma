#include "array.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib> // For malloc, free
#include <cstring> // For memcpy
#include <iostream> 

// Allocate memory for the array
void Array::allocate(int length) {
    values = new int[length];
    capacity = length;
  }

  // Copy the values from another array
  void Array::copy(const Array& other) {
    // Allocate memory for the new array
    allocate(other.size1);

    // Copy the values from the other array
    for (int i = 0; i < other.size1; i++) {
      values[i] = other.values[i];
    }

    // Update the storage of the array
    size1 = other.size1;
  }



Array::Array(int length, int value)  {
    allocate(length);
    size1 = length;
    for (int i = 0; i < length; i++) {
        values[i] = value;
    }
}

Array::Array(int length, int* values){
    allocate(length);
    size1 = length;
    for(int i = 0; i < length; i++){
	    this->values[i] = values[i];
    }
}

Array::Array(int length){
	allocate (length);
	size1 = length;
	for(int i = 0; i < length; i++){
		this->values[i] = 0;
	}
}


Array::Array(const Array& other){
    copy(other);
}

Array::~Array() {
    delete[] values;
}
Array& Array::operator=(const Array& other){
	if(this == & other){
		return *this;
	}

	copy(other);
	return *this;
}


int Array::size() const {
    return size1;
}

void Array::append(int x) {
    if (size1 == capacity) {
        int* newValues = new int[capacity * 2];
	for(int i = 0; i < capacity; i++){
		newValues[i] = values[i];
	}
delete[] values;
values = newValues;
capacity *= 2;
    }
    values[size1] = x;
    size1++;
}

void Array::append(const Array& other) {
    for (int i = 0; i < other.size1; i++) {
        append(other.values[i]);
    }
}

Array Array::operator+(const Array& other){
    Array result(size1 + other.size1);
    for (int i = 0; i<size1; i++){
	    result.values[i] = values[i];
    }
    for (int i = 0; i<other.size1; i++){
	    result.values[size1 + i] = other.values[i];
    }

      return result;
}


int Array::operator[](int index) const {
	if (index < 0 || index >= size1){
		std::cout << "error" << std::endl;
		exit(0);
}
return values[index];
}
int& Array::operator[](int index){
//int Array::operator[](int index) cont{
	if(index < 0 || index >= size1){
		std::cout << "error" << std::endl;
		exit(0);
	}
    return values[index];
}

   //void Array::resize(int newCapacity) {
  //  int* newData = (int*) realloc(data, newCapacity * sizeof(int));
    //if (newData == nullptr) {
      //  std::cerr << "Failed to allocate memory." << std::endl;
        //exit(1);
   // }
    //data = newData;
   // capacity = newCapacity;
    //length = std::min(length, capacity);
//}
