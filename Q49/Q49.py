# Project Euler Question 49

import math
import itertools

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for n in range(3, int( math.ceil( math.sqrt( integer ) ) + 1 ) ) :
        if integer%n == 0 : return False
    return True



def isPermutation( n1, n2 ) :
    s1 = str( n1 )
    s2 = str( n2 )
    for s in itertools.permutations( s1 ) :
        if s2[0] == s[0] and s2[1] == s[1] and s2[2] == s[2] and s2[3] == s[3] :
            return True
    return False

def primes( n=1000 ) :
    while n<10000 :
        if isPrime( n ) : yield n
        n += 1


# Loop through all four digit primes
for n1 in primes() :
    print n1
    for diff in range(1, int( math.floor( 10000.0 - float(n1) )/2.0 ) ) :       # Loop through all potential differences
        n2 = n1 + diff
        n3 = n2 + diff
        if isPermutation( n1, n2 ) and isPermutation( n1, n3 ) :
            if isPrime( n2 ) and isPrime( n3 ) :
                print n1, n2, n3
