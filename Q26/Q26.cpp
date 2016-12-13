/*
 *		  Name: Q26.cpp
 *	Created on: 31 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

int detectCycle(int);

int main()
{
	int maxCycle=0, cycle, dMax;

	// Loop through all integers up to 1000 and
	// find the maximum recurring cycle of 1/d

	for( int d=2 ; d<=1000; d++)
	{
		cycle = detectCycle(d);

		cout<<cycle<<endl;

		if( cycle > maxCycle)
		{
			dMax = d;
			maxCycle = cycle;
			cout<<"^ New max cycle! For d = "<<d<<"."<<endl;
		}
	}

    cout<<"Max cycle = "<<maxCycle<<" at d = "<<dMax<<endl;



return 0;

}

int detectCycle(int n)
{
	// Long division algorithm for calculating
	// the first hundred digits of 1/n
	int digit = 0, numToDivide = 1, N = 1000;

	// Make array to store the N digits
	int digitArray[N];

	// Make an array of remainder values to check
	// if one has appeared previously. This will
	// allow us to spot if there's a cycle
	int rem[N];

	// Reset values of both arrays to zero
	for( int i=0 ; i<N ; i++ )
	{
		digitArray[i] = 0;
		rem[i] = 0;
	}

	while( digit<N )
	{
		while( numToDivide/n == 0 && digit<N )
		{
			digitArray[digit] = 0;
			numToDivide = numToDivide*10;
			digit++;
		}

		// Calculate this digit value
		digitArray[digit] = numToDivide/n;

		// Calculate remainder
		rem[digit] = (numToDivide - n*(numToDivide/n));

		if( n==8 ) cout<<numToDivide<<" "<<digit<<" "<<rem[digit]<<endl;

		numToDivide = rem[digit]*10;    // The *10 drops down the zero

		digit++;
	}

	// Now loop through each remainder value and see if it
	// appears again. If it does, then the gap between them is the
	// length of the cycle.
	bool foundCycle = false;
	int m=0, cycleLength=0, j = 1;

	if( digitArray[0] == 0 && digitArray[1] != 0 && digitArray[2] != 0) m=1, j=2;
	if( digitArray[0] == 0 && digitArray[1] == 0 && digitArray[2] != 0) m=2, j=3;
	if( digitArray[0] == 0 && digitArray[1] == 0 && digitArray[2] == 0) m=3, j=4;


	while( !foundCycle && m<N )
	{
		while( rem[j] != rem[m] && j<N )
		{
			j++;
		}

		if( j!=N  )
		{
			foundCycle = true;
			cycleLength = j-m;
		}

		m++;
	}

	return cycleLength;
}

