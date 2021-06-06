/**
 * Assignment #5.2
 * DUE: 10/6
 * NAME: Andy Davis
 * PURPOSE: Write the following function that compares the two version strings, 
 *          ver1 and ver2, of a software product to determine which product version is the latest
*/

#include <iostream>
#include <string>
using namespace std;


/**
* FUNCTION NAME: getSecretMessage
 * PURPOSE: get secret message by taking the first character from each word in the input sentence, 
 *          in the order they appear
 * PARAMETER:
 *     str, the input sentence 
 * RETURN VALUE:
 *     The secret message
  * FUNCTION SIGNATURE:
 *     string getSecretMessage(string str)
*/

string getSecretMessage(string str)
{
    string message;
    char delimiter = ' ';
    bool delimHit = true;
    int i = 0;

    for (i; i < str.length(); i++)
    {
        if (str[i] == delimiter)
        {
            delimHit = true;
        }
        else if (str[i] != delimiter && delimHit == true)
        {
            message += str[i];
            delimHit = false;
        }
        
    }

    return message;
}


int main()  
{
   cout << getSecretMessage("professor can code") << endl; // prints "pcc"
   cout << getSecretMessage("                ") << endl;  // prints nothing
   cout << getSecretMessage("pasadena") << endl;  // prints "p"

   return 0;
}
