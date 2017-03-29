//--------------------------------------------------------------------
//
//  Laboratory 1                                          myString.cpp
//
//  SOLUTION: Array implementation of the String ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "myString.h"


//--------------------------------------------------------------------

myString:: myString ( const char *charSeq ) 

// Creates a string containing the delimited sequence of characters
// charSeq. Allocates enough memory for this string.

{
    bufferSize = strlen(charSeq) + 1;   // Account for null

    try
    {
        buffer = new char [ bufferSize ];   // Allocate memory
    }
    catch ( bad_alloc &e )
    {
        cerr << "myString::myString(const char): bad_alloc: buffer == 0\n";
        throw bad_alloc();
    }

    strcpy(buffer,charSeq);             // Copy the string
}

//--------------------------------------------------------------------

myString:: myString ( const myString &valuemyString )

// Copy constructor, creates a copy of valuemyString. Called whenever
//
//   1) a string is passed to a function using call by value,
//   2) a function returns a string, or
//   3) a string is initialized using another string -- as in the
//      declarations:
//                      myString str1("First"),
//                             str2 = str1; 

  : bufferSize(valuemyString.bufferSize)

{
    buffer = new char [bufferSize];    // Allocate memory
    strcpy(buffer,valuemyString.buffer);   // Copy the string
}

//--------------------------------------------------------------------

void myString:: operator = ( const myString& other )

// Assigns other to a myString object.

{
    int rlen = other.getLength();   // Length of other

    if ( rlen >= bufferSize )          // If other will not fit
    {
       delete [] buffer;                    // Release buffer and
       bufferSize = rlen + 1;               //  allocate a new
       buffer = new char [ bufferSize ];    //  (larger) buffer
    }

    strcpy(buffer,other.buffer);   // Copy other
}

//--------------------------------------------------------------------

myString:: ~myString ()

// Frees the memory used by the myString object buffer.

{
    delete [] buffer;
}

//--------------------------------------------------------------------

int myString:: getLength () const

// Returns the number of characters in the myString object buffer (excluding the
// null character).

{
    return strlen(buffer);
}

//--------------------------------------------------------------------

char myString:: operator [] ( int n ) const

// Returns the nth character in a myString object -- where the characters are
// numbered beginning with zero.

{
    if ( n >= 0  &&  n <= getLength() )
       return buffer[n];
    else
       return '\0';
}

//--------------------------------------------------------------------

void myString:: clear ()

// Clears a myString object -- i.e., makes it empty. The buffer size
// remains unchanged.

{
    buffer[0] ='\0';
}

//--------------------------------------------------------------------

void myString:: showStructure () const

// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.

{
    int j;   // Loop counter

    for ( j = 0 ; j < bufferSize ; j++ )
        cout << j << "\t";
    cout << endl;
    for ( j = 0 ; buffer[j] != '\0' ; j++ )
        cout << buffer[j] << "\t";
    cout << "\\0" << endl;
}

//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------

istream & operator >> ( istream &input, myString &inputmyString )

// (In-lab 1)  myString input function. Extracts a string from istream input and
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

// (In-lab 1)  myString output function. Inserts outputmyString in ostream output.
// Returns the state of the output stream.

{
   output << outputmyString.buffer;
   return output;
}


//--------------------------------------------------------------------

myString myString:: toUpper ( ) const

// (In-lab 2)  Returns a myString object containing an upper-case copy of myString object.

{
   int length = strlen(buffer);
   char *tempBuf = new char[length + 1]; //char tempBuf[length + 1];
   strcpy(tempBuf, buffer);
   for ( int i=0; i<length; i++) {
       tempBuf[i] = toupper( tempBuf[i] );
   }

   // Option 1: Correct. Create correctly initialized object, and return object reference by
   // dereferencing new object's address.
   //return myString( tempBuf );

   // Option 2: Also correct. Wordier, but perhaps easier for students to follow.
   myString upper( tempBuf );
   return upper;
}

//--------------------------------------------------------------------

myString myString:: toLower ( ) const

// (In-lab 2)  Returns a myString object containing a lower-case copy of myString object.

{
   int length = strlen(buffer);
   char *tempBuf = new char[length + 1]; //char tempBuf[length + 1];
   strcpy(tempBuf, buffer);
   for ( int i=0; i<length; i++) {
       tempBuf[i] = tolower( tempBuf[i] );
   }

   return myString(tempBuf);
}


//--------------------------------------------------------------------

bool myString::operator == ( const myString &other ) const

// (In-lab 3)  Equality relational operator. Returns true if leftmyString is equal to
// other. Otherwise returns false.

{
    return ( strcmp(buffer,other.buffer) == 0 );
}

//--------------------------------------------------------------------

bool myString::operator < ( const myString &other ) const

// (In-lab 3)  "Less than" relational operator. Returns true if leftmyString is less
// than other. Otherwise returns false.

{
    return ( strcmp(buffer,other.buffer) < 0 );
}

//--------------------------------------------------------------------

bool myString::operator > ( const myString &other ) const

// (In-lab 3)  "Greater than" relational operator. Returns true if leftmyString is
// greater than other. Otherwise returns false.

{
    return ( strcmp(buffer,other.buffer) > 0 );
}

