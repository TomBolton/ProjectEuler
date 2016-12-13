/*
 *		  Name: Q15.cpp
 *	Created on: 2 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
using namespace std;
int main()
{
	// The number of combinations of going from top-right to
	// bottom-left of a NxN grid is given by N choose N/2, so
	// for a 20x20 grid, the answer is 40!/20!

	double combinations1 = 1;

	for( int i=21 ; i<=40 ; i++ )
	{
		combinations1 = combinations1*i;
	}

	double combinations2 = 1;

	for( int i=1 ; i<=20 ; i++ )
		{
			combinations2 = combinations2*i;
		}

	cout<<fixed<<combinations1/combinations2<<endl;

return 0;
}
