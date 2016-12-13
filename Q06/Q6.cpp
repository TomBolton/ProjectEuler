/*
 *		  Name: Q6.cpp
 *	Created on: 27 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int N = 100;
	int sumOfSquares = 0;
	int sum = 0;

	for( int i=1 ; i<101 ; i++)
	{
		sumOfSquares = sumOfSquares + i*i;
		sum  = sum + i;
	}

	cout<< sum*sum - sumOfSquares <<endl;
return 0;
}
