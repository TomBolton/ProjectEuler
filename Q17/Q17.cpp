/*
 *		  Name: Q17.cpp
 *	Created on: 2 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
using namespace std;
int main()
{
	// make arrays for the number of letters for
	// each set of numbers
	int nOnes [10];
	int nTens [10];
	int nTensSpecial [10];

	nOnes[0] = 0; // zero, so no letters
	nOnes[1] = 3; // 'one'
	nOnes[2] = 3; // 'two'
	nOnes[3] = 5; // 'three'
	nOnes[4] = 4; // 'four'
	nOnes[5] = 4; // 'five'
	nOnes[6] = 3; // 'six'
	nOnes[7] = 5; // 'seven'
	nOnes[8] = 5; // 'eight'
	nOnes[9] = 4; // 'nine'

	nTens[0] = 0; // zero, so no letters
	nTens[1] = 0; // multiple options, so have to add an additional loop for this term
	nTens[2] = 6; // 'twenty'
	nTens[3] = 6; // 'thirty'
	nTens[4] = 5; // 'forty'
	nTens[5] = 5; // 'fifty'
	nTens[6] = 5; // 'sixty'
	nTens[7] = 7; // 'seventy'
	nTens[8] = 6; // 'eighty'
	nTens[9] = 6; // 'ninety'

	nTensSpecial[0] = 3; // 'ten'
	nTensSpecial[1] = 6; // 'eleven'
	nTensSpecial[2] = 6; // 'twelve'
	nTensSpecial[3] = 8; // 'thirteen'
	nTensSpecial[4] = 8; // 'fourteen'
	nTensSpecial[5] = 8; // 'fifteen'
	nTensSpecial[6] = 7; // 'sixteen'
	nTensSpecial[7] = 9; // 'seventeen'
	nTensSpecial[8] = 8; // 'eighteen'
	nTensSpecial[9] = 8; // 'nineteen'

	// make array for the number of letters for each value
	// between 1 and 1000
	int nValues [1000] = {};

	// loop through hundreds
	for( int hundreds=0 ; hundreds<10 ; hundreds++)
	{

		// loop through tens
		for( int tens=0 ; tens<10 ; tens++ )
		{
			// loop through ones
			for( int ones=0 ; ones<10 ; ones++ )
			{

				// treat 1-99 separately
				if( hundreds == 0 )
				{
					// check if tens=1
					if( tens==1 )
					{
						nValues[10*tens+ones] = nTensSpecial[ones];
					}else
					{
						nValues[10*tens+ones] = nOnes[ones] + nTens[tens];
					}

				}else
				{
					// check if tens=1
					if( tens==1 )
					{
						nValues[100*hundreds + 10*tens + ones] = nOnes[hundreds] + 7 + 3 + nTensSpecial[ones];
					}else
					{

						nValues[100*hundreds + 10*tens + ones] = nOnes[hundreds] + 7 + 3 + nTens[tens] + nOnes[ones];
						//if( hundreds == 9 ){cout<<100*hundreds + 10*tens + ones<<" "<<nOnes[hundreds]<<" "<<nTens[tens]<<" "<<nOnes[ones]<<" "<<nOnes[hundreds]+nTens[tens]+nOnes[ones]<<" "<<nValues[100*hundreds+10*tens+ones]<<endl;}
					}

				}

			}
		}
	}

	// sum letters
	int sum = 0;

	for( int i=0 ; i<1000 ; i++)
	{
		sum = sum + nValues[i];
	}

	// there are nine instances where the word 'and' does not appears but is
	// none the less counted. This happens for 100,200,300, etc. Correct for
	// this here
	sum = sum - 3*9;
	// add letters for one thousand
	sum = sum + 11;

	for( int i=0 ; i<1000 ; i++)
	{
		cout<<nValues[i]<<endl;
	}

	cout<<sum<<endl;

return 0;
}
