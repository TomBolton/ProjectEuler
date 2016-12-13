/*
 *		  Name: Q18.cpp
 *	Created on: 2 Oct 2016
 *	Created by: Thomas Bolton
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int row1 = 75;
	int row2 [2] = {95,64};
	int row3 [3] = {17,47,82};
	int row4 [4] = {18,35,87,10};
	int row5 [5] = {20,4,82,47,65};
	int row6 [6] = {19,1,23,75,3,34};
	int row7 [7] = {88,2,77,73,7,63,67};
	int row8 [8] = {99,65,4,28,6,16,70,92};
	int row9 [9] = {41,41,26,56,83,40,80,70,33};
	int row10 [10] = {41,48,72,33,47,32,37,16,94,29};
	int row11 [11] = {53,71,44,65,25,43,91,52,91,51,14};
	int row12 [12] = {70,11,33,28,77,73,17,78,39,68,17,57};
	int row13 [13] = {91,71,52,38,17,14,91,43,58,50,27,29,48};
	int row14 [14] = {63,66,4,68,89,53,67,30,73,16,69,87,40,31};
	int row15 [15] = {4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};

	int sum1;
	int sum2;
	int sum3;
	int sum4;
	int sum5;
	int sum6;
	int sum7;
	int sum8;
	int sum9;
	int sum10;
	int sum11;
    int sum12;
    int sum13;
    int sum14;

	int maxSum = 0;

	for( int i1=0 ; i1<=1 ; i1++)
	{
		sum1 = row1 + row2[i1];

		for( int i2=i1 ; i2<=i1+1 ; i2++)
		{
			sum2 = sum1 + row3[i2];

			for( int i3=i2 ; i3<=i2+1 ; i3++)
			{
				sum3 = sum2 + row4[i3];

				for( int i4=i3 ; i4<=i3+1 ; i4++ )
				{
					sum4 = sum3 + row5[i4];

					for( int i5=i4 ; i5<=i4+1 ; i5++ )
					{
						sum5 = sum4 + row6[i5];

						for( int i6=i5 ; i6<=i5+1 ; i6++ )
						{
							sum6 = sum5 + row7[i6];

							for( int i7=i6 ; i7<=i6+1 ; i7++ )
							{
								sum7 = sum6 + row8[i7];

								for( int i8=i7 ; i8<=i7+1 ; i8++ )
								{
									sum8 = sum7 + row9[i8];

									for( int i9=i8 ; i9<=i8+1 ; i9++ )
									{
										sum9 = sum8 + row10[i9];

										for( int i10=i9 ; i10<=i9+1 ; i10++ )
										{
											sum10 = sum9 + row11[i10];

											for( int i11=i10 ; i11<=i10+1 ; i11++ )
											{
												sum11 = sum10 + row12[i11];

												for( int i12=i11 ; i12<=i11+1 ; i12++ )
												{
													sum12 = sum11 + row13[i12];

													for( int i13=i12 ; i13<=i12+1 ; i13++ )
													{
														sum13 = sum12 + row14[i13];

														for( int i14=i13 ; i14<=i13+1 ; i14++ )
														{
															sum14 = sum13 + row15[i14];

															//cout<<sum<<endl;
														    if( sum14>maxSum )
														    {
																maxSum = sum14;
																cout<< maxSum << endl;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

return 0;
}
