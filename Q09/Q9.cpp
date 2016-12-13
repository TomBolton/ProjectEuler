/*
 *		  Name: Q9.cpp
 *	Created on: 27 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <cmath>
#include <iostream>
using namespace std;

bool pythagTest(int,int);

int main()
{
	// a < b < c, so while looping through a and b,
	// you only need to loop a up to the value of b,
	// as it cannot be great

	for( int b=1 ; b<=1000 ; b++ )
	{
		for( int a=1 ; a<b ; a++ )
		{
			// see if this combo of a and b form a triplet
			// and then see if a+b+c = 1000
			if( pythagTest(a,b) == true )
			{
				if( a + b + sqrt(a*a+b*b) == 1000)
				{
					cout<<"Found it! "<<"a*b*c = "<<a*b*sqrt(a*a+b*b)<<endl;
				}
			}
		}
	}

return 0;
}


bool pythagTest(int a, int b)
{
	double c = sqrt(a*a + b*b);
	if( c - floor(c) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
