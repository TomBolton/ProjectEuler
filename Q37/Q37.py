# Project Euler Question 37

import math

def isPrime( integer ) :
    if integer == 1 : return False
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for i in range(3, int( math.ceil( math.sqrt(integer) + 1 ) ) ) :
        if integer%i == 0 : return False
    return True

def isLeftTruncatable( integer ) :
    nDigits = math.log(integer,10)     # Calculate the number of digits

    for n in  range( int(nDigits) , 0 , -1 ) :
        integer = integer - int( pow(10,n)*( math.floor( integer/pow(10,n) ) ) )
        if not isPrime( integer ) : return False
    return True

def isRightTruncatable( integer ) :
    nDigits = math.log(integer,10)      # Calculate the number of digits

    for n in range( 1 , int(nDigits)+1) :
        integer = int( math.floor( integer/10 ) )
        if not isPrime( integer ) : return False
    return True



nPrimes = 0
sum = 0
i = 10
while nPrimes < 11 :
    if isPrime( i ) and isLeftTruncatable( i ) and isRightTruncatable( i ) :
        print i, " nPrimes = ", nPrimes+1
        sum = sum + i
        nPrimes = nPrimes + 1
    i = i + 1

print "Sum = ", sum
