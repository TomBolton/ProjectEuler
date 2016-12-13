/*
 *		  Name: Q24.cpp
 *	Created on: 30 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	// Make an array of size 10 for the numbers
	// 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9. This array
	// will be used to make the various permutations
	// of the digits, in lexicographic order.

	int digitArray[] = {0,1,2,3,4,5,6,7,8,9};

	// In lexicographic order, the left most digit is
	// permuted last (exactly like how words in a dictionary
	// are ordered). Therefore, you permute the right most
	// digits first and move left. The first permutations of
	// the above digits will be:
	//
	// 		0 1 2 3 4 5 6 7 8 9     (permute right-most 2 digits)
	// 		0 1 2 3 4 5 6 7 9 8		 2! combinations
	//
	// 		0 1 2 3 4 5 6 8 7 9     (permute right-most 3 digits)
	// 		0 1 2 3 4 5 6 8 9 7		 3! combinations
	// 		0 1 2 3 4 5 6 9 7 8
	// 		0 1 2 3 4 5 6 9 8 7

	// 		0 1 2 3 4 5 7 6 8 9		(permute right-most 4 digits)
	// 		0 1 2 3 4 5 7 6 9 8		 4! combinations
	//      0 1 2 3 4 5 7 8 6 9
	//      0 1 2 3 4 5 7 8 9 6
	//      0 1 2 3 4 5 7 9 6 8
	//      0 1 2 3 4 5 7 9 8 6
	//	    0 1 2 3 4 5 8 6 7 9
	//      0 1 2 3 4 5 8 6 9 7
	//      0 1 2 3 4 5 8 7 6 9
	// 	    0 1 2 3 4 5 8 7 9 6
	//      0 1 2 3 4 5 8 9 6 7
	//      0 1 2 3 4 5 8 9 7 6
	//      0 1 2 3 4 5 9 6 7 8
	//      0 1 2 3 4 5 9 6 8 7
	//      0 1 2 3 4 5 9 7 6 8
	//      0 1 2 3 4 5 9 7 8 6
	//      0 1 2 3 4 5 9 8 6 7
	//      0 1 2 3 4 5 9 8 7 6

	int numPerms = 1;

	while( numPerms<1000000 )
	{
		next_permutation(digitArray,digitArray+10);
		numPerms++;
	}



	cout<<"Number of permutations: "<<numPerms<<endl;
	cout<<digitArray[0]<<digitArray[1]<<digitArray[2]<<digitArray[3]<<digitArray[4]<<digitArray[5]<<digitArray[6]<<digitArray[7]<<digitArray[8]<<digitArray[9]<<endl;



return 0;

}


