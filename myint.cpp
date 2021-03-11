
/* Name: Andrew Stade
Date: 11/8/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "myint.h"

using namespace std;


// --- Operator Overloads ---

MyInt operator+ (const MyInt& x, const MyInt& y) // (Kinda works)
{
    int carry = 0;
    int sum = 0;
    int counter = 0;
    int j = 0;
    
    MyInt result;
    
    if (x.currentSize == y.currentSize)
    {
        for (int i = 0 ; i < x.currentSize; i++)
        {      
            if (i < y.currentSize)
            {
                sum = x.intArr[i] + y.intArr[i]; //+ carry;
                carry = sum / 10;
                result.Add(sum);
            }
            else 
            {
                sum = x.intArr[i] + carry;
                carry = sum / 10;
                result.Add(sum);
            }
        }
    }
    else if (x.currentSize < y.currentSize)
    {
        counter = y.currentSize - x.currentSize;
        
        for (int i = 0; i < y.maxSize; i++)
        {      
            if (i < y.currentSize)
            {
                sum = x.intArr[i-counter] + y.intArr[i]; //+ carry;
                carry = sum / 10;
                if (carry == 1)
                {
                    y.intArr[i] = y.intArr[i+j];
                    result.Add(sum);
                }
                else 
                {
                    result.Add(sum);
                }
            }
        }
    }        
    else if (x.currentSize > y.currentSize)
    {
        counter = x.currentSize - y.currentSize;
        
        for (int i = 0; i < x.maxSize; i++)
        {      
            if (i < x.currentSize)
            {
                sum = y.intArr[i-counter] + x.intArr[i]; //+ carry;
                carry = sum / 10;
                if (carry == 1)
                {
                    x.intArr[i] = x.intArr[i+j];
                    result.Add(sum);
                }
                else 
                {
                    result.Add(sum);
                }
            }
        }
    }
    return result;

}

MyInt operator* (const MyInt& x, const MyInt& y) // (Doesn't  work)
{
    int carry = 0;
    int sum = 0;
    int counter = 0;
    int j = 0;
    
    MyInt result;
    
    if (x.currentSize == y.currentSize)
    {
        for (int i = 0 ; i < x.currentSize; i++)
        {      
            if (i < y.currentSize)
            {
                sum = x.intArr[i] * y.intArr[i] + carry;
                carry = sum / 10;
                result.Add(sum);
            }
            else 
            {
                sum = x.intArr[i] + carry;
                carry = sum / 10;
                result.Add(sum);
            }
        }
    }
    else if (x.currentSize < y.currentSize)
    {
        counter = y.currentSize - x.currentSize;
        
        for (int i = 0; i < y.maxSize; i++)
        {      
            if (i < y.currentSize)
            {
                sum = x.intArr[i-counter] * y.intArr[i] + carry;
                carry = sum / 10;
                if (carry == 1)
                {
                    y.intArr[i] = y.intArr[i+j];
                    result.Add(sum);
                }
                else 
                {
                    result.Add(sum);
                }
            }
        }
    }        
    else if (x.currentSize > y.currentSize)
    {
        counter = x.currentSize - y.currentSize;
        
        for (int i = 0; i < x.maxSize; i++)
        {      
            if (i < x.currentSize)
            {
                sum = y.intArr[i-counter] * x.intArr[i] + carry;
                carry = sum / 10;
                if (carry == 1)
                {
                    x.intArr[i] = x.intArr[i+j];
                    result.Add(sum);
                }
                else 
                {
                    result.Add(sum);
                }
            }
        }
    }
    return result;
}

bool operator< (const MyInt& x, const MyInt& y) // (Complete)
{
    if (x.currentSize == y.currentSize)
    {
        for (int i = 0; i < y.currentSize; i++)
        {        
            if (x.intArr[i] < y.intArr[i])
            {
                return true;
            }
        }
        return false;
    }
    else if (x.currentSize < y.currentSize)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool operator> (const MyInt& x, const MyInt& y) // (Complete)
{
    return (y < x);
}

bool operator<= (const MyInt& x, const MyInt& y) // (Complete)
{
    return (!(x > y));
}

bool operator>= (const MyInt& x, const MyInt& y) // (Complete)
{
    return (!(x < y));
}

bool operator== (const MyInt& x, const MyInt& y) // (Complete)
{
    for (int i = 0; i < y.currentSize; i++)
    {
        if (x.intArr[i] != y.intArr[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!= (const MyInt& x, const MyInt& y) // (Complete)
{
    for (int i = 0; i < y.currentSize; i++)
    {
        if (x.intArr[i] != y.intArr[i])
        {
            return true;
        }
    }
    return false;
}


istream& operator>> (istream& s, MyInt& e) // (Doesn't work)
{
   /*char a;
   int i = 0;
   
   delete [] e.intArr;
   e.currentSize = 0;
   e.maxSize = e.currentSize + 5;
   e.intArr = new int[e.maxSize];
   
   do
   {
       for (int j = 0; j > e.maxSize; j++)
       {
            a = s.getline(e.intArr, e.maxSize);
       }
       if (e.C2I(a))
       {
            e.intArr[e.currentSize+1] == e.C2I(a);
           if (e.currentSize == e.maxSize)
           {
               e.Grow();
           }
       }
       else 
       {
       }
   } while (e.C2I(a));
    return s; */
}

