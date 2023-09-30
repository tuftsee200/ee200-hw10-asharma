#ifndef ARRAY_H
#define ARRAY_H
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class Array{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.
  

  // Private members of the class
 //public:
  int* data;
  int storage;

  public:
    // Function to initialize the Array with storage for 'size' elements, all initialized to 'val'
    void initialize(int storage, int val);

    // Function to free all malloced memory associated with the Array
    void cleanup();

    // Function to return the current size of the Array
    int size();

    // Function to add the element 'x' to the end of the array
    void append(int x);

    // Function to add all of the contents of Array 'y' to the end of the array
    void append(Array y);

    // Overload the assignment operator to make a deep copy of the Array
    Array& operator=(Array& y) ;// was const

    // Overload the bracket operator for reading and writing elements of the Array
    int& operator[](int index);

};


#endif

