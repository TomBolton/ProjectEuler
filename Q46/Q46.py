# Project Euler Question 46

import math
import itertools

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for i in  range(3, int( math.ceil( math.sqrt( integer ) ) + 1 ) ) :
        if integer%i == 0 : return False
    return True

def primeGenerator( n=1 ) :
    while( True ) :
        if isPrime( n ) : yield n
        n += 1

def isPrimeAndTwiceSquare( integer ) :
    for n in primeGenerator() :             # Loop through all primes less than the integer
        if n > integer : break
        diff = (integer - n)/2              # Calc half the difference between prime and integer
        if math.sqrt( float(diff) )%1 == 0 : return True
    return False


n = 9

while isPrimeAndTwiceSquare( n ) :
    n += 2
    while isPrime( n ) : n += 2

print n









