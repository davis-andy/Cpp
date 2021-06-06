/**
 * Assignment #4.1
 * DUE: 9/29
 * NAME: Andy Davis
 * PURPOSE: Take any arbitrary number, n, and append zero (0) or more numeric digits 
 *          at the end of it to obtain a palindrome.
*/

#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: reverseString
 * PURPOSE: 
 *      Reverses a string
 * PARAMETER:
 * 		string input
 * RETURN VALUE:
 * 		string
 * FUNCTION SIGNATURE:
 *      string reverseString(string input)
*/


string reverseString(string input)
{
    string result;

    //create reverse string
    for (int i = input.length()-1; i >= 0; i--)
    {
        result += input[i];
    }

    return result;
}

/**
 * FUNCTION NAME: getShortestLength
 * PURPOSE: 
 *      Returns the integral length of your shortest possible palindrome.
 * PARAMETER:
 * 		int n
 * RETURN VALUE:
 * 		integer
 * FUNCTION SIGNATURE:
 *      int getShortestLength(int n)
*/

int getShortestLength(int n)
{
    //convert to string
    string strNum = to_string(n);
    string backwards = reverseString(strNum);
    int palindromeLength = 0;
    int result = 0;
    string palindromeStr;
    string addOn;
    int counter = 0;

    if (n < 0) result = 0;

    //check if palindrome
    else if (strNum == backwards)
    {
        result = strNum.length();
    }

    else
    {
        //iterate from back to front
        for (int i = 0; i < backwards.length(); i++)
        {
            addOn += backwards[i];
            string tCheck = reverseString(addOn);
            if (addOn == tCheck)
            {
                counter = i + 1;
            }
        }

        addOn.erase(0, counter);
        palindromeStr = strNum + addOn;
        palindromeLength = palindromeStr.length();
        result = palindromeLength;
    }

    return result;
}

int main() {
    cout << getShortestLength(121) << "\n";
    cout << getShortestLength(12393) << "\n";
    cout << getShortestLength(123) << "\n";
    cout << getShortestLength(-234) << "\n";
    cout << getShortestLength(4) << "\n";
    cout << getShortestLength(12434434) << "\n";
  return 0;
}
