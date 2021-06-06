/**
 * Assignment #4.2
 * DUE: 9/29
 * NAME: Andy Davis
 * PURPOSE: Write a de-duplication function that iteratively sanitizes (removes) 
 *          all consecutive duplicates in a C++ string
*/

#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: deduplicate
 * PURPOSE: 
 *      This function will internally run as many iterations as needed to 
 *      remove all consecutive duplicates until there is either no consecutive duplicates left, 
 *      or the string becomes empty
 * PARAMETER:
 * 		string input
 * RETURN VALUE:
 * 		string: retrun either "Empty" or non-duplicate values
 * FUNCTION SIGNATURE:
 *      string deduplicate(string input)
*/

string deduplicate(string input)
{
  int i = 0;
  int j = 0;
    
  if (input.length() == 1)
  {
    return input;
  }
    
    
  while (i < input.length()-1)
  {
    while (j < input.length()-1)
    {
      if (input[j] == input[j+1])
      {
        input.erase(j,2);
      }
      else if (input == "")
      {
        input = "Empty";
        break;
      }
      else
      {
        j++;
      }
    }
        
    if (input[i] == input[i+1])
    {
      input.erase(i,2);
    }
    else if (input == "")
    {
      input = "Empty";
      break;
    }
    else
    {
      i++;
    }
  }

  return input;
}



int main() {
  cout << deduplicate("AABB"); // should output "Empty"
  cout << deduplicate("A"); // "A"
  cout << deduplicate("ABBA"); // should output "Empty"
  cout << deduplicate("AAA"); // "A"
  cout << deduplicate("AKA"); // "AKA" because there is no consecutive pair.
  return 0;
}
