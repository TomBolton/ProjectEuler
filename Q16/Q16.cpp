/*
 *		  Name: Q16.cpp
 *	Created on: 2 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	int nDigits = 310;
	int digits [310] = {};
	digits[nDigits-1] = 1;

	// loop through each power of 2 from 1 to 1000
	for( int n=1 ; n<=1000 ; n++ )
	{
		//cout<<n<<endl;

		// loop through digits and multiply by 2
		for( int i=0 ; i<nDigits ; i++)
		{
			digits[i] = 2*digits[i];

			// check if this digit is > 10
			int index = i;
			while( digits[index]>=10 )
			{
				digits[index] = digits[index]%10;

				digits[index-1] = digits[index-1]+1;

				index--;
			}
		}

	}
	int sum=0;
	for( int i=0 ; i<nDigits ; i++ )
	{
		sum = sum + digits[i];
	}

	cout<<sum<<endl;



return 0;
}
