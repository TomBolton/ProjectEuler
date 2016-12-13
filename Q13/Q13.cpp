/*
 *		  Name: Q13.cpp
 *	Created on: 2 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	double value;
	double sum = 0.0;
	int integer = 1;

	ifstream inFile("numbers_q13.txt");

	while( inFile >> value )
	{
		sum = sum + value;

		cout<<integer<<endl;
		integer++;
	}

	cout<<static_cast<long>(sum*pow(10.0,-42))<<endl;
return 0;
}
;
