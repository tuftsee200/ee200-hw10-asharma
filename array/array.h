#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

class Array {
public:
    // Constructors
    Array();
    Array(int length, int value);
    Array(int length, int* values);
    Array(const Array& other); // Copy constructor
    Array(int length);
    // Destructor
    ~Array();

    // Public member functions
    int getSize() const;
    void append(int x);
    void append(const Array& other);
    Array operator+(const Array& other);
    Array& operator=(const Array& other);
    int& operator[](int index);
    const int& operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);

private:
    int* values;
    int size;
    int capacity;
    void allocate(int length){
	    values = new int[length];
	    capacity = length;
    }
    void copy(const Array& other){
	    allocate(other.size);
	for (int i = 0; i<other.size; i++){
values[i] = other.values[i];
}
size = other.size;
}
	
};

#endif	
