#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;



int main()
{
	int numPennies = 0;
	cout << "Please enter all of your pennies: " << endl;
	cin >> numPennies;
	double cad = (numPennies * 1.33) / 100;
	std::ostringstream cadstr;
	cadstr << std::fixed << std::setprecision(2) << cad;
	int dollars = numPennies / 100;
	int cents = numPennies % 100;
	int quarters = cents / 25;
	int dimes = (cents - (quarters * 25)) / 10;
	int nickles = (cents - (quarters * 25) - (dimes * 10)) / 5;
	int pennies = (cents - (quarters * 25) - (dimes * 10) - (nickles * 5));

	std::cout << "In US currency you have: " << dollars << " dollars, ";
	std::cout << quarters << " quarters, " << dimes << " dimes, ";
	std::cout << nickles << " nickles, and " << pennies << " pennies.\n";
	std::cout << "In Canadian currency you have: " << cadstr.str() << " dollars.";
	return 0;
}