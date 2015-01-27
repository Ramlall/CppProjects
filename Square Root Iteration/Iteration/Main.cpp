#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main(void)
    {
    // VARIABLE INITIALIZATION
    double a; 
    double e;
    double x0;
    double x1;
    char optimus;

    // ASK USER FOR INFO
    cout << "Hey there. Let's find the square root of a number using C++." << endl << endl;
    cout << "Which number would you like to find the square root of? ";
    cin >> a;
    cout << "Please enter your tolerance. (Usually .0000001 (six zeroes).) ";
    cin >> e;
    cout << "Please enter a guess of the answer. ";
    cin >> x0;

    // OUTSTREAM STUFF
    const char filepath[] = "C:\\work\\Iteration_Output.txt";
    const char ErrorMessage[] = "Can't open file location.";
    fstream OutStream(filepath, ios::out);
    if (OutStream.fail())
        {
        cerr << ErrorMessage << filepath;
        cin >> optimus;
        exit(-1);
        }

    // REPEAT INFO
    cout << "\n\nYour number is " << a << " and your guess is " << x0 << "." << endl << endl;
    OutStream << 0 << "   " << x0 << endl;

    // CALCULATE SQUARE ROOT & OUTPUT ANSWERS
    for (int w = 1; w < w + 1; w++) // Loop will go on forever...until we break it. 
        {
        x1 = (x0 + a/x0)/2;
        cout << w << "   " << setprecision(15) << x1 << endl;
        OutStream << w << " " << setprecision(15) << x1 << "\n";
        if (abs((x1 - x0)) < e)
            {
            break;
            }
        x0 = x1;
        }

    // PROGRAM END
    OutStream.close();
    cout << "\n\nOnly a Prime can stop the Fallen. ";
    cin >> optimus;
    return 0;
    }