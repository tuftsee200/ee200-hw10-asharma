#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>

class Array {
public:

    // Constructors
    Array() : values(nullptr), size1(0), capacity(0) {}
    Array(int length, int value);
    Array(int length, int* values);
    Array(const Array& other); // Copy constructor
    Array(int length);
    // Destructor
    ~Array();

    // Public member functions
    //int getSize() const;
    int size() const;
    void append(int x);
    void append(const Array& other);
    Array operator+(const Array& other);
    Array& operator=(const Array& other);
    int& operator[](int index);
    //const int& operator[](int index) const;
    int operator[] (int index) const;
    friend std::ostream& operator<<(std::ostream& stream, const Array& arr){
	    stream << "[";

// writing all values in array seperated by ","
	    for (int i = 0; i < arr.size1; i++){
		    stream << arr.values[i];
		    if (i < arr.size1 - 1){
			    stream << ", ";
		    }
	    }
	    stream << "]";
	    return stream;
    }

private:
    int* values;
    int size1;
    int capacity;
    void allocate(int length);//{
	   // values = new int[length];
	    //capacity = length;
   // }
    void copy(const Array& other);//{
	    //allocate(other.size);
	//for (int i = 0; i<other.size; i++){
//values[i] = other.values[i];
//}
//size = other.size;
//}
	
};

#endif	
