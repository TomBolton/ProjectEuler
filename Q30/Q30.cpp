/*
 *		  Name: Q30.cpp
 *	Created on: 22 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

int calcFifthPowerSum(int, int, int, int, int, int);
int calcNumberFromDigits(int, int, int, int, int, int);

int main()
{
	int sumOfNumbers = 0;

	// Loop through all five digits from 1 to 9
	// and calculate the sum of the 5th powers
	// of each integer
	for( int d1=0 ; d1<10 ; d1++ )
	{
		for( int d2=0 ; d2<10 ; d2++ )
		{
			for( int d3=0 ; d3<10 ; d3++ )
			{
				for( int d4=0 ; d4<10 ; d4++ )
				{
					for( int d5=0 ; d5<10 ; d5++ )
					{
						for( int d6=0 ; d6<10 ; d6++ )
						{
							if( calcFifthPowerSum(d1,d2,d3,d4,d5,d6) == calcNumberFromDigits(d1,d2,d3,d4,d5,d6) )
							{
								cout<<d1<<d2<<d3<<d4<<d5<<d6<<endl;
								sumOfNumbers += calcNumberFromDigits(d1,d2,d3,d4,d5,d6);
							}
						}
					}
				}
			}
		}
	}

	cout<<sumOfNumbers-1<<endl;


return 0;

}


int calcFifthPowerSum(int a, int b, int c, int d, int e, int f)
{
	int sum;
	sum = pow(a,5) + pow(b,5) + pow(c,5) + pow(d,5) + pow(e,5) + pow(f,5);
	return sum;
}

int calcNumberFromDigits(int g, int h, int i, int j, int k, int l)
{
	int number;
	number = g*100000 + h*10000 + i*1000 + j*100 + k*10 + l;
	return number;
}
