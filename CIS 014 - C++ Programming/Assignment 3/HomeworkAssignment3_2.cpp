/**
 * Assignment #3.2
 * DUE: 9/22
 * NAME: Andy Davis
 * PURPOSE: You and your friend decide to play a game to remove these pebbles, 
 *          one or several at a time, to prove that one of you is the Ultimate Strategist at PCC.
*/

#include <iostream>
using namespace std;


/**
 * FUNCTION NAME: CanIAlwasyWin
 * PURPOSE: To see if you are always the winner given n as your starting quantity of pebbles.
 * PARAMETER:
 * 		int n
 * RETURN VALUE:
 * 		boolean: result in true/false
 * FUNCTION SIGNATURE:
 *      bool CanIAlwaysWin(int n)
*/

bool CanIAlwaysWin(int n)
{
    bool result;

    if (n % 5 == 0)
    {
        result = false;
    }
    else
    {
        result = true;
    }
    
    cout << boolalpha;
    return result;
}


int main() 
{
   int n = 0;
   cout << "Enter a number: ";
   cin >> n;
   cout << "Can I win: " << CanIAlwaysWin(n);
   return 0;
}
