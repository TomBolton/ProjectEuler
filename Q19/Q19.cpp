/*
 *		  Name: Q19.cpp
 *	Created on: 3 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
using namespace std;

int whatIsTheFirstDay(int);

int main()
{
	// first define the first day for each month
	int jan = 1;
	int feb = 1+31;
	int mar = 1+31+28;
	int apr = 1+31+28+31;
	int may = 1+31+28+31+30;
	int jun = 1+31+28+31+30+31;
	int jul = 1+31+28+31+30+31+30;
	int aug = 1+31+28+31+30+31+30+31;
	int sep = 1+31+28+31+30+31+30+31+31;
	int oct = 1+31+28+31+30+31+30+31+31+30;
	int nov = 1+31+28+31+30+31+30+31+31+30+31;
	int dec = 1+31+28+31+30+31+30+31+31+30+31+30;

	int monthDays [12] = {jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
	int monthDaysLeap [12] = {jan,feb,mar+1,apr+1,may+1,jun+1,jul+1,aug+1,sep+1,oct+1,nov+1,dec+1};

	int numberOfSundays = 0;
	int firstOfTheMonth, firstDay;

	// loop through years from the start of 1901 to the end of 2000
	for( int year=1901 ; year<=2000 ; year++ )
	{
		// calculate the first day of this year
		firstDay = whatIsTheFirstDay(year);
		//cout<<firstDay<<" "<<year<<endl;

		if( year%4 == 0 && year!=1900 )
		{
			// leap year
			for( int month=1 ; month<=12 ; month++)
			{
				// get the number of the first day of the month
				firstOfTheMonth = monthDaysLeap[month];

				// see if the first of the month is a sunday
				if( (7+firstOfTheMonth+1-firstDay)%7 == 0)
				{
					numberOfSundays++;
				}

			}
		}else
		{
			// non-leap year
			for( int month=1 ; month<=12 ; month++)
			{
				// get the day-number of the first of the month
				firstOfTheMonth = monthDays[month];

				// see if the first of the month is a sunday
				if( (firstOfTheMonth + 7 - firstDay + 1)%7 == 0 )
				{
					numberOfSundays++;
				}
			}
		}

		cout<<numberOfSundays<<" "<<year<<endl;
	}

cout<<numberOfSundays<<endl;

return 0;
}


int whatIsTheFirstDay(int year)
{
	year = year - 1900;
	int day=0;
	int Y=1;

	do
	{

		if( (Y-2)%4 == 0 && Y!=1 )
		{
			day+=2;
		}
		else
		{
			day++;
		}

		Y++;

		//cout<<day<<" "<<Y<<" "<<year<<endl;

	}while( Y<=year );

	// mon = 1
	// tue = 2
	// wed = 3
	// thu = 4
	// fri = 5
	// sat = 6
	// sun = 7



	day = day%7;
	if( day==0)
	{
		day = 7;
	}
	//cout<<day<<" "<<year+1899<<endl;
	return day;
}


