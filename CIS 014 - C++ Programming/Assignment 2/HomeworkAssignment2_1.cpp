/**
 * Homework Assignment #2.1
 * DUE: 9/15
 * NAME: Andy Davis
 * PURPOSE: To write a simple console application that takes a user's numeric "pennies" input 
 *          and returns a string output (using the USD units of currency), and converts it to Canadian dollars.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

/**
 * FUNCTION NAME: breakCash
 * PURPOSE: the function takes in the total of pennies from the user as input, computes its equivalent in
 * dollars, quarters, dimes, nickels, and pennies, and outputs the result in string to the console
 * PARAMETER:
 * 		int numPennies
 * RETURN VALUE:
 * 		string: result in dollars, quarters, dimes, nickels, and pennies
 * FUNCTION SIGNATURE:
 * string breakCash(int numPennies)
*/

string breakCash(int numPennies)
{
	double cad = (numPennies * 1.33) / 100;
	ostringstream cadstr;
	cadstr << fixed << setprecision(2) << cad;
	int dollars = numPennies / 100;
	int cents = numPennies % 100;
	int quarters = cents / 25;
	int dimes = (cents - (quarters * 25)) / 10;
	int nickels = (cents - (quarters * 25) - (dimes * 10)) / 5;
	int pennies = (cents - (quarters * 25) - (dimes * 10) - (nickels * 5));
	
	
	string sentence ("In US currency you have: " + to_string(dollars) + " dollars, " +
		to_string(quarters) + " quarters, " + to_string(dimes) + " dimes, " + 
		to_string(nickels) + " nickels, " + to_string(pennies) + " pennies.\n" +
		"In Canadian currency you have: " + cadstr.str() + " dollars.");
	
	return sentence;
}



int main()
{
	int numOfPennies = 0;
    cout << "Please enter all of your pennies: " << endl;
    cin >> numOfPennies;
    cout << breakCash(numOfPennies);
    return 0;
}


/*
Please enter all of your pennies: 
23456
In US currency you have: 234 dollars, 2 quarters, 0 dimes, 1 nickels, 1 pennies.
In Canadian currency you have: 311.96 dollars. 
*/