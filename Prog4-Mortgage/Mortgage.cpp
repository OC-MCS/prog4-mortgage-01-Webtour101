#include <iostream>
#include "Mortgage.h"

//====================================================== 
// Mortgage: Constructor to initialize different members to 0
// 
//	It is of the Mortgage class.
//
// return type: none
//======================================================
Mortgage::Mortgage()
{
	loan = 0;
	rate = 0;
	years = 0;
}

//====================================================== 
// Mortgage: Constructor to initialize different members to 0
//	It is of the Mortgage class.
// parameters:
//	float l: to be set as the loan value
//  float r: to be set as the intrest rate value
//	int y: to be set as the number of years
// return type: none
//======================================================
Mortgage::Mortgage(float l, float r, int y)
{
	loan = l;
	rate = r;
	years = y;
}

//====================================================== 
// findTerm: function to find the term of the mortgage.
//	It is a private function in the class
// parameters: 
//
// return type: float (returning the term needed for a diferent function)
//======================================================
float Mortgage::findTerm()
{
	float term;

	term = pow((1 + (rate / 12)), (12 * years));

	return term;
}

//====================================================== 
// findPayment: function to find the monthly payments to pay off the mortgage.
//	It is a public function in the class
// parameters: 
//
// return type: float (returning the monthly payment needed to be paid)
//======================================================
float Mortgage::findPayment()
{
	float payment;

	payment = (loan * (rate / 12) * findTerm()) / (findTerm() - 1);

	return payment;
}

//====================================================== 
// findTotal: function to find the total needed to pay off the mortgage.
//	It is a public function in the class
// parameters: 
//
// return type: float (returning the total amount to be spent over a number of years)
//======================================================
float Mortgage::findTotal()
{
	float total;

	total = (findPayment() * 12) * years;

	return total;
}
