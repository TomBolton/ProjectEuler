/*
 *		  Name: Q23.cpp
 *	Created on: 27 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

bool isAbundant(int);
bool isNotSumOfAbundant(int,int[],int);

using namespace std;

int main()
{
	// Loop through all integers from 1 to 28123 to
	// find and count all abundant integers.
	int total = 0;

	for( int i=0 ; i<28123 ; i++)
	{
		if( isAbundant(i+1) ) total = total + 1;
	}

	// Use the total number of abundant numbers
	// to initialise an array and store the numbers
	int abundantNumbers[total];
	int count = 0;

	for( int j=0 ; j<28123 ; j++)
	{
		if( isAbundant(j+1) )
		{
			abundantNumbers[count] = j+1;
			count++;
		}
	}

	// Now sum all integers between 1 and 28123 that are NOT
	// the sum of two abundant numbers
	int sum = 0;

	for( int k=1 ; k<28123 ; k++ )
	{
		if( isNotSumOfAbundant(k,abundantNumbers,total) ) sum = sum + k, cout<<k<<endl;
	}

	cout<<sum<<endl;

return 0;
}

bool isAbundant(int n)
{
	int sum = 0;

	// Sum all divisors between 1 and n
	for( int i=1 ; i<n ; i++ )
	{
		if( n%i == 0 ) sum = sum + i;
	}

	// Abundant if sum of divisors is greater than n
	if( sum > n ) return true;

	return false;

}

bool isNotSumOfAbundant(int n, int abundantNumbers[], int size)
{
	// Find position of abundant number that is closest in value
	// to n. Then adjust the for loops below to only search for
	// through abundant numbers less than n.
	int max=0;

	while( abundantNumbers[max] < n ) max++;

	// Loop through all combinations of pairs of abundant
	// numbers and check if their sum equals n
	for( int k=0 ; k<max ; k++)
	{
		for( int l=0 ; l<max ; l++)
		{
			if( abundantNumbers[k] + abundantNumbers[l] == n) return false;
		}
	}

	return true;
}
