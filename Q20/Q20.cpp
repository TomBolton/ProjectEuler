/*
 *		  Name: Q20.cpp
 *	Created on: 4 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int a[200]; //array will have the capacity to store 200 digits.
    int n,i,j,temp,m,x;


    n=20;

    a[0]=1;  // Initialises array with only 1 digit, the digit 1.
    m=1;     // Initialises digit counter

    temp = 0; 			// Initialises carry variable to 0.
    for(i=1;i<=n;i++)
    {
    	cout<<"Number of digits: "<<m<<"  for "<<i<<"!"<<endl;

    	for(j=0;j<m;j++)    // This loop goes through the digits until it reaches the last (m th) digit
    	{
    		x = a[j]*i+temp; 	// x contains the digit by digit product
    		a[j]=x%10; 			// Contains the digit to store in position j
    		cout<<a[j]<<" "<<temp<<endl;
    		temp = x/10; 		// This calculates how many tens you have left over
    	}

    	// The code above first adds on the 'temp' variable to i*a[j]. It
    	// then calculates what the jth digit is by using x%10 where x = a[j]*i.
    	// The new 'temp' is then x/10, as x is an 'int' so it automatically
    	// rounds (which gives the number of 10s in x). If 'temp' is non-zero
    	// after this loop has finished, then the carry on goes to the next digits.

        while(temp>0) 	// while loop that will store the carry value on array.
        {
            a[m]=temp%10;
            temp = temp/10;
            m++; 		// increments digit counter
        }
     }

    int sumOfDigits=0;
        for( i=m-1 ; i>=0 ; i--)
        {
         	sumOfDigits = sumOfDigits + a[i];
        }

        cout<<sumOfDigits<<endl;

    return 0;
}
