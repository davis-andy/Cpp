/**
 * Assignment #9.1
 * DUE: 11/10
 * NAME: Andy Davis
 * PURPOSE: To find out if the addresses are able to be created or not given the inventory
*/

#include <iostream>
#include <map>
using namespace std;

class CIS14 {
public:
    int getNumPossibleSigns(string* letterInventory, string* addresses, int length);
};


/**
 * MEMBER FUNCTION NAME: 
 *    getNumPossibleSigns
 * PURPOSE: 
 *    The function takes in a series of addresses in a string array and compares each of them with the available 
 *    letterInventory, returning the number of addresses that are POSSIBLE to form from the given letterInventory
 * PARAMETER:
 *    string* letterInventory
 *    string* addresses
 *    int length: length of the array, addresses[]
 * RETURN VALUE:
 *    int: the number of possible addresses that can be formed from your inventory of letters
*/


int CIS14::getNumPossibleSigns(string* letterInventory, string* addresses, int length){
    int result = length;
    map<char,int> test;
    string s = *letterInventory;
    
    map<char,int> inventory;
    for (int i = 0; i < s.size(); i++){
        inventory[s[i]]++;
    }


    
    for (int x = 0; x < length; x++){
        for (int y = 0; y < addresses[x].length(); y++){
            if (addresses[x][y] == ' ') continue;
            else test[addresses[x][y]]++;
        }
        
        for (int z = 0; z < addresses[x].length(); z++){
            if (test[addresses[x][z]] > inventory[addresses[x][z]]){
                result--;
                break;
            }
            else continue;
            
        }
        
        test.clear();
    }
    
    return result;
}


int main() {
    CIS14 cis14;

    string a = "AAAABCCC123456789";
    string aa[] = {"123C","123A","123 ADA"};

    string b = "ABCDEFGHIJKLMNORSTUVWXYZ1234567890";
    string bb[] = {"2 FIRST ST"," 13 PUN ST", "101 AKER"};

    string c = "ABCDAAST";
    string cc[] = {"999 S ST", "A BAD ST", "B BAD ST"};

    int lengthA = sizeof(aa)/sizeof(aa[0]);
    int lengthB = sizeof(bb)/sizeof(bb[0]);
    int lengthC = sizeof(cc)/sizeof(cc[0]);
    

    cout << cis14.getNumPossibleSigns(&a, aa, lengthA) << endl; //2
    cout << cis14.getNumPossibleSigns(&b, bb, lengthB) << endl; //0
    cout << cis14.getNumPossibleSigns(&c, cc, lengthC) << endl; //1
}