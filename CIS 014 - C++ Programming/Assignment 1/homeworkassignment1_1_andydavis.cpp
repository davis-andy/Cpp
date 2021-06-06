/**
 * Homework Assignment #1
 * DUE: 9/8
 * NAME: Andy Davis
 * PURPOSE: To write a simple console application that takes a user's numeric "pennies" input 
 *          and returns a string output (using the USD units of currency).
*/

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    double user;
	cout << "Please enter all of your pennies\n";
	cin >> user;


	double usdTotal = user / 100;
	double cad = usdTotal * 1.33;
	ostringstream cadstr;
	cadstr << fixed << setprecision(2) << cad;
	int dollars = user / 100;
	int cents = ((int)user % 100);
	int quarters = cents / 25;
	int dimes = (cents - (quarters * 25)) / 10;
	int nickles = (cents - (quarters * 25) - (dimes * 10)) / 5;
	int pennies = (cents - (quarters * 25) - (dimes * 10) - (nickles * 5));

	cout << "In US currency you have: " << dollars << " dollars, ";
	cout << quarters << " quarters, " << dimes << " dimes, ";
	cout << nickles << " nickles, and " << pennies << " pennies.\n";
	cout << "In Canadian currency you have: " << cadstr.str() << " dollars.";
	return 0;
}