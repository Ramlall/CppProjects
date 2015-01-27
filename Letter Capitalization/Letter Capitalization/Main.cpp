// A simple C++ program to capitalize a letter you input. 
// Makes use of the ASCII character symbols. 

#include <iostream>
using namespace std;

int main(void)
    {
    char ch;

    for(;;) // Forever for loop.
        {
        cout << "Enter lowercase character: ";
        cin >> ch;

        if (ch >= 'a' && ch <= 'z') // Makes sure you entered a legit lowercase character.
            {
            break;
            }
        }

    char upper = ch - 'a' + 'A'; 
    cout << "Upper case of " << ch << " is " << upper << "." << endl;
    return main();
    }