/**
 * Assignment #3.1
 * DUE: 9/22
 * NAME: Andy Davis
 * PURPOSE: You have a C++ string of finite length consisting of only 'a' and 'b's in it. 
 *      Write the following function to separate all of the 'a' and 'b' in the string so 
 *      that all 'a' appear before 'b' in it
*/

#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: 
 *      separateLetters
 * PURPOSE: 
 *      Separate a string of finite length consisting of only 'a' and 'b's 
 *      in it so that all 'a' appear before 'b'.
 * PARAMETER:
 * 		string input
 * RETURN VALUE:
 * 		string: result is sorted with all 'a's in the front and 'b's in the back
 * FUNCTION SIGNATURE:
 *      string separateLetters(string input)
*/

string separateLetters(string input)
{
    string sorted = input;
    for (int i = 0; i < sorted.length() - 1; i++)
    {
        int j;
        int jBefore = i;

        for (j = i + 1; j < sorted.length(); j++)
        {
            if (sorted[j] < sorted[jBefore])
            {
                jBefore = j;
            }
        }

        if (jBefore != i)
        {
            swap(sorted[i], sorted[jBefore]);
        }
    }

    return sorted;
}


int main()
{
    string result;
    cout << "Input: ";
    cin >> result;
    cout << "Output: " << separateLetters(result);
    return 0;
}