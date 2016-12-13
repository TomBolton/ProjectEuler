/*
 *		  Name: Q21.cpp
 *	Created on: 27 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>
using namespace std;

int calcSumOfDivisors(int);

int main()
{
	// Loop through all integers from 1 to N and
	// calculate the sum of divisors. Take this value
	// for the sum of divisors and then calculate the
	// sum of its own divisors; if this takes you back
	// to the original value then the pair of numbers
	// are called amicable pairs.

	// Initialise
	int a, b, c;
	int sumAmicable = 0;

	// choose how many numbers to loop up to
	int N = 10000;

	// loop up to (but not including) N
	for( int a=1 ; a<N ; a++ )
	{
		// Calculate the sum of divisors of a
		b = calcSumOfDivisors(a);
		// Now calculate the sum of divisors of 'b'
		c = calcSumOfDivisors(b);

		// Check if c = a ( and a!=b )
		if( c==a && a!=b )
		{
			cout<<a<<"  "<<b<<endl;

			// You only need to add the first amicable
			// number in the pair (i.e. n), as the loop
			// will pick up the second later on
			sumAmicable = sumAmicable + a;
		}
	}

	cout<<"Sum of amicable numbers up to "<<N<<" : "<<sumAmicable<<endl;


return 0;
}

int calcSumOfDivisors(int n)
{
	// Write a function that takes an integer n
	// and calculates all the proper divisors
	// and sums then.
	int sum = 1;

	// Loop through all integers up to n and check
	// if it's a divisor. If it is, then add it to
	// the sum.
	for( int i=2 ; i<n ; i++ )
	{
		if( n%i==0 )
		{
			sum = sum + i;
		}
	}

	return sum;
}
