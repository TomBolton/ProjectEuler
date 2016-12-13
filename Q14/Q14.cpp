/*
 *		  Name: Q14.cpp
 *	Created on: 2 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
using namespace std;

int countCollatzTerms(long);

int main()
{
	int maxTerms = 0;
	long iMaxTerms = 0;
	int nTerms = 0;

	for( long i=2 ; i<1000000 ; i++ )
	{
		nTerms = countCollatzTerms(i);

		if( nTerms > maxTerms)
		{
			maxTerms = nTerms;
			iMaxTerms = i;
		}
	}

	cout<<iMaxTerms<<endl;

return 0;
}

int countCollatzTerms(long n)
{
	int nTerms = 1;

	while( n != 1)
	{
		if( n%2 == 0 )
		{
			n = n/2;
		}
		else
		{
			n = 3*n+1;
		}

		nTerms++;

	}

	return nTerms;
}
