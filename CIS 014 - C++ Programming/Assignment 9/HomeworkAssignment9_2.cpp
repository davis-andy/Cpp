/**
 * Assignment #9.2
 * DUE: 11/10
 * NAME: Andy Davis
 * PURPOSE: To find if a string is present in a dictionary or not
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class CIS14 {
   public:
      bool isInputInDictionary(string* s, unordered_set<string> &dict);
};


/**
 * MEMBER FUNCTION NAME: 
 *    isInputInDictionary
 * PURPOSE: 
 *    The function takes in a word and compares it with the list of words in the dictionary string array,
 *    returning the true or false (in the dictionary or not)
 * PARAMETER:
 *    string* s
 *    unordered_set<string> &dict
 * RETURN VALUE:
 *    bool: the input is consisted of words only in the dictionary or not
*/


bool CIS14::isInputInDictionary(string* s, unordered_set<string> &dict){   
   vector<int> result((*s).size()+1, 0);
   result[0] = 1;
   
   for (int i = 1; i <= (*s).size(); i++) {
      for (int j = i-1; j >= 0; j--) {
         if (dict.count((*s).substr(j, i-j))) {
            result[i] = 1;
            break;
         }
      }
   }
   
   cout << boolalpha;
   return result[(*s).size()];
}


int main() {
   string a = "joe";
   unordered_set<string> aa = {"joe1", "joe"};

   string b = "joey";
   unordered_set<string> bb = {"joe1", "joe"};

   string c = "applepie";
   unordered_set<string> cc = {"apple", "pie"};

   string d = "hellonow";
   unordered_set<string> dd = {"hello", "on", "hell", "now"};

   string e = "hellonowl";
   unordered_set<string> ee = {"hell", "on", "owl"};


   CIS14 cis;

   cout << cis.isInputInDictionary(&a, aa) << endl; //true
   cout << cis.isInputInDictionary(&b, bb) << endl; //false
   cout << cis.isInputInDictionary(&c, cc) << endl; //true
   cout << cis.isInputInDictionary(&d, dd) << endl; //true
   cout << cis.isInputInDictionary(&e, ee) << endl; //true
    
}