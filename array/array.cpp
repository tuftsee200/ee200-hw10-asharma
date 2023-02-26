#include "array.h"
#include <cstdlib> // For malloc, free
#include <cstring> // For memcpy
#include <iostream>

Array::Array() : values(nullptr), size(0), capacity(0) {}

Array::Array(int length, int value)  {
    allocate(length);
    size = length;
    for (int i = 0; i < length; i++) {
        values[i] = value;
    }
}

Array::Array(int length, int* values){
    allocate(length);
    size = length;
    for(int i = 0; i < length; i++){
	    this->values[i] = values[i];
    }
}

Array::Array(int length){
	allocate (length);
	size = length;
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


int Array::getSize() const {
    return size;
}

void Array::append(int x) {
    if (size == capacity) {
        int* newValues = new int[capacity * 2];
	for(int i = 0; i < capacity; i++){
		newValues[i] = values[i];
	}
delete[] values;
values = newValues;
capacity *= 2;
    }
    values[size] = x;
    size++;
}

void Array::append(const Array& other) {
    for (int i = 0; i < other.size; i++) {
        append(other.values[i]);
    }
}

Array Array::operator+(const Array& other){
    Array result(size + other.size);
    for (int i = 0; i<size; i++){
	    result.values[i] = values[i];
    }
    for (int i = 0; i<other.size; i++){
	    result.values[size + i] = other.values[i];
    }

      return result;
}


int& Array::operator[](int index) {
	if (index < 0 || index >= size){
		std::cout << "error" << std::endl;
		exit(0);
}
return values[index];
}
const int& Array::operator[](int index) const{
//int Array::operator[](int index) cont{
	if(index < 0 || index >= size){
		std::cout << "error" << std::endl;
		exit(0);
	}
    return values[index];
}

std::ostream& operator<<(std::ostream& stream, const Array& array) {
    stream << "[";
    for (int i = 0; i < array.size; i++) {
        stream << array.values[i];
        if (i < array.size - 1) {
            stream << ", ";
        }
    }
    stream << "]";
    return stream;
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
