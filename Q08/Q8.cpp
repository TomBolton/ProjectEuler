/*
 *		  Name: Q8.cpp
 *	Created on: 27 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	// declare vector
	vector<int> out;

	// read data from file
	ifstream fs("numbers.txt");
	copy(
	istream_iterator<int>(fs),
	istream_iterator<int>(),
	back_inserter(out));

	long productOf13;
	long maxProduct=0;

	// loop through numbers in vector
	// and calculate the largest product
	for( int i=1 ; i<=1000-13 ; i++)
	{
		productOf13 = 1;

		// calculate product of 13 consecutive
		// digits at this position (i to i+12)

		for( int n=1 ; n<=13 ; n ++)
		{
			productOf13 = productOf13*out[i+n-1];
		}

		cout<<productOf13<<endl;

		// check to see if this product is larger
		// than the current maximum product
		if( productOf13 > maxProduct)
		{
			maxProduct = productOf13;
			cout<<"NEW MAXIMUM!"<<endl;
		}


	}




return 0;
}
