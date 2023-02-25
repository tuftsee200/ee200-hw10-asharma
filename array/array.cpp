#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

void Array::initialize(int size, int val)
    {
      this->size = size;

      // Allocate memory for the data array
      data = (int*) malloc(size * sizeof(int));

      // Initialize the elements of the array to 'val'
      for (int i = 0; i < size; i++) {
        data[i] = val;
      }
    }

    // Function to free all malloced memory associated with the Array
    void Array::cleanup()
    {
      free(data);
    }

    // Function to return the current size of the Array
    int Array::Size()
    {
      return size;
    }

    // Function to add the element 'x' to the end of the array
    void Array::append(int x)
    {
      // Allocate memory for the new element
      int* newData = (int*) malloc((size + 1) * sizeof(int));

      // Copy the old elements to the new array
      memcpy(newData, data, size * sizeof(int));

      // Add the new element to the end of the array
      newData[size] = x;

      // Update the size of the array
      size++;

      // Free the old memory and set the new array as the data
      free(data);
      data = newData;
    }

    // Function to add all of the contents of Array 'y' to the end of the array
    void Array::append(Array y)
    {
      // Allocate memory for the new elements
      int* newData = (int*) malloc((size + y.Size()) * sizeof(int));

      // Copy the old elements to the new array
      memcpy(newData, data, size * sizeof(int));

      // Copy the elements from 'y' to the end of the new array
      memcpy(newData + size, y.data, y.Size() * sizeof(int));

      // Update the size of the array
      size += y.Size();

      // Free the old memory and set the new array as the data
      free(data);
      data = newData;
    }

    // Overload the assignment operator to make a deep copy of the Array
    Array& Array::operator=(Array& y) // was const
    {
      // Check for self-assignment
      if (this == &y) {
          return *this;
      }

      // Free the old memory
      free(data);

      // Allocate memory for the new elements
      size = y.Size();
      data = (int*) malloc(size * sizeof(int));

      // Copy the elements from 'y' to the new array
      memcpy(data, y.data, size * sizeof(int));

      // Return the new Array
      return *this;
    }

    // Overload the bracket operator for reading and writing elements of the Array
    int& Array::operator[](int index)
    {
      // Check for invalid index
      if (index < 0 || index >= size) {
          printf("error\n");
          exit(0);
      }

      // Return the element at the specified index
      return data[index];
    }







   

//not much to say here.  Good luck!

