/**
 * Assignment #6.1
 * DUE: 10/13
 * NAME: Andy Davis
 * PURPOSE: To simulate the effect of a circular array in that it'd be able to 
 *          shift all of its elements to the RIGHT by M elements, where M is an integer >= 0.
*/

#include <iostream>
#include <string>
using namespace std;


/**
 * FUNCTION NAME: rightShiftElements
 * PURPOSE: 
 *      Shift the elements of the array to the right M spaces, given length N
 * PARAMETER:
 * 		int arr[], int N, int M
 * RETURN VALUE:
 * 		none, it is a void function and acts on the original arr[]
 * FUNCTION SIGNATURE:
 *      void rightShiftElements(int arr[], int N, int M)
*/

void rightShiftElements(int arr[], int N, int M)
{
    int j = 0;
    int x = N;

    while (M > N)
    {
        M = M-N;
    }

    for (int i = (N-1); i > -1; i--) 
    {
        if (i >= M)
        {
            arr[i] = arr[i-M];
        }
        else
        {
            arr[i] = x;
            x--;
        }
        
        j++;
    }
}


int main() {
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
   int size = sizeof(arr)/sizeof(arr[0]);
   rightShiftElements(arr, size, 1);
   cout << "[";
   for (int i=0; i<size; i++) {
      cout << arr[i]; cout << ((i==size-1) ? "" : ",");
   }
   cout << "]";
   // or you can write your assert() to validate - what you do here is 
   // completely up to you
   return 0;
}