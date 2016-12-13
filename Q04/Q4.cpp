/*
 *		  Name: Q4.cpp
 *	Created on: 27 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>

using namespace std;

bool palinedromeTest(int n);

int main()
{
	int largestPalinedrome = 0;

    // loop through the product of all 3 digit numbers
	// and test if each is a palindrome
	for( int i=100 ; i<1000 ; i++ )
	{
		for( int j=100 ; j<1000 ; j++ )
		{
			// see if i*j is a palindrome
			bool isPalinedrome = palinedromeTest((i*j));

			// print number if palindrome
			if( isPalinedrome == true)
			{
				// print out this palindrome
				cout<<i*j<<" = "<<i<<"*"<<j<<" <-- palindrome!"<<endl;

				// see if this palindrome was larger than the previous
				if( (i*j)>largestPalinedrome )
				{
					largestPalinedrome = i*j;
				}
			}
		}
	}

	// print the largest palindrome found
	cout<<"Largets palinedrome under 1000,000 is: "<<largestPalinedrome<<endl;

	return 0;
}



bool palinedromeTest(int n)
{

	// see if n is 5 or 6 digits long
	double nDigits = log10(n);


    // see if string is either 5 or 6 characters long
    // and then extract individual digits
    if( nDigits < 5 )
    {
    	int digitOne = n/10000;
    	int digitTwo = (n-digitOne*10000)/1000;
    	int digitThree = (n - digitOne*10000 - digitTwo*1000)/100;
    	int digitFour = (n - digitOne*10000 - digitTwo*1000 - digitThree*100)/10;
    	int digitFive = (n - digitOne*10000 - digitTwo*1000 - digitThree*100 - digitFour*10);

    	// see if palindrome
    	if( digitOne == digitFive && digitTwo == digitFour )
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    else
    {
    	int digitOne = n/100000;
    	int digitTwo =   (n-digitOne*100000)/10000;
    	int digitThree = (n - digitOne*100000 - digitTwo*10000)/1000;
    	int digitFour =  (n - digitOne*100000 - digitTwo*10000 - digitThree*1000)/100;
    	int digitFive =  (n - digitOne*100000 - digitTwo*10000 - digitThree*1000 - digitFour*100)/10;
    	int digitSix =   (n - digitOne*100000 - digitTwo*10000 - digitThree*1000 - digitFour*100 - digitFive*10);

    	// see if palindrome
    	if( digitOne == digitSix && digitTwo == digitFive && digitThree == digitFour )
    	{
    		return true;
    	}
        else
    	{
        	return false;
    	}
    }
}
