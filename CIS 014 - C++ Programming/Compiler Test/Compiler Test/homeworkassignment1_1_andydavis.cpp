/**
 * Homework Assignment #1
 * DUE: 9/8
 * NAME: Andy Davis
 * PURPOSE: To write a simple console application that takes a user's numeric "pennies" input 
 *          and returns a string output (using the USD units of currency).
*/

#include <iostream>
using namespace std;

int main()
{
    float penny;
	cout << "Please enter all of your pennies\n";
	cin >> penny;


	float usdTotal = penny / 100;
	float cad = usdTotal * 1.33;
	int dollars = penny / 100;
	int cents = ((int)penny % 100);
	int quarters = cents / 25;
	int dimes = (cents - (quarters * 25)) / 10;
	int nickles = (cents - (quarters * 25) - (dimes * 10)) / 5;
	int pennies = (cents - (quarters * 25) - (dimes * 10) - (nickles * 5));

	cout << "In US currency you have: " << dollars << " dollars, ";
	cout << quarters << " quarters, " << dimes << " dimes, ";
	cout << nickles << " nickles, and " << pennies << " pennies.\n";
	cout << "In Canadian currency you have: " << cad << " dollars.";
	return 0;
}