/*
 *		  Name: Q33.cpp
 *	Created on: 23 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

bool isWierd(int, int);

int main()
{
	int aProduct = 1, bProduct = 1;

	// Loop through all numerators
	for( int a=10 ; a<100 ; a++ )
	{
		// Loop through all denominators
		for( int b=a+1 ; b<100 ; b++ )
		{
			if( isWierd(a,b) )
			{
				cout<<a<<" "<<b<<endl;
				aProduct = aProduct*a;
				bProduct = bProduct*b;
			}
		}
	}

	cout<<aProduct<<" "<<bProduct<<endl;

	int i=aProduct;

	// Find lowest common terms
	while( i>1 )
	{
		if( aProduct%i == 0 && bProduct%i == 0 )
		{
			aProduct = aProduct/i;
			bProduct = bProduct/i;
		}

		i--;
	}

	cout<<aProduct<<" "<<bProduct<<endl;

return 0;

}

bool isWierd(int n, int d)
{
	int digit1a = n/10, digit1b = n%10;
	int digit2a = d/10, digit2b = d%10;

	double r1, r2;


	if( digit1a == digit2b )
	{
		r1 = static_cast<double>(n)/static_cast<double>(d);
		r2 = static_cast<double>(digit1b)/static_cast<double>(digit2a);

		if( r1==r2 ) return true;
	}

	if (digit1b == digit2a )
	{
		r1 = static_cast<double>(n)/static_cast<double>(d);
		r2 = static_cast<double>(digit1a)/static_cast<double>(digit2b);

		if( r1==r2 ) return true;
	}

	return false;
}
