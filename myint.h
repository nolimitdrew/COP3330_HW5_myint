
/* Name: Andrew Stade
Date: 11/8/2019
Section: 2 */

#include <iostream>
#include <iomanip>

using namespace std;

class MyInt
{
   // these overload starters are declared as friend functions

   friend MyInt operator+ (const MyInt& x, const MyInt& y);
   friend MyInt operator* (const MyInt& x, const MyInt& y);
   // add in multiplication, as well

   friend bool operator< (const MyInt& x, const MyInt& y);
   friend bool operator> (const MyInt& x, const MyInt& y);
   friend bool operator<= (const MyInt& x, const MyInt& y);
   friend bool operator>= (const MyInt& x, const MyInt& y);
   friend bool operator== (const MyInt& x, const MyInt& y);
   friend bool operator!= (const MyInt& x, const MyInt& y);
   // add in the other comparison overloads, as well
    
   friend istream& operator >> (istream& a, MyInt& b);
   friend ostream& operator << (ostream& a, const MyInt& b);
   // declare overloads for input and output (MUST be non-member functions)
   //  you may make them friends of the class

public:
   MyInt(int n = 0);		        // first constructor
   ~MyInt();                        // destructor
   
   MyInt(const MyInt& q);           // copy constructor
   MyInt(const char* m);            // string constructor
   MyInt& operator= (const MyInt &); // assignment operator
   
   
   void Add(int b);
   
   int C2I(char a);
   char I2C (int z);

   MyInt& operator++();                 // pre/post increment
   MyInt operator++(int);
   MyInt& operator--();
   MyInt operator--(int);


   // be sure to add in the second constructor, and the user-defined 
   //  versions of destructor, copy constructor, and assignment operator

private:
    int maxSize;
    int currentSize;
    int * intArr;
    void Grow();
   // member data (suggested: use a dynamic array to store the digits)

};
