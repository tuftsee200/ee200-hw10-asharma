#include "array.h"
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>

#include <exception>
int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.
// Test the default constructor
    Array<int> arr;
    arr.append(3);
    arr.append(4);
    arr.append(5);
    // Test getSize
int size1 = arr.size();
if (size1 == 3) {
    std::cout << "getSize test passed. Size is correct: " << size1 << std::endl;
} else {
    std::cout << "getSize test failed. Expected size: 3, Actual size: " << size1 << std::endl;
}
    // Test the copy constructor
    Array<int> copy(arr);
    copy[1] = 6;

    // Test the = operator
    Array<int> copy2;
    copy2 = arr;
    copy2[1] = 7;

    // Test + operator
    Array<int> sum = arr + copy + copy2;

    // Test the [] operator
    for (int i = 0; i < sum.size(); i++)
    {
        std::cout << sum[i] << ' ';
    }

    std::cout << std::endl;

    // Test out of bounds error
    try
    {
        std::cout << sum[sum.size() - 1] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test the << operator
    // std::cout << sum << std::endl;

    Array<int> arrr(3, 0);
    try {
        std::cout << "The fourth number is: " << arrr[3] << std::endl;
    }
    catch (const std::exception& e){
        std::cout << "There was an error: " << e.what() << std::endl;
    }

    // Test getSize()
    int expectedSize = 3; // Set the expected size here
    int actualSize = sum.size();

    if (actualSize == expectedSize) {
        std::cout << "getSize() test passed. Expected size: " << expectedSize << ", Actual size: " << actualSize << std::endl;
    } else {
        std::cout << "getSize() test failed. Expected size: " << expectedSize << ", Actual size: " << actualSize << std::endl;
    }


    Array<int> arr2 (10, 5);
    Array<int> rtoo (0, 0);
    rtoo = arr2;

    for(int i = 0; i < arr2.size(); i++){
        arr2[i] = i * 2;
    }
    for(int i = 0; i < arr2.size(); i++){
        printf(" arr[%d] = %d\n", i, arr2[i]);
    }
    for(int i = 0; i < rtoo.size(); i++){
        printf("rtoo[%d] = %d\n", i, rtoo[i]);
    }

    return 0;
 // Array arr;
  //arr.initialize(10, 5);

 // Array rtoo;
 // rtoo.initialize(0, 0);
 // rtoo = arr;

  //for(int i = 0; i < arr.size(); i++){
    //arr[i] = i * 2;
  //}


 // for(int i = 0; i < arr.size(); i++){
    //printf(" arr[%d] = %d\n", i, arr[i]);
  //}

 // for(int i = 0; i < rtoo.size(); i++){
    //printf("rtoo[%d] = %d\n", i, rtoo[i]);
  //}

 // return(0);
}

