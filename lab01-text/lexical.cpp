//--------------------------------------------------------------------
//
//  Laboratory 1, In-lab Exercise 1                      lexical.cpp
//
//  SOLUTION: Lexical analysis program
//
//--------------------------------------------------------------------

// Reads tokens from the specified program file outputs each token as
// it is read in. A running count of the number of tokens that have
// been processed is maintained and output.

#include <iostream>
#include <fstream>
#include "Text.h"

using namespace std;

int main ()
{
    Text token;          // Token 8
    int count;           // Counts tokens
    char filename[80];   // Name of the program file

    // Open the specified program file.

    cout << endl << "Enter the name of the program file : ";
    cin >> filename;

    ifstream programFile (filename);

    if ( !programFile )
       cout << "Error opening file " << filename << endl;
    else
    {
       count = 0;
       while ( programFile >> token )
       {
            count++;
            cout << count << " : " << token << endl;
       }
    }

    return 0;
}

