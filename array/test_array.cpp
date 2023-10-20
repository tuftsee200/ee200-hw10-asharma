#include "array.h"

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>

// Test our Array class
int main(int argc, char* argv[])
{
    // Test the default constructor
    Array<int> arr;
    arr.append(3);
    arr.append(4);
    arr.append(5);

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
    for (int i = 0; i < sum.getSize(); i++)
    {
        std::cout << sum[i] << ' ';
    }

    std::cout << std::endl;

    // Test out of bounds error
    try
    {
        std::cout << sum[sum.getSize()] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test the << operator
    // std::cout << sum << std::endl;

    return 0;
}
/*
#include <exception>


using namespace std;
int main(int argc, char* argv[]) {
    
 Array<int> arr;
    arr.append(2);
    arr.append(4);
    arr.append(5);

    // Test the copy constructor
    Array<int> copy(arr);
    copy[1] = 9;

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
        std::cout << sum[sum.size()] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
*/
