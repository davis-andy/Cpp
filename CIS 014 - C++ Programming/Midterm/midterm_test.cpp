#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str = "P C c?"; // note `c` is lowercase, not capital.

    char arr[128];
    for (int i = 0; i<128; i++)
    {
        arr[i] = i+1;
    }

    int counter[128] = {0};

    for (int j = 0; str[j]; j++)
    {
        counter[str[j]-1]++;
    }

    for(int x=0; x<128 ; x++)
    {
        if (counter[x] > 0)
        {
            cout << arr[x] << ": " << counter[x] << endl;
        }
        else continue;
    }


    return 0;
}