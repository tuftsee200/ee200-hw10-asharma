#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
class Array
{
int* data;
int size;

	public:
void initialize(int size, int val);//The function initialize(int size, int val) should set up the Array with storage for size elements, all initialized to va

void cleanup();//release memory

int Size(); //return size of array

void append(int x);// to add element x to the end

void append(Array y);//to add elements of y to array 

// Overload the assignment operator to make a deep copy of the Array
    Array& operator=(Array& y);

// Overload the bracket operator for reading and writing elements of the Array
    int& operator[](int index);	    

 
       








	// You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.
};


#endif
