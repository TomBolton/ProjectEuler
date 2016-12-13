/*
 *		  Name: Q22.cpp
 *	Created on: 27 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int sumAlphaValues(string s);
void sortAlphabetical(string[], int);

int main()
{
	// choose number of words
	int N = 5163;

	// Initialise arrays to store names as strings
	string nameArray[N];

	ifstream names;
	names.open("names.txt");

	// Loop through from 1 to 5000 and pick out each name
	for( int i=0 ; i<N ; i++ )
	{
		// insert code to extract names from names.txt
		getline(names,nameArray[i],',');
	}

	// Sort the names in nameArray alphabetically into the
	// array called sortedArray
	sortAlphabetical(nameArray,N);

	// Loop through all 5000 names and then loop through all letters
	// in each string. Then convert each letter to its alphabetical
	// value using the function below and then sum
	int sum=0;
	string nameString;

	for( int j=0 ; j<N ; j++ )
	{
		nameString = nameArray[j];

		// Calculate alphabetical value of all letters in nameString
		// and multiply by its position in the name.txt file
		sum = sum + (j+1)*sumAlphaValues(nameString);
	}

	for( int i=0 ; i<N ; i++ )
	{
		cout<<i+1<<"  "<<nameArray[i]<<endl;
	}


	cout<<"Sum of alphabetical values multiplied by position: "<<sum<<endl;


return 0;
}

void sortAlphabetical(string stringArray[], int size)
{

	// Use a Bubble Sort (swapping) algorithm to sort
	// names into alphabetical order
	int numOfSwaps;
	string name1, name2;

	do
	{
		numOfSwaps = 0;

		// Loop through all names and see if it needs
		// swapping with the adjacent name
		for( int j=0 ; j<size-1 ; j++)
		{
			if( stringArray[j] > stringArray[j+1] )
			{
				name1 = stringArray[j];
				name2 = stringArray[j+1];

				stringArray[j] = name2;
				stringArray[j+1] = name1;

				numOfSwaps++;
			}
		}

	}
	while( numOfSwaps != 0 );

}

int sumAlphaValues(string s)
{
	// Take a letter and calculate its alphabetical value
	// by converting into its ASCII value and subtracting 64
	// (in ASCII, A=65, B=66, etc).

	// Loop through all letters in the string and calculate
	// the alphabetical value of each
	int stringLength = s.size();
	int sum=0;

	// Only loop from 2nd to 2nd last letters in string e.g.
	// for "MARY" you only want to deal with the characters
	// M, A, R and Y.
	for( int i=1 ; i<stringLength-1 ; i++ )
	{

		sum = sum + s[i] - 64;

	}

	return sum;
}

