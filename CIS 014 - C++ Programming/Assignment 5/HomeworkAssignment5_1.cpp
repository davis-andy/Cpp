/**
 * Assignment #5.1
 * DUE: 10/6
 * NAME: Andy Davis
 * PURPOSE: Write the following function that compares the two version strings, 
 *          ver1 and ver2, of a software product to determine which product version is the latest
*/




///////////use the dynamic allocation as mentioned in class with delete[] array////////////////////////




#include <iostream>
#include <string>
using namespace std;


/**
 * FUNCTION NAME: compareVersions
 * PURPOSE: 
 *      Compare two software versions and determines which one is the latest
 * PARAMETER:
 * 		string ver1, string ver2
 * RETURN VALUE:
 * 		1: ver1 > ver2
 *      -1: ver1 < ver2
 *      0: ver1 = ver2
 * FUNCTION SIGNATURE:
 *      int compareVersions(string ver1, string ver2)
*/

int compareVersions(string ver1, string ver2)
{
    char delimiter = '.';
    if (ver1[0] == delimiter) ver1.insert(0, "0");
    if (ver2[0] == delimiter) ver2.insert(0, "0");


    int arraySize = 0;
    int counter1 = 0;
    int counter2 = 0;

    for (int search1 = 0; search1 < ver1.length(); search1++)
    {
        if (ver1[search1] == delimiter) counter1++;
    }
    for (int search2 = 0; search2 < ver2.length(); search2++)
    {
        if (ver2[search2] == delimiter) counter2++;
    }

    if (counter1 < counter2) arraySize = counter2 + 1;
    else if (counter1 > counter2) arraySize = counter1 + 1;
    else if (counter1 == counter2) arraySize = counter2 + 1;

    int ver1num[arraySize] = {0};
    int ver2num[arraySize] = {0};


    int test1 = 0, step1;
    int test2 = 0, step2;
    
    for (step1 = 0; ver1[step1] != '\0'; step1++)
    {
        if (ver1[step1] == delimiter)
        {
            test1++;
        } 
        else ver1num[test1] = ver1num[test1] * 10 + (ver1[step1] - 48);
    }
    
    for (step2 = 0; ver2[step2] != '\0'; step2++)
    {
        if (ver2[step2] == delimiter)
        {
            test2++;
        } 
        else ver2num[test2] = ver2num[test2] * 10 + (ver2[step2] - 48);
    }


    int step = 0;

    while (step < arraySize)
    {
        if (ver1num[step] < ver2num[step])
        {
            return -1;
            break;
        }
        
        if (ver1num[step] > ver2num[step])
        {
            return 1;
            break;
        }
        
        step++;
    }
    

    return 0;
}


int main()  
{
//   cout << compareVersions("0.1", "0.2") << "\n";  //-1
//   cout << compareVersions("0.1.1", "0.13.2") << "\n"; //-1
//   cout << compareVersions("1.0", "1.0") << "\n";  //0
//   cout << compareVersions("6", "6") << "\n";  //0
//   cout << compareVersions("0", "0") << "\n";  //0
//   cout << compareVersions("1.1.0", "1.1.1") << "\n";  //-1
//   cout << compareVersions("1.1.1", "1.1.2") << "\n";  //-1
//   cout << compareVersions("1.1.2", "1.2.0") << "\n";  //-1
//   cout << compareVersions("1.2.0", "1.2.1") << "\n";  //-1
//   cout << compareVersions("1.2.1", "1.3.1") << "\n";  //-1
//   cout << compareVersions("1.3.1", "8.8.8") << "\n";  //-1
//   cout << compareVersions("1", "1.1") << "\n";  //-1
//   cout << compareVersions("1.1", "1.1.0") << "\n";  //0
//   cout << compareVersions("256", "300.2.1") << "\n";  //-1
//   cout << compareVersions("0.1", "1") << "\n";  //-1
//   cout << compareVersions("3", "3.1.1") << "\n";  //-1
//   cout << compareVersions("3.1.1", "4") << "\n";  //-1
//   cout << compareVersions(".0.4", ".1") << "\n";  //-1
//   cout << compareVersions(".2", ".1.1") << "\n";  //1
//   cout << compareVersions("2.3.2.2.3.1.1.5.3.5.6.2", "1.1.1.1.1.1.1") << "\n";  //1

   return 0;
}
