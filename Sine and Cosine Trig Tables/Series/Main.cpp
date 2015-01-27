#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double GetFactorial(double placeholder)
{
	if (placeholder == 0)
		{
		return 1.0;
		}
	double temporary = placeholder * GetFactorial(placeholder - 1.0);
	return temporary;
}

int main(void)
	{
	//*****************************************
	// DECLARE VARIABLES
	//*****************************************
	char spiderman;
	double degrees; // Number of degrees we go up too for our trig table.
	double intervals; // Number of intervals we move up by.
	double i = 0.0; // We need to declare and initialize this now so we can write formulas for sin and cosine.
	double sine;
	double cosine;
	double x = 0.0;
	double pi = 4*atan(1.0);

	//*****************************************
	// OUTSTREAM INITALIZATION
	//*****************************************
	const char filepath[] = "C:\\work\\Series_Trig_Table.txt";
		const char ErrorMessage[] = "Can't open file location.";
		fstream OutStream(filepath, ios::out);
		if (OutStream.fail())
			{
			cerr << ErrorMessage << filepath;
			cin >> spiderman;
			exit(-1);
			}


	//*****************************************
	// INTRODUCTION
	//*****************************************
	cout << "Today we'll be calculating a trig table for sine and cosine using their series." << endl;
	cout << "We'll be starting from 0 degrees." << endl;
	cout << "How many degrees could you like to go up too? (For this project, it's 45.) ";
	cin >> degrees;
	cout << "How many intervals would you like to move up by? (For this project, it's 5.) ";
	cin >> intervals;
	cout << "The output will look like: " << endl;
	cout << "Degree   Numberofterms   Sin(degree)/Cos(degree)";
	cout << endl << endl;

	OutStream << "Today we'll be calculating a trig table for sine and cosine using their series." << endl;
	OutStream << "The maximum degree we chose is " << degrees << " and the number of intervals is " << intervals << "." << endl;
	OutStream << "The output will look like: " << endl;
	OutStream << "Degree   Numberofterms   Sin(degree)/Cos(degree)";
	OutStream << endl << endl;

	//*****************************************
	// FORMULAS
	//*****************************************
	// I'm gonna do two tricks to make this neat.
	// I'm going to use cmath's power function to calculate the power.
	// And since cmath doesn't have factorial's, I'm going to use recursion to get the factorial term.
	//sine = pow(-1.0,i) * pow(x, 2*i+1) / GetFactorial(2*i+1);
	//cosine = pow(-1.0,i) * pow(x, 2*i) / GetFactorial(2*i);

	//*****************************************
	// CALCULATIONS
	//*****************************************
	// I'm going to break this into two different calculations so the output looks neat.

	//******************
	// SINE CALCULATION
	//******************
	cout << "Sine trig table: " << endl;
	OutStream << "Sine trig table: " << endl;
	for (double w = 0.0 ; w <= degrees; w=w+intervals) // For loop to get our degrees. 
		{
		double sum = 0.0;
		for(int i = 0; i < i+1; i++) // Forever for loop.
			{
			x = pi*w/180; // Say x is equal to whatever degree we're working on.
			sine = pow(-1.0,i) * pow(x, 2*i+1) / GetFactorial(2*i+1);
			sum = sum + sine;

			if (abs(sum - sin(pi*w/180)) < .0001)
				{
				cout << setprecision(12) << w << "   " << i << "   " << sum << endl;
				OutStream << setprecision(12) << w << " , " << i << " , " << sum << " , " << endl;
				break;
				}
			}
		}

	//*******************
	// COSINE CALCULATION
	//*******************
	cout << endl << endl << "Cosine trig table: " << endl;
	OutStream << endl << endl << "Cosine trig table: " << endl;
	for (double w = 0.0 ; w <= degrees; w=w+intervals) // For loop to get our degrees. 
		{
		double sum = 0.0;
		for(int i = 0; i < i+1; i++) // Forever for loop.
			{
			x = pi*w/180; // Say x is equal to whatever degree we're working on.
			cosine = pow(-1.0,i) * pow(x, 2*i) / GetFactorial(2*i);
			sum = sum + cosine;

			if (abs(sum - cos(pi*w/180)) < .0001)
				{
				cout << setprecision(12) << w << "   " << i << "   " << sum << endl;
				OutStream << setprecision(12) << w << " , " << i << " , " << sum << " , " << endl;
				break;
				}
			}
		}

	//*****************************************
	// END OF PROGRAM
	//*****************************************
	OutStream.close();
	cout << "\n\nThe best superhero is the Amazing ";
	cin >> spiderman;
	return 0;
	}