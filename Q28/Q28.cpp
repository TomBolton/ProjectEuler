/*
 *		  Name: Q28.cpp
 *	Created on: 20 Nov 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	// Start timing
	clock_t t;
	t = clock();

	// Loop through the number of spirals until the
	// spiral is N x N numbers (where N is odd). Start
	// with the 3x3 spiral, with the one in the center
	// already counted.
	int N = 1001, n = 3, firstNum, sumOfDiagonals = 1;

	while( n <= N )
	{
		// The starting integer of a spiral is the
		// total number of numbers that have appeared
		// in previous spirals, plus one.
		//
		// For example, the first digit of the fourth
		// spiral is n^2 + 1 = 5^2 + 1 = 26, where n
		// is the dimension of the spiral. The
		// dimension of the spiral n is related to the
		// number of spirals m by: n = 2m - 1.

		// Calculate the first number of the spiral
		firstNum = (n-2)*(n-2) + 1;

		// The first diagonal (right-bottom) is
		// n-2 numbers away. Add this to the sum.
		sumOfDiagonals += firstNum + n - 2;
		// Add the left-bottom diagonal to the sum.
		sumOfDiagonals += firstNum + n - 2 + n - 1;
		// Add the left-top diagnonal to the sum.
		sumOfDiagonals += firstNum + n - 2 + (n - 1)*2;
		// Add the right-top diagonal to the sum.
		sumOfDiagonals += firstNum + n - 2 + (n - 1)*3;

		n += 2;  // The dimensions increase by two
				 // for every new spiral
	}

	cout<<"Sum of spiral diagonals up to dimension "<<N<<"x"<<N<<" ="<<sumOfDiagonals<<endl;

	// Finish timing
	t = clock() - t;
	cout<<"Time to run (in seconds): "<<(double)t/CLOCKS_PER_SEC<<endl;

return 0;

}
