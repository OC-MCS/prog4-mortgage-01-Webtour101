#include <iostream>
#include <string>
#include <iomanip>  
#include "Mortgage.h"  // To include the created class

using namespace std;

// Function prototype
bool garbageTester1(string input, int& output);
bool garbageTester2(string input, float& output);

int main()
{
	// Initializing variables
	Mortgage newHouse;
	float total;
	float payment;
	string loan;
	float borrowed;
	string rate;
	float intrest;
	string years;
	int time;

	cout << "What is the amount of your current loan? " << endl << "$ ";
	getline(cin, loan);

	// Testing for a valid input 
	if (!garbageTester2(loan, borrowed))
	{
		cout << "Sorry, that is not a valid input. Please try again" << endl;
		getline(cin, loan);
	}

	cout << "What is the current intrest rate? " << endl << "% ";
	getline(cin, rate);

	// Testing for a valid input
	if (!garbageTester2(rate, intrest))
	{
		cout << "Sorry, that is not a valid input. Please try again" << endl;
		getline(cin, rate);
	}

	cout << "How many years do you want to spread the payments out over ? " << endl;
	getline(cin, years);

	// Testing for a valid input
	if (!garbageTester1(years, time))
	{
		cout << "Sorry, that is not a valid input. Please try again" << endl;
		getline(cin, years);
	}

	// Calculating the intrest rate into a decimal
	intrest = (intrest / 100);

	// Initializing a class with specific values.
	newHouse = {borrowed, intrest, time};

	// Calling the class' member function to find the monthly payment needed
	payment = newHouse.findPayment();

	// Calling the class' member function to find the total payment made.
	total = newHouse.findTotal();

	cout << fixed << setprecision(2);
	cout << "The monthly payments needed to be made is: $ " << payment << endl;
	cout << "The total to be paid over the course of " << years << " years is: $ " << total << endl;

	return 0;
}

//====================================================== 
// garbageTester1: function to convert a string to an integer.
//	If not possible, returns a false bool.
// parameters: 
//   input: The string the user typed in
//   output: Passed by reference, containing the converted int
// return type: bool (returning if the string was converted or not)
//======================================================
bool garbageTester1(string input, int& output)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(input);
		output = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

//====================================================== 
// garbageTester1: function to convert a string to a float.
//	If not possible, returns a false bool.
// parameters: 
//   input: The string the user typed in
//   output: Passed by reference, containing the converted float
// return type: bool (returning if the string was converted or not)
//======================================================
bool garbageTester2(string input, float& output)
{
	float num;
	bool success = true;
	try
	{
		num = stof(input);
		output = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}