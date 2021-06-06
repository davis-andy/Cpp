#include <iostream>
#include <string>
using namespace std;


char findHalfDuplicate(string s)
{
    char result;
    string test;
    for (int i = 0; i < s.length(); i++)
        {
            test = s[i];
            if (test[i] == s[i+1])
            {
                result = s[i];
            }
        }
}

