/*
 *		  Name: Q11.cpp
 *	Created on: 30 Sep 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	vector<int> array;
	ifstream inFile("numbers.txt");
	int number;

	while(inFile >> number)
	{
		// extract numbers from text file
		array.push_back(number);
	}

	int productOfValues = 1;
	int maxProduct = 0;

	// now check products of up/down values
	for( int i=0 ; i<400-60 ; i++ )
	{
		productOfValues = array[i]*array[i+20]*array[i+40]*array[i+60];

		// check if this product is largest
		if( productOfValues > maxProduct )
		{
			maxProduct = productOfValues;
			cout<<maxProduct<<endl;
			cout<<"^^ New Maximum!"<<endl;
		}

	}
	// now check products of left/right values
	for( int i=0 ; i<20 ; i++ )
	{
		for( int j=0 ; j<20-3 ; j++)
		{
			productOfValues = array[i*20+j]*array[i*20+j+1]*array[i*20+j+2]*array[i*20+j+3];

			// check if this product is largest
			if( productOfValues > maxProduct )
			{
				maxProduct = productOfValues;
				cout<<maxProduct<<endl;
				cout<<"^^ New Maximum!"<<endl;
			}
		}
	}
	// now check products of left-to-right DIAGONAL values
		for( int i=0 ; i<20-3 ; i++ )
		{
			for( int j=0 ; j<20-3 ; j++)
			{
				productOfValues = array[i*20+j]*array[(i+1)*20+j+1]*array[(i+2)*20+j+2]*array[(i+3)*20+j+3];

				// check if this product is largest
				if( productOfValues > maxProduct )
				{
					maxProduct = productOfValues;
					cout<<maxProduct<<endl;
					cout<<"^^ New Maximum!"<<endl;
				}
			}
		}

		// now check products of right-to-left DIAGONAL values
				for( int i=0 ; i<20-3 ; i++ )
				{
					for( int j=3 ; j<20 ; j++)
					{
						productOfValues = array[(i)*20+j]*array[(i+1)*20+j-1]*array[(i+2)*20+j-2]*array[(i+3)*20+j-3];

						// check if this product is largest
						if( productOfValues > maxProduct )
						{
							maxProduct = productOfValues;
							cout<<maxProduct<<endl;
							cout<<"^^ New Maximum!"<<endl;
						}
					}
				}
return 0;
}
