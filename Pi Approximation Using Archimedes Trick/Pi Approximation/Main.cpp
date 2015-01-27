#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
    {
    // DECLARE THE VARIABLES
    char clorox;
    double polygonSides;
    double insideA;
    double outsideB;
    double commonA = .5;
    double perimeterA;
    double perimeterB;
    double error;

    //OUTSTREAM
    const char filepath[] = "C:\\work\\Pi_Output.txt";
    const char ErrorMessage[] = "Can't open file location.";
    fstream OutStream(filepath, ios::out);
    if (OutStream.fail())
        {
        cerr << ErrorMessage << filepath;
        cin >> clorox;
        exit(-1);
        }

    // INTRO
    cout << "Hey there! We're going to compute pi using Archimedes' trick.\n";
    cout << "The columns (in order) are: \nPolygon side length \nThe side length of the inside polygon";
    cout << "\nThe side length of the outside polygon";
    cout << "\nThe guess of pi from the circle using the inside polygon";
    cout << "\nThe guess of pi from the circle using the outside polygon";
    cout << "\nThe error of pi, gotten from difference in perimeters" << endl << endl << endl;

    // CALCULATIONS
    for (int i = 0; i <= 29; i++)
        {
        polygonSides = 6*pow(2.0, i);
        insideA = sqrt((1-sqrt(1-commonA*commonA))/2);
        outsideB = commonA / sqrt(1-commonA*commonA);
        perimeterA = commonA * polygonSides;
        commonA = insideA;
        perimeterB = outsideB * polygonSides;
        error = perimeterB - perimeterA;

        cout << polygonSides << " ";
        //cout << setprecision(6) << insideA << " ";
        //cout << setprecision(6) << outsideB << " ";
        cout << setprecision(15) << perimeterA << " ";
        cout << setprecision(15) << perimeterB << " ";
        cout << setprecision(14) << error;
        cout << endl;

        OutStream << polygonSides << ", ";
        //OutStream << setprecision(6) << insideA << ", ";
        //OutStream << setprecision(6) << outsideB << ", ";
        OutStream << setprecision(15) << perimeterA << ", ";
        OutStream << setprecision(15) << perimeterB << ", ";
        OutStream << setprecision(14) << error << ", ";
        OutStream << endl;


        if (perimeterB - perimeterA < pow(10.0, -15))
            {
            break;
            }
        }

    // END OF PROGRAM
    OutStream.close();
    cout << "\nThe Dark Knight Rises. ";
    cin >> clorox;
    return 0;
    }