//--------------------------------------------------------------------
//
//  Laboratory 1, In-lab Exercise 1                        textio.cpp
//
//  String input/output operations
//
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>

//--------------------------------------------------------------------

istream & operator >> ( istream &input, myString &inputmyString )

// myString input function. Extracts a string from istream input and
// returns it in inputmyString. Returns the state of the input stream.

{
    const int textBufferSize = 256;     // Large (but finite)
    char textBuffer [textBufferSize];   // text buffer

    // Read a string into textBuffer, setw is used to prevent buffer
    // overflow.

    input >> setw(textBufferSize) >> textBuffer;

    // Apply the myString(char*) constructor to convert textBuffer to
    // a string. Assign the resulting string to inputmyString using the
    // assignment operator.

    inputmyString = textBuffer;

    // Return the state of the input stream.

    return input;
}

//--------------------------------------------------------------------

ostream & operator << ( ostream &output, const myString &outputmyString )

// myString output function. Inserts outputmyString in ostream output.
// Returns the state of the output stream.

{
   output << outputmyString.buffer;
   return output;
}

