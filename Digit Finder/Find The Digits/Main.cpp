// Find the [first five] digits in a number being entered, and then find the sum of those numbers.
#include <iostream>
using namespace std;

int main(void)
    {
    int number;
    int digitone;
    int digittwo;
    int digitthree;
    int digitfour;
    int digitfive;
    int sum;

    cout << "Please enter a five digit number. ";
    cin >> number;

    digitfive = number % 10;
    digitfour = (number % 100)/10;
    digitthree = (number % 1000)/100;
    digittwo = (number % 10000)/1000;
    digitone = (number % 100000)/10000;
    sum = digitone + digittwo + digitthree + digitfour + digitfive;

    cout << "\nYou entered: " << number << endl;

    cout << "\nThe first digit is: " << digitone << endl;

    cout << "The second digit is: " << digittwo << endl;

    cout << "The third digit is: " << digitthree << endl;

    cout << "The fourth digit is: " << digitfour << endl;

    cout << "The fifth digit is: " << digitfive << endl;

    cout << "\nThe sum of these five digits is: " << sum << "\n\n" << endl;

    return main();
    }