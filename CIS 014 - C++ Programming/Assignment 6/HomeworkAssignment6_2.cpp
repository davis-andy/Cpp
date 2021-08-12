/**
 * Assignment #6.2
 * DUE: 10/13
 * NAME: Andy Davis
 * PURPOSE: Write a function that simulates ++N by taking in its vector representation
 *           as the function parameter. The function returns the result of ++N in its vector form.
*/


////////////FAILED!!!///////////////


#include <iostream>
#include <vector>
using namespace std;


/**
 * FUNCTION NAME: plusPlusN
 * PURPOSE:
 *      A function that simulates ++N on a vector
 * PARAMETER:
 * 		vector<int> v
 * RETURN VALUE:
 * 		vector<int> v
 * FUNCTION SIGNATURE:
 *      vector<int> plusPlusN(vector<int> v)
*/

vector<int> plusPlusN(vector<int> v)
{
    int temp = v[v.size() - 1];

    if (v[v.size() - 1] == 9)
    {
        v[v.size() - 1] = 0;
    }
    else
    {
        v[v.size() - 1]++;
    }

    for (int i = v.size() - 2; i >= 0; i--)
    {
        if ((temp == 9) && (v[i + 1] != temp))
        {
            temp = v[i];
            if (v[i] == 9)
            {
                v[i] = 0;
            }
            else
            {
                v[i]++;
            }
        }
        else
        {
            temp = v[i];
        }
    }


    vector<int>::iterator it = v.begin();

    if (v[0] == 0)
    {
        v.insert(it, 1);
    }

    return v;
}


int main() {
    vector<int> v{ 9, 9 };
    vector <int> retVal = plusPlusN(v); // retVal = {1, 0, 0}
    // insert you own assert or other test code here
    vector<int>::iterator i = retVal.begin();
    cout << "{";
    for (i; i < retVal.end(); i++)
    {
        cout << *i;
    }
    cout << "}";

    return 0;
}
