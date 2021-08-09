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
    int i = v.size()-1;
    
    for (i; i >= 0; i--)
    {
        if (i == v.size()-1)
        {
            if (v[i] == 9)
            {
                v[i] = 0;
            }
            else v[i]++;
        }
        else if (v[i+1] == 0)
        {
             if (v[i] == 9)
            {
                v[i] = 0;
            }
            else v[i]++;
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
    vector<int> v {9, 9};
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

    '''
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 0]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 1]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 1] - TEST FAILED -
    
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 1]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 2]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 2] - TEST FAILED - 
    
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 2]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 3]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 3] - TEST FAILED - 
    
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 3]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 4]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 4] - TEST FAILED -
    
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 4]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 5]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 5] - TEST FAILED -
    
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 5]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 6]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 6] - TEST FAILED -
    
    INPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 6]
    YOUR OUTPUT: [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 1, 0, 7]
    EXPECTED:    [1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 1, 9, 4, 0, 0, 7] - TEST FAILED -
    
    INPUT: [1, 0, 0]
    YOUR OUTPUT: [2, 0, 1]
    EXPECTED:    [1, 0, 1] - TEST FAILED -
    
    INPUT: [1, 0, 1]
    YOUR OUTPUT: [2, 0, 2]
    EXPECTED:    [1, 0, 2] - TEST FAILED -
    
    INPUT: [1, 0, 0]
    YOUR OUTPUT: [2, 0, 1]
    EXPECTED:    [1, 0, 1] - TEST FAILED -
    
    INPUT: [1, 0, 1]
    YOUR OUTPUT: [2, 0, 2]
    EXPECTED:    [1, 0, 2] - TEST FAILED -
    
    INPUT: [1, 0, 2]
    YOUR OUTPUT: [2, 0, 3]
    EXPECTED:    [1, 0, 3] - TEST FAILED -
    
    INPUT: [9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    YOUR OUTPUT: [1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
    EXPECTED:       [9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1] - TEST FAILED -
    
    INPUT: [9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
    YOUR OUTPUT: [1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2]
    EXPECTED:       [9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2]
    '''