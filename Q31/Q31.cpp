/*
 *		  Name: Q31.cpp
 *	Created on: 22 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Define the values of each coin (in pennies)
	int coin1 = 1, coin2 = 2, coin3 = 5, coin4 = 10;
	int coin5 = 20, coin6 = 50, coin7 = 100, coin8 = 200;

	// Choose what sum you want to make (in pennies)
	int targetSum = 200;

	// Define the number of each coin used in the combination
	int n1, n2, n3, n4, n5, n6, n7, n8;

	// Define the maximum number of each coin that can be used,
	// for example, a max of 10xcoin5 can be used to make 200p
	int max1 = floor(targetSum/coin1);
	int max2 = floor(targetSum/coin2);
	int max3 = floor(targetSum/coin3);
	int max4 = floor(targetSum/coin4);
	int max5 = floor(targetSum/coin5);
	int max6 = floor(targetSum/coin6);
	int max7 = floor(targetSum/coin7);
	int max8 = floor(targetSum/coin8);

	// Loop through all combinations of the above eight coins
	// on each iteration, check if the sum of the coins makes
	// the target value. Count the number of combinations
	// that do add up to the target value.
	int nCombos = 0, value;

	for( int i1=0 ; i1<=max1 ; i1++ )
	{
		for( int i2=0 ; i2<=max2 ; i2++ )
		{
			for( int i3=0 ; i3<=max3 ; i3++ )
			{
				for( int i4=0 ; i4<=max4 ; i4++ )
				{
					for( int i5=0 ; i5<=max5 ; i5++ )
					{
						for( int i6=0 ; i6<=max6 ; i6++ )
						{
							for( int i7=0 ; i7<=max7 ; i7++ )
							{
								for( int i8=0 ; i8<=max8 ; i8++ )
								{
									value = i1*coin1 + i2*coin2 + i3*coin3 + i4*coin4 + i5*coin5 + i6*coin6 + i7*coin7 + i8*coin8;

									if( value == targetSum )
									{
										nCombos++;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout<<nCombos<<endl;

return 0;

}
