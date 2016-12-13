/*
 *		  Name: Q7.cpp
 *	Created on: 27 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
using namespace std;

bool primeTest(int n);

int main()
{
	int totalPrimes = 0;
	int N = 2;

	while( totalPrimes != 10001 )
	{
		if( primeTest(N) == true )
		{
			totalPrimes++;
			cout<<"Prime: "<<N<<" Total so far: "<<totalPrimes<<endl;
		}

		N++;
	}

return 0;
}

bool primeTest(int n)
{
	if( n==1 ) return false;
	if( n==2 ) return true;
	if( n%2 == 0 ) return false;

	for( int i=3 ; i<n ; i++ )
	{
		if( n%i == 0 ) return false;
	}

	return true;
}
