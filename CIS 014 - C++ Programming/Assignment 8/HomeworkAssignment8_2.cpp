/**
 * Assignment #8.2
 * DUE: 11/3
 * NAME: Andy Davis
 * PURPOSE: Given a string of number, convert them into a single integer number
*/

#include <iostream>
#include <string>
using namespace std;


/**
 * FUNCTION NAME: convertString2Integer
 * PURPOSE: 
 *      convert a string of numbers to an integer
 * PARAMETER:
 * 		string str
 * RETURN VALUE:
 * 		int output
 * FUNCTION SIGNATURE:
 *      int convertString2Integer(string str)
*/

int convertString2Integer(string str) {
    int output = 0;
    int currentNum = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-') continue;
        currentNum = str[i]-48;
        output = (output*10) + currentNum;
    }
    
    if (str[0] == '-') output = -output;

    return output;
}


int main() {
    cout << convertString2Integer("123") << endl;
    cout << convertString2Integer("-123") << endl;
    cout << convertString2Integer("0000012") << endl;
    cout << convertString2Integer("1200") << endl;
}