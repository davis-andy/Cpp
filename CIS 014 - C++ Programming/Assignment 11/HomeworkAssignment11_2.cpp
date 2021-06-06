/**
 * Assignment #11.2
 * DUE: 12/1
 * NAME: Andy Davis
 * PURPOSE:  Write a function that takes in a pointer reference to an array of any arbitrary elevation profile 
 *     and its array size, and outputs the max cross sectional area of the biggest pond.
*/

#include <iostream>
using namespace std;


/**
 * FUNCTION NAME:
 *      getMaxPond
 * PURPOSE: 
 *      Return the biggest pond created by cutting into an elevation profile
 * PARAMETER:
 * 		  int* arr: array of the elevation profile
 *      int size: size of the array
 * RETURN VALUE:
 * 		  int: total pond size
 * FUNCTION SIGNATURE:
 *      int getMaxPond(int* arr, int size)
*/

int getMaxPond(int* arr, int size) {
  int begin = 0;
  int end = size - 1;
  int firstNum = arr[0];
  int lastNum = arr[size-1];
  int result = min(firstNum, lastNum) * (size-1);
  int tmp;

  while (begin < end){
    if (firstNum <= lastNum){
      begin++;
      if (arr[begin] > firstNum){
        firstNum = arr[begin];
        tmp = min(firstNum, lastNum) * (end - begin);
        result = max(result, tmp);
      }
    }
    else if (firstNum > lastNum) {
      end--;
      if (arr[end] > lastNum) {
        lastNum = arr[end];
        tmp = min(firstNum, lastNum) * (end - begin);
        result = max(result, tmp);
      }
    }
  }

  return result;
}


int main() {
  int arr1[] = {22,31,1,23};
  int size1 = sizeof(arr1)/sizeof(arr1[0]);

  int arr2[] = {1};
  int size2 = sizeof(arr2)/sizeof(arr2[0]);

  int arr3[] = {1,3,5};
  int size3 = sizeof(arr3)/sizeof(arr3[0]);

  int arr4[] = {3,2,1};
  int size4 = sizeof(arr4)/sizeof(arr4[0]);

  int arr5[] = {1,1,1,1,1,1,1,1,1};
  int size5 = sizeof(arr5)/sizeof(arr5[0]);

  int arr6[] = {1,99,1};
  int size6 = sizeof(arr6)/sizeof(arr6[0]);
    

  cout << getMaxPond(arr1, size1) << endl; //66
  cout << getMaxPond(arr2, size2) << endl; //0
  cout << getMaxPond(arr3, size3) << endl; //3
  cout << getMaxPond(arr4, size4) << endl; //2
  cout << getMaxPond(arr5, size5) << endl; //8
  cout << getMaxPond(arr6, size6) << endl; //2
}