/*
 *		  Name: Q27.cpp
 *	Created on: 17 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(double);

int main()
{
	// Initialise coefficients
	int n, maxPrimes = 0;

	// Loop through all combinations of 'a' and 'b'
	for( int a=-999 ; a<1000 ; a++ )
	{
		for( int b=-1000 ; b<=1000 ; b++ )
		{
			// Loop through values of n until the equation n^2 + an + b no
			// longer produces prime numbers
			n = 0;

			while(isPrime(abs(n*n + a*n + b)))
			{
				n++;
			}


			// 'n' is now the number of consecutive primes produced
			// so see if this is larger than the current maximum
			if( n>maxPrimes)
			{
				cout<<"n = "<<n<<", a = "<<a<<", b = "<<b<<", a*b = "<<a*b<<endl;
				maxPrimes = n;
			}

		}


	}



return 0;

}


bool isPrime(double m)
{
	int n = static_cast<int>(m);

	if( n==1 ) return true;
	if( n==2 ) return true;
	if( n%2==0 ) return false;

	for( int i=3 ; i<=(n+1)/2 ; i++ )
	{
		if( n%i==0 ) return false;
	}

	return true;
}
