//--------------------------------------------------------------------
//
//  Laboratory 1                                            myString.h
//  **Instructor's Solution**
//  Class declaration for the array implementation of the myString ADT
//
//--------------------------------------------------------------------

#ifndef myString_H
#define myString_H

#include <stdexcept>
#include <iostream>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

class myString
{
  public:

    // Constructors and operator=
    myString ( const char *charSeq = "" );               // Initialize using char*
    myString ( const myString &other );                      // Copy constructor
    void operator = ( const myString &other );           // Assignment

    // Destructor
    ~myString ();

    // myString operations
    int getLength () const;                          // # characters
    char operator [] ( int n ) const;                // Subscript
    void clear ();                                   // Clear string

    // Output the string structure -- used in testing/debugging
    void showStructure () const;

    //--------------------------------------------------------------------
    // In-lab operations
    // toUpper/toLower operations (Programming Exercise 2)
    myString toUpper( ) const;                           // Create upper-case copy
    myString toLower( ) const;                           // Create lower-case copy

    // Relational operations (Programming Exercise 3)
    bool operator == ( const myString& other ) const;
    bool operator <  ( const myString& other ) const;
    bool operator >  ( const myString& other ) const;

  private:

    // Data members
    int bufferSize;   // Size of the string buffer
    char *buffer;     // myString buffer containing a null-terminated sequence of characters

  // Friends

    // myString input/output operations (In-lab Exercise 1)
    friend istream & operator >> ( istream& input, myString& inputmyString );
    friend ostream & operator << ( ostream& output, const myString& outputmyString );

};

#endif
