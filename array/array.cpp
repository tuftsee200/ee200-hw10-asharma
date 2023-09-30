#include "array.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // Function to initialize the Array with storage for 'size' elements, all initialized to 'val'
    void Array::initialize(int storage, int val)
    {
      this->storage = storage;

      // Allocate memory for the data array
      data = (int*) malloc(storage * sizeof(int));

      // Initialize the elements of the array to 'val'
      for (int i = 0; i < storage; i++) {
        data[i] = val;
      }
    }

    // Function to free all malloced memory associated with the Array
    void Array::cleanup()
    {
      free(data);
    }

    // Function to return the current size of the Array
    int Array::size()
    {
      return storage;
    }

    // Function to add the element 'x' to the end of the array
    void Array::append(int x)
    {
      // Allocate memory for the new element
      int* newData = (int*) malloc((storage + 1) * sizeof(int));

      // Copy the old elements to the new array
      memcpy(newData, data, storage * sizeof(int));

      // Add the new element to the end of the array
      newData[storage] = x;

      // Update the size of the array
      storage++;

      // Free the old memory and set the new array as the data
      free(data);
      data = newData;
    }

    // Function to add all of the contents of Array 'y' to the end of the array
    void Array::append(Array y)
    {
      // Allocate memory for the new elements
      int* newData = (int*) malloc((storage + y.size()) * sizeof(int));

      // Copy the old elements to the new array
      memcpy(newData, data, storage * sizeof(int));

      // Copy the elements from 'y' to the end of the new array
      memcpy(newData + storage, y.data, y.size() * sizeof(int));

      // Update the size of the array
      storage += y.size();

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
      storage = y.size();
      data = (int*) malloc(storage * sizeof(int));

      // Copy the elements from 'y' to the new array
      memcpy(data, y.data, storage * sizeof(int));

      // Return the new Array
      return *this;
    }

    // Overload the bracket operator for reading and writing elements of the Array
   int& Array::operator[](int index)
    {
      // Check for invalid index
      if (index < 0 || index >= storage) {
          printf("error\n");
          exit(0);
      }

      // Return the element at the specified index
      return data[index];
    }
;

