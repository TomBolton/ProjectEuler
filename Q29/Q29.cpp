/*
 *		  Name: Q29.cpp
 *	Created on: 20 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

bool arrayEqual( int[], int, int[], int);
void calcPrimePowers( int[], int, int, int);

int main()
{
	// Initialise number of pairs that are unique
	int nUnique = 99*99;

	// Initialise an array for the powers of primes
	int primePowers1[25], primePowers2[25];

	// We need to make sure we're not over counting,
	// so make an array for every combo of a and b
	// which will be 'FALSE' if a^b has not been counted
	// before, and will be 'TRUE' if it has been
	// previously counted. Initialise as f
	bool *beenCounted = new bool[99*99];

	// Set all elements of vector to false
	for( int n=0 ; n<99*99 ; n++ ) beenCounted[n] = false;


	// All combinations of a and b have to be looped
	// through TWICE. This is because you need to calculate
	// the prime powers for a certain a and b, and then
	// compare them with all the over combinations of a and b.
	for( int a1=2 ; a1<=100 ; a1++ )
	{
		for( int b1=2 ; b1<=100 ; b1++)
		{
			// Reset values from previous combination of a1 and b1
			for( int i=0 ; i<25 ; i++ )
			{
				primePowers1[i] = 0;
			}

			// Calculate the prime powers for this a1-b1 pair
			calcPrimePowers(primePowers1,25,a1,b1);

			// Loop through all other a-b pairs and check
			// if they're the same
			for( int a2=a1 ; a2<=100 ; a2++ )
			{
				for( int b2=2 ; b2<=b1 ; b2++ )
				{
					// Reset values from previous combination of a2 and b2
					for( int j=0 ; j<25 ; j++ )
					{
						primePowers2[j] = 0;
					}

					// Calculate the prime powers for this a2-b2 pair
					calcPrimePowers(primePowers2,25,a2,b2);

					// Check if primePowers1 and primePowers2 are equal
					// (and that a1 != a2, b1 != b2)
					if( arrayEqual(primePowers1,25,primePowers2,25) && !beenCounted[(a2-2)*99+b2-2] && a1 != a2 && b1 != b2 )
					{
						beenCounted[(a2-2)*99+b2-2] = true;
						beenCounted[(a1-2)*99+b1-2] = true;
						nUnique --;
						cout<<"    "<<a1<<"^"<<b1<<"  =  "<<a2<<"^"<<b2<<"."<<endl;
					}
				}
			}
		}
	}

	cout<<"Number of unique numbers: "<<nUnique<<endl;

	delete [] beenCounted;

return 0;

}

bool arrayEqual( int* primePowers1, int length1, int* primePowers2, int length2 )
{
	for( int i=0 ; i<length1 ; i++ )
	{
		if( primePowers1[i] != primePowers2[i] )
		{
			return false;
		}
	}

	return true;
}

void calcPrimePowers( int* primePowers, int length, int base, int power)
{
	// When a number is written as a product of it's
	// prime factors, then the important part is the
	// power each of the prime factors are raised to.
	// There are 25 prime numbers between 1 and 100,
	// so use an array to store the power for each of
	// these 25 primes.
	int rem;

	int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

	// Loop through all the above primes and see if its a factor
	for( int j=0 ; j<25 ; j++ )
	{
		rem = base;

		while( rem%primes[j] == 0 )
		{
			primePowers[j]++;		// Add one to the power for this prime
			rem = rem/primes[j];	// Divide by prime to get leftover
		}
	}

	// The power will simply multiply the power values of each prime
	for( int i=0 ; i<25 ; i++ )
	{
		primePowers[i] = primePowers[i]*power;
	}

}