ostream& operator<< (ostream& s, const MyInt& e) // (Complete)
// Output of the array
{
    if (e.currentSize == 0)
    {
        s << 0;
    }
    else
    {
        for (int i = 0 ; i < e.currentSize; i++)
        {
            s << e.intArr[i];
        }
    }
    return s;
}


// --- Member Functions --- 

MyInt::MyInt(int n) // (Complete)
// Int constructor
{   
    int sizeN = 0;
    int temp = n;

    if (n > 0)
    {
        maxSize = 5;
        intArr = new int[maxSize]; 
        currentSize = 0;
        
        do
        {
            temp = temp / 10;
            sizeN++;
        } while (temp / 10 != 0);
        sizeN++;
    
        for (sizeN; sizeN > 0 ; sizeN--)
        {
            intArr[sizeN-1] = n % 10;
            n = n / 10;
            currentSize++;
            if (currentSize == maxSize)
            {
                Grow();
            }
        }
    }
    else
    {
        currentSize = 0;
        intArr = new int[currentSize];        
    }  
}

MyInt::~MyInt() // (Complete)
// Destructor
{
    delete [] intArr;
}

MyInt::MyInt(const char* m) // (Complete)
// String Constructor
{
    int temp = strlen(m);
    
    maxSize = 5;
    currentSize = strlen(m);
    intArr = new int[currentSize];
    
    for (int i = 0; i < temp; i++)
    {
        if (isdigit(m[i]))
        {
            intArr[i] = C2I(m[i]);
            if (currentSize == maxSize)
            {
                Grow();
            }
        }
        else
        {
            currentSize = 0;
            intArr = new int[currentSize];
        }
    }
}

MyInt& MyInt::operator= (const MyInt & o) // (Complete)
// Assignment Operator
{
    if (this != &o)
    {
        delete [] intArr;
        maxSize = o.maxSize;
        currentSize = o.currentSize;
        intArr = new int[o.currentSize];
        for (int i = 0; i < currentSize; i++)
        {
            intArr[i] = o.intArr[i];
        }
    return *this;
    }
}

void MyInt::Add(int b) // (Complete)
// Used in the add operator (operator+)
{
    currentSize++;
    if (currentSize == maxSize)
    {
        Grow();
    }
    intArr[currentSize-1] = b;
    
}

void MyInt::Grow() // (Complete)
// Increases the array if needed by 1.
{
    maxSize = currentSize + 1;
    int* newList = new int[maxSize];
    
    for (int i = 0; i < currentSize; i++)
    {
        newList[i] = intArr[i];
    }
    
    delete [] intArr;
    intArr = newList;
}

int MyInt::C2I(char c) // Premise
// converts character into integer (returns -1 for error)
{
   if (c < '0' || c > '9')	return -1;	// error
   return (c - '0');				// success
}

char MyInt::I2C(int x) // Premise
// converts single digit integer into character (returns '\0' for error)
{
   if (x < 0 || x > 9)		return '\0';	// error
   return (static_cast<char>(x) + '0'); 	// success
}

// Add in operator overload and member function definitions 

MyInt::MyInt(const MyInt& q) // (Complete)
// Copy Constructor
{
    currentSize = q.currentSize;
    maxSize = q.maxSize;
    intArr = new int[maxSize];
    
    for (int i = 0; i < currentSize; i++)
    {
        intArr[i] = q.intArr[i];
    }
}

MyInt& MyInt::operator++() // (Complete)
{
    for (int i = 0; i < currentSize; i++)
    {
        intArr[i] = intArr[i+1];
    }
    return *this;
}

MyInt MyInt::operator++(int) // (Complete)
{
    MyInt temp = *this;
    for (int i = 0; i < currentSize; i++)
    {
        intArr[i] = intArr[i+1];
    }
    return temp;
}

MyInt& MyInt::operator--() // (Complete)
{
    for (int i = 0; i < currentSize; i++)
    {
        intArr[i] = intArr[i-1];
    }
    return *this;
}

MyInt MyInt::operator--(int) // (Complete)
{
    MyInt temp = *this;
    for (int i = 0; i < currentSize; i++)
    {
        intArr[i] = intArr[i-1];
    }
    return temp;
}