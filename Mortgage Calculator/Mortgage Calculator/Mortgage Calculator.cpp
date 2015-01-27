//Program to calculate how much the monthly payment of a mortgage will be 
// and how much interest will be paid.
#include <iostream>
#include <cmath>
using namespace std;

double GetStuff()
	{
	double mpayment; // Fixed monthly payments
    double rate; // Rate of interest
    double principle; // How much you the house costs
    double downpayment; // How much of a downpayment you put down on the house
    double years; // Number of years you expect to pay the mortgage for

	cout << "How much does the property cost? $";
    cin >> principle;

    cout << "How much of a downpayment are you making? $";
    cin >> downpayment;

    cout << "What rate of interest are you paying (in percentage)? ";
    cin >> rate;

    cout << "How many years do you expect you will be paying this mortgage? ";
    cin >> years;

    int princ = principle - downpayment;
    float irate = rate / 1200;
    float denominator = pow(1.0+irate, - (years * 12));

    mpayment = (princ) * (irate) / (1 - (denominator) );

    float cost;

    cost = (mpayment * 12 * years) - princ;

    cout << "\n\nYour monthly payment will be $" << mpayment << "." << endl;
    cout << "The interest paid over the course of the mortgage is $" << cost << ". \n\n" << endl;

    GetStuff();
	return 0;
	}

int main(void)
    {
    cout << "Today we'll calculate how much the monthly payment a mortgage" << endl;
	cout << "will be and how much interest will be paid over the life of the mortgage.\n\n";

	GetStuff();

    return 0;
    }