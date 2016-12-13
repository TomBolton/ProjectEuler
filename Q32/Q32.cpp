/*
 *		  Name: Q32.cpp
 *	Created on: 23 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPandigital(int[], int);
bool isCValueNew(vector<int>&, int, int);

int main()
{
	// To find all the combinations of a x b = c that are 1 through 9
	// pandigital, the total number of digits is obviously 9. The
	// lowest combo that produces 9 digits is 10 x 100 = 1000. The
	// combo 99 x 999 produces a five digit number on the right, so
	// a rough upper limit on a and b is 99 and 999.

	// Make an array 9 elements long that will store all the digits
	// present in the numbers a, b and c.
	int digits[9], c, sum = 0;

	// We need to keep track of which c values have already been
	// counted, so make an vector to store c values
	vector<int> cValues;

	// First consider cases where a is two digits, b is three digits and c is four digits

	// Loop through all a values
	for( int a=10 ; a<99 ; a++ )
	{
		// Loop through all b values
		for( int b=100 ; b<999 ; b++ )
		{
			if( (a*b)/10000 == 0 )
			{

				// Reset values of digits from previous iteration
				for( int i=0 ; i<9 ; i++ ) digits[i] = 0;

				c = a*b;

				if( isCValueNew(cValues,cValues.size(),c) )		// Check that c hasnt been counted before
				{
					// Calculate digits
					digits[0] = a/10;
					digits[1] = a%10;
					digits[2] = b/100;
					digits[3] = (b - digits[2]*100)/10;
					digits[4] = b%10;
					digits[5] = c/1000;
					digits[6] = (c - digits[5]*1000)/100;
					digits[7] = (c - digits[5]*1000 - digits[6]*100)/10;
					digits[8] = c%10;

					if( isPandigital(digits,9) )
					{
						sum += c;
						cValues.push_back(c);
						cout<<a<<" "<<b<<" "<<c<<endl;
					}
				}
			}
		}
	}

	// Now consider the case where a is one digit, b is four digits and c is four digits

	for( int a=1 ; a<10 ; a++ )
	{
		for( int b=1000 ; b<9999 ; b++ )
		{
			// Reset values of digits from previous iteration
			for( int i=0 ; i<9 ; i++ ) digits[i] = 0;

			c = a*b;

			if( isCValueNew(cValues,cValues.size(),c) )		// Check that c hasnt been counted before
			{
				// Calculate digits
				digits[0] = a;
				digits[1] = b/1000;
				digits[2] = (b - digits[1]*1000)/100;
				digits[3] = (b - digits[1]*1000 - digits[2]*100)/10;
				digits[4] = b%10;
				digits[5] = c/1000;
				digits[6] = (c - digits[5]*1000)/100;
				digits[7] = (c - digits[5]*1000 - digits[6]*100)/10;
				digits[8] = c%10;

				if( isPandigital(digits,9) )
				{
					sum += c;
					cValues.push_back(c);
					cout<<a<<" "<<b<<" "<<c<<endl;
				}
			}
		}
	}

	cout<<sum;

return 0;

}

bool isPandigital( int* digits, int size )
{
	// Count how many times each digit appears
	int n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;

	for( int i=0 ; i<9  ; i++ )
	{
		if( digits[i] == 1 ) n1++;
		if( digits[i] == 2 ) n2++;
		if( digits[i] == 3 ) n3++;
		if( digits[i] == 4 ) n4++;
		if( digits[i] == 5 ) n5++;
		if( digits[i] == 6 ) n6++;
		if( digits[i] == 7 ) n7++;
		if( digits[i] == 8 ) n8++;
		if( digits[i] == 9 ) n9++;
	}

	if( n1==1 && n2==1 && n3==1 && n4==1 && n5==1 && n6==1 && n7==1 && n8==1 && n9==1 ) return true;

	return false;
}

bool isCValueNew(vector<int>& CValues, int size, int c)
{
	for( int n=0 ; n<size ; n++ )
	{
		if( CValues[n] == c ) return false;
	}

	return true;
}
