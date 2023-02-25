#include "array.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  Array arr;
  arr.initialize(10, 0);


  Array rtoo;
  rtoo.initialize(0, 0);
  rtoo = arr;

  for(int i = 0; i < arr.Size(); i++){
     arr [i] = i * 2;
  }


   for(int i = 0; i < arr.Size(); i++){
   printf(" arr[%d] = %d\n", i, arr [i]);
 }

  for(int i = 0; i < rtoo.Size(); i++){
    printf("rtoo[%d] = %d\n", i, rtoo [i]);
  }

  return(0);
}

