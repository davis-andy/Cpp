/**
 * Homework Assignment #2.2
 * DUE: 9/15
 * NAME: Andy Davis
 * PURPOSE: To write a simple console application that takes a user's numeric coin amount input 
 *          and returns a string output (using the USD units of currency).
 * */

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
    double usd;
	int half_dollars;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
    int totalCoins;
    int totalPennies;

    cout << "Enter half dollars: ";
    cin >> half_dollars;
    cout << "\nEnter quarters: ";
    cin >> quarters;
    cout << "\nEnter dimes: ";
    cin >> dimes;
    cout << "\nEnter nickels: ";
    cin >> nickels;
    cout << "\nEnter pennies: ";
    cin >> pennies;

    totalCoins = half_dollars + quarters + dimes + nickels + pennies;
    totalPennies = (half_dollars * 50) + (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;
    usd = (double)totalPennies / 100;
    ostringstream usdstr;
	usdstr << fixed << setprecision(2) << usd;

    string sentence ("\nThe value of your " + to_string(totalCoins) + " coins is equivalent to " +
        to_string(totalPennies) + " pennies, or $" + usdstr.str() + " USD");
    cout << sentence;

    return 0;
}


/*
Enter half dollars: 14

Enter quarters: 25

Enter dimes: 2

Enter nickels: 4

Enter pennies: 10

The value of your 55 coins is equivalent to 1375 pennies, or $13.75 USD 
*/