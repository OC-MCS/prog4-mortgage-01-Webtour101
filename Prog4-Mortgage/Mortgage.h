#pragma once

using namespace std;

// Identifying the Mortgage class
class Mortgage
{
// Private members of the class, can only be used 
private:
	float loan;
	double rate;
	int years;
	float findTerm();

// Public member of the class, able to be accessed by main. 
public:
	Mortgage();
	Mortgage(float, float, int);
	float findPayment();
	float findTotal();
};