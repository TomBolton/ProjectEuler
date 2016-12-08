# Project Euler Question 56

import math


def sumDigitValues( integer ) :
    string = str( integer )
    sum = 0
    for c in string :
        sum = sum + int( c )
    return sum

maxSum = 0
for a in range(1,100) :
    for b in range(1,100) :
        sum = sumDigitValues( a**b )
        if sum>maxSum :
            print sum
            maxSum = sum

print maxSum