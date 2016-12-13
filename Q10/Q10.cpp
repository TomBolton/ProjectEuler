/*
 *  Author: Thomas Bolton
 *  Filename: Q10.cpp
 *  Created on: 27th Sep 2016
 */
#include <iostream>
using namespace std;

bool primeTest(int n);

int main()
{
	long sumOfPrimes = 2;

	for( int i=3 ; i<2000000 ; i+=2)
	{
		// check if prime
		if(primeTest(i))
		{
			sumOfPrimes = sumOfPrimes + i;
			//cout<<sumOfPrimes<<endl;
		}
	}

	cout<<"Finished! Total: "<<sumOfPrimes<<endl;

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
