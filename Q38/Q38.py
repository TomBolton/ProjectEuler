# Project Euler Question 38

import math


def isPandigital( string ) :
    nDigits = [0]*9
    for i in range(1,10) :
        if string[i - 1] == str(1): nDigits[0] = nDigits[0] + 1
        if string[i - 1] == str(2): nDigits[1] = nDigits[1] + 1
        if string[i - 1] == str(3): nDigits[2] = nDigits[2] + 1
        if string[i - 1] == str(4): nDigits[3] = nDigits[3] + 1
        if string[i - 1] == str(5): nDigits[4] = nDigits[4] + 1
        if string[i - 1] == str(6): nDigits[5] = nDigits[5] + 1
        if string[i - 1] == str(7): nDigits[6] = nDigits[6] + 1
        if string[i - 1] == str(8): nDigits[7] = nDigits[7] + 1
        if string[i - 1] == str(9): nDigits[8] = nDigits[8] + 1
    product = 1
    for j in range(0,9) :
        product = product * nDigits[j]
    if product == 1 : return True
    return False




# Loop through n from 2 to 9; the value of n sets the
# maximum value of the multiplying value, as the number
# of digits has to equal 9.
maxMPower = [6,3,3,2,2,2,2,1]
maxPandigital = 0

for n in range(2,10) :
    for m in range( 1 , pow(10,maxMPower[n-2]) ) :

        string = str(1*m)
        for i in range(2,n+1) :
            string = string + str(i*m)

        if len(string) == 9 :
            if isPandigital( string ) :
                print string
                if int(string) > maxPandigital :
                    print "^^^ New max pandigital!"
                    maxPandigital = int(string)

print "    ", maxPandigital