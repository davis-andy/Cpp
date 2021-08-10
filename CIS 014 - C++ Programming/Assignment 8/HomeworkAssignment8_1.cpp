/**
 * Assignment #8.1
 * DUE: 11/3
 * NAME: Andy Davis
 * PURPOSE: To write a class CIS14 and implement its public member function, 
 *          int reverseInt(int), to reverse an integer. 
 *          The program MUST include this CIS14 class declaration with its public member function 
 *          BEFORE the placement of the main() function
*/

#include <iostream>
#include <climits>
using namespace std;

class CIS14 {
public:
   int reverseInt(int input);
};

/**
 * FUNCTION NAME: reverseInt
 * PURPOSE: 
 *      reverse an integer
 * PARAMETER:
 * 		int input
 * RETURN VALUE:
 * 		int output
 * FUNCTION SIGNATURE:
 *      int reverseInt(int input)
*/

int CIS14::reverseInt(int input){
    int output = 0;
    int checkOver = 0;
    int currentNum = 0;
    int currentCheck = 0;

    while (input != 0)
    {
        currentNum = input % 10;
        currentCheck = currentNum * 1000000000;
        checkOver = output;
        
        if ((currentCheck > 0) && (checkOver > INT_MAX - currentCheck))
        {
            output = 0;
            break;
        }
        if ((currentCheck < 0) && (checkOver < INT_MIN - currentCheck))
        {
            output = 0;
            break;
        }
        
        
        output = (output*10) + currentNum;
        input /= 10;
    }
    
    return output;
}


int main() {
    // instantiate an instance of CIS14 class
   CIS14 cis14;

   // invoke this instance's member function one  by one
   cout << cis14.reverseInt(1) << endl;
   cout << cis14.reverseInt(12) << endl;
   cout << cis14.reverseInt(123) << endl;
   cout << cis14.reverseInt(1234) << endl;
   cout << cis14.reverseInt(1200) << endl;
   cout << cis14.reverseInt(-123) << endl;
   cout << cis14.reverseInt(2147483645) << endl;
   cout << cis14.reverseInt(-2147483645) << endl;

   return 0;
}

/*
TEST FAILED - 
INPUT: -1000000119 
YOUR OUTPUT: -520065409 
EXPECTED: 0 

TEST FAILED - 
INPUT: 1000000007 
YOUR OUTPUT: -1589934591 
EXPECTED: 0 

TEST FAILED - 
INPUT: -1000000007 
YOUR OUTPUT: 1589934591 
EXPECTED: 0
*/