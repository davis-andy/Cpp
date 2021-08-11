/**
 * Assignment #11.1
 * DUE: 12/1
 * NAME: Andy Davis
 * PURPOSE: Write a function that takes in a pointer reference to an array of any arbitrary elevation
 *      and its array size, and outputs the total amount of water retention in that given terrain
*/

#include <iostream>
using namespace std;


/**
 * FUNCTION NAME: 
 *      getTotalWaterAmount
 * PURPOSE: 
 *      Return the total amount of water retention from a given terrain
 * PARAMETER:
 * 		int* arr: array of heights
 *      int size: size of the array
 * RETURN VALUE:
 * 		int: total amount of water collected
 * FUNCTION SIGNATURE:
 *      int getTotalWaterAmount(int* arr, int size)
*/

int getTotalWaterAmount(int* arr, int size){
    int maxHeight = 0;
    int maxPos = 0;
    int previousHeight = 0;
    int nextHeight = 0;
    int result = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] > maxHeight){
            maxHeight = arr[i];
            maxPos = i;
        }
    }
    
    if (maxPos != 0){
        for (int j = 0; j <= maxPos; j++){
            if (arr[j] > previousHeight) previousHeight = arr[j];
        
            if (arr[j] == maxHeight) break;

            if (arr[j] >= arr[j+1] && arr[j] <= maxHeight){
                result += previousHeight - arr[j+1] ;
            }

            else if (arr[j] <= arr[j+1] && arr[j+1] <= previousHeight){
                result += previousHeight - arr[j+1];
            }
            
            else if (arr[j] <= arr[j+1] && arr[j+1] <= previousHeight){
                result += previousHeight - arr[j+1];
            }
        }
    
        for (int k = size-1; k >= maxPos; k--){
            if (arr[k] > nextHeight) nextHeight = arr[k];
        
            if (arr[k] == maxHeight) break;

            if (arr[k] >= arr[k-1] && arr[k] <= maxHeight){
                result += nextHeight - arr[k-1];
            }

            else if (arr[k] >= arr[k-1] && arr[k] <= nextHeight){
                result += nextHeight - arr[k-1];
            }
            
            else if (arr[k] <= arr[k-1] && arr[k-1] <= nextHeight){
                result += nextHeight - arr[k-1];
            }
        }
    }

    else{
        for (int k = size-1; k > 0; k--){
            if (arr[k] > nextHeight) nextHeight = arr[k];
        
            if (k != size-1 && arr[k] == maxHeight) break;

            if (arr[k] >= arr[k-1] && arr[k] <= maxHeight){
                result += nextHeight - arr[k-1];
            }

            else if (arr[k] >= arr[k-1] && arr[k] <= nextHeight){
                result += nextHeight - arr[k-1];
            }
            
            else if (arr[k] <= arr[k-1] && arr[k-1] <= nextHeight){
                result += nextHeight - arr[k-1];
            }
        }
    }

    return result;
}


int main() {
    int arr1[] = {10, 20, 30 , 40, 42, 40, 30, 20, 40, 50, 55, 50, 40, 30, 20, 10, 3};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {5,2,1,2,1,5};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int arr3[] = {0,1,0};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);

    int arr4[] = {1,2,3,4,5,6,5,4,3,6,22,3,2};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);

    int arr5[] = {0,1,2,5,4,2,6,4,3,2,1,1,1,1,1,1,8};
    int size5 = sizeof(arr5)/sizeof(arr5[0]);

    int arr6[] = {5,4,1,2};
    int size6 = sizeof(arr6)/sizeof(arr6[0]);

    int arr7[] = {5,2,1,3,1,5};
    int size7 = sizeof(arr7)/sizeof(arr7[0]);
    

    cout << getTotalWaterAmount(arr1, size1) << endl; //38
    cout << getTotalWaterAmount(arr2, size2) << endl; //14
    cout << getTotalWaterAmount(arr3, size3) << endl; //0
    cout << getTotalWaterAmount(arr4, size4) << endl; //6
    cout << getTotalWaterAmount(arr5, size5) << endl; //43
    cout << getTotalWaterAmount(arr6, size6) << endl; //1
    cout << getTotalWaterAmount(arr7, size7) << endl; //13
}

/*
TEST FAILED - 
INPUT: [5,2,1,2,1,5,4,2] 
YOUR OUTPUT: 0 
EXPECTED: 14 

TEST FAILED - 
INPUT: [5,2,5,2,5,5] 
YOUR OUTPUT: 0 
EXPECTED: 6 

TEST FAILED - 
INPUT: [5,2,5,2,5,2,5,2,5] 
YOUR OUTPUT: 3 
EXPECTED: 12
*/