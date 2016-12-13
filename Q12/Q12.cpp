/*
 *		  Name: Q12.cpp
 *	Created on: 30 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

int calcDivisors(long);

int main()
{

	long N = 1;
	int divisors = 1;

	// loop through triangle numbers while the
	// number of divisors is less than 500
	while( divisors < 500 )
	{
		N++;

		divisors = calcDivisors(N*(N+1)/2);

		if( divisors > 200)
		{
			cout<<divisors<<" (N(N+1)/2= "<<N*(N+1)/2<<" "<<endl;
		}


	}

	cout<<N*(N+1)/2<<" with this many divisors: "<<divisors<<endl;

return 0;
}

int calcDivisors(long n)
{
	int nDivisors = 1;

	for( int i=1 ; i<=sqrt(n) ; i++)
	{
		if( n%i == 0 )
		{
			nDivisors+=2;
		}
	}

	return nDivisors;
}


