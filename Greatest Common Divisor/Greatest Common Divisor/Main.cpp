// Program to find the greatest common divisor/least common multiple for two numbers, written in C++.
// As usual, the tabbing is messed up.
/* I'd also like to note that I wrote this program for a class, and to submit it, the program had to compile in Visual C++....*/
/* For that reason, the code is a little convoluted and has an extra if statement. */
#include <iostream>
using namespace std;

int main(void)
    {
    int a; //Declare our variables.
    int b;
    int divisor=1;

    //Ask user for their integers.
    cout << "Let's calculate the greatest common divisor and least common multiple of two positive numbers.\n\n";
    cout << "Please enter your first integer: ";
    cin >> a;
    cout << "Please enter your second integer: ";
    cin >> b;

    // Find the greatest common divisor of "a."
    for (int i=1; i <=a ; i++) // This for loop cycles through 1 to a.
        {
        if (a%i == 0) // Check's for the greatest integer divisor of a.
            {
            int astored = a/i; // Stores that greatest integer divisor of a into a variable called astored.
             for (int i=1; i <=b ; i++) /* This for loop cycles through 1 to b. This occurs for every (greatest) divisor of a until something happens.*/
                {
                if (b%i == 0) //Check's for the greatest integer divisor of b.
                    {
                    int bstored = b/i; // Stores that greatest integer divisor of b into a variable called bstored.
                    if (astored == bstored) // Checks to see if the astored value equals the bstored value.
                                if (astored >= divisor ) // If astored is bigger than the current "divisor" variable....
                                {
                                divisor = astored; // Store that astored into "divisor." This is necessary for getting this program to work on Visual Studio...
                                // Let's give our answers.
                                cout << "\nThe greatest common divisor is: " << divisor << endl;
                                int lcm = (a*b)/divisor; // Formula given to us for least common multiple.
                                cout << "The least common multiple is: " << lcm << endl << endl;
                                break;
                                }
                       }
                    }
                }
            }
    
	char zzz;
    cout << "Type something and press enter to end the program. ";
    cin >> zzz;
    return 0;
    }