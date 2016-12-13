/*
 *		  Name: Q34.cpp
 *	Created on: 23 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

int fact(int n);

int main()
{
	// The largest factorial sum that can be obtained is when
	// all digits are 9, so if you have n digits, then the sum
	// is n*9! The corresponding number is 999999... (n digits
	// long) which is approximately 10^n. The value of n at
	// whicn n*9! < 10^n occurs at n=7. We there need to loop
	// through all 7 digit numbers.

	int sum, sumOfSpecial = 0, digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;

	for( int i=10 ; i<100000000 ; i++ )
	{
		digit1 = (i/10000000);
		digit2 = (i/1000000)%10;
		digit3 = (i/100000)%10;
		digit4 = (i/10000)%10;
		digit5 = (i/1000)%10;
		digit6 = (i/100)%10;
		digit7 = (i/10)%10;
		digit8 = i%10;

		sum = fact(digit1) + fact(digit2) + fact(digit3) + fact(digit4) + fact(digit5) + fact(digit6) + fact(digit7) + fact(digit8);

		// Zeros at the beginning do not count as digits so take away
		// 0! = 1 for every zero at the beginning
		if( digit1 == 0) sum--;
		if( digit1 + digit2 == 0 ) sum--;
		if( digit1 + digit2 + digit3 == 0 ) sum--;
		if( digit1 + digit2 + digit3 + digit4 == 0 ) sum--;
		if( digit1 + digit2 + digit3 + digit4 + digit5 == 0 ) sum--;
		if( digit1 + digit2 + digit3 + digit4 + digit5 + digit6 == 0) sum--;
		if( digit1 + digit2 + digit3 + digit4 + digit5 + digit6 + digit7 == 0) sum--;

		if( i == sum )
		{
			cout<<digit1<<digit2<<digit3<<digit4<<digit5<<digit6<<digit7<<digit8<<endl;
			sumOfSpecial += i;
		}

	}

	cout<<"    "<<sumOfSpecial<<endl;

return 0;

}


int fact(int n)
{
	int factorial = 1;
	for( int i=1 ; i<=n ; i++ ) factorial = factorial*i;
	return factorial;
}
