/*
 *		  Name: Q25.cpp
 *	Created on: 31 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{

	// Make a 1000 digit array to store
	// the Fibonacci digits
	unsigned long long fibDigitsA[1200], fibDigitsB[1200], fibDigitsC[1200];

	// Set first two values F1 = 1, F2 = 1
	fibDigitsA[0] = 1;
	fibDigitsB[0] = 1;

	// The 'digit' variable counts the number of digits the current Fibonacci number has
	// and the 'carry' variable is the amount to carry over to the next digit. 'termNum'
	// keeps track of what term in the sequence we are at.
	unsigned long long digit=1, carry=0, termNum=3, value;

	while( digit<1000)
	{
		if( digit>800 && digit<820 )
				{
					cout<<carry<<" "<<digit<<" "<<value<<" "<<fibDigitsA[digit-1]<<" "<<fibDigitsB[digit-1]<<" "<<fibDigitsC[digit-1]<<endl;
				}

		// Store digits from left to right
		for( int i=0 ; i<digit ; i++)
		{
			value = fibDigitsA[i] + fibDigitsB[i] + carry;   // Calc the sum of the previous two digits
			carry  = value/10; 							     // Calc the carry over value for the next digit
			fibDigitsC[i] = value%10;                        // The digit value is the remainder when divided by 10

		}
		if( digit>800 && digit<820 )
		{
			cout<<carry<<" "<<digit<<" "<<value<<" "<<fibDigitsA[digit-1]<<" "<<fibDigitsB[digit-1]<<" "<<fibDigitsC[digit-1]<<endl;
		}

		// If the carry value is non-zero at this stage,
		// then you need to add it to next digit along
		while( carry!=0 )
		{

			fibDigitsC[digit] = carry%10;
			carry = carry/10;

			digit++;
		}
		if( digit>800 && digit<820 )
				{
					cout<<carry<<" "<<digit<<" "<<value<<" "<<fibDigitsA[digit-1]<<" "<<fibDigitsB[digit-1]<<" "<<fibDigitsC[digit-1]<<endl;
				}

		// Now make F_n = F_n-1, and F_n-1 = F_n-2
		for( int i=0 ; i<1200 ; i++ )
		{
			fibDigitsA[i] = fibDigitsB[i];
			fibDigitsB[i] = fibDigitsC[i];
		}


		if( digit>800 && digit<820 )
				{
					cout<<carry<<" "<<digit<<" "<<value<<" "<<fibDigitsA[digit-1]<<" "<<fibDigitsB[digit-1]<<" "<<fibDigitsC[digit-1]<<endl;
				}

		termNum++;

	}

	cout<<termNum<<endl;

return 0;

}
