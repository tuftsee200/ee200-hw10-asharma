#include "array.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  // Create an array of length 3 with initial value 0
  //Array a(3, 0);

  // Append some values to the array
  //a.append(1);
 // a.append(2);
  //a.append(3);

  // Print the modified array
 // std::cout << "a = " << a << std::endl;

  // Create another array of length 3 with initial value 0
  //Array b(3, 0);

  // Append some values to the array
 // b.append(4);
 // b.append(5);
  //b.append(6);

  // Print the modified array
  //std::cout << "b = " << b << std::endl;

  // Concatenate the two arrays
  //Array c = a + b;

  // Print the concatenated array
  //std::cout << "a + b = " << c << std::endl;

  // Create another array with the same values as a
  //Array d = a;

  // Change a value in the new array
  //d[0] = 9;

  // Print the modified array
  //std::cout << "d = " << d << std::endl;

  // Print the original array
 // std::cout << "a = " << a << std::endl;

  // Print the value at index 1 in the array
  //std::cout << "a[1] = " << a[1] << std::endl;

  // Print the value at an invalid index in the array
 // std::cout << "a[10] = " << a[10] << std::endl;
 Array a;

    // Create an array with length and initial value
    Array b(5, 10);

    // Create an array with length and values
    int data[] = {1, 2, 3, 4, 5};
    Array c(5, data);

    // Copy an array
    Array d = c;

    // Modify an element of the array using bracket notation
    d[0] = 10;

    // Append an element to the end of an array
    d.append(6);

    // Append an array to another array
    d.append(b);

    // Concatenate two arrays
    Array e = c + d;

    // Print the size of an array
    cout << "Size of array e: " << e.size() << endl;

    // Print the content of an array using the << operator
    cout << "Array e: " << e << endl;

    // Test out of bounds error
    e[100] = 1;

  return 0;


}

