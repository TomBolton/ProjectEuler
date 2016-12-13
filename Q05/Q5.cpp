/*
 *		  Name: Q5.cpp
 *	Created on: 27 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
using namespace std;

bool divisibleTest(int);

int main()
{
	// declare variables
   int i = 22;
   cout<<divisibleTest(i)<<endl;
   // test numbers and stop when the number is found
   while( divisibleTest(i) == false )
   {
	   i++;
   }

   cout<<i<<endl;


return 0;
}

bool divisibleTest(int n)
{
	if ( n%20 != 0 ) return false;
	if ( n%19 != 0 ) return false;
    if ( n%18 != 0 ) return false;
	if ( n%17 != 0 ) return false;
    if ( n%16 != 0 ) return false;
    if ( n%15 != 0 ) return false;
    if ( n%14 != 0 ) return false;
    if ( n%13 != 0 ) return false;
    if ( n%12 != 0 ) return false;
    if ( n%11 != 0 ) return false;

    return true;

}
