# Project Euler Question 60

import math
import itertools

def isPrime( n ) :          # A function to test whether n is primes
    if n == 2 : return True
    if n == 3 : return True
    if n == 5 : return False   # Even though 5 is prime, it doesn't serve our purpose later on.
    if n % 2 == 0 : return False
    for i in range( 3, int( math.ceil( math.sqrt( n ) ) + 1 ) ):
        if n % i == 0 : return False
    return True

def primes( n = 3 ) :           # A generator of primes ( dont start at 2 for this question )
    while( n<10000 ) :
        if isPrime( n ) : yield n
        n += 1

def concatAndTest( prime1, prime2 ) :
    if prime1 == prime2 : return False
    newPrime1 = int( str(prime1) + str(prime2) )
    newPrime2 = int( str(prime2) + str(prime1) )
    if isPrime( newPrime1 ) and isPrime( newPrime2 ) :
        return True
    return False


# Loop through combinations of five primes. Start from 3 as the prime two
# will not produce primes if concatenated (also ignore 5 as that will not
# produce a prime if put on the end of a number). Loop through two primes
# to begin with, and if concatenations are prime then add a third prime
# loop, and so on.
for p1 in primes() :
    for p2 in primes() :
        if concatAndTest( p1, p2 ) :        # Test if p1 and p2 concatenated are prime

            for p3 in primes() :
                if concatAndTest( p1, p3 ) and concatAndTest( p2, p3 ) :     # Test p3 with p1 and p2

                    for p4 in primes() :
                        if concatAndTest( p1, p4 ) and concatAndTest( p2, p4 ) and concatAndTest( p3, p4 ) :    # Test p4 with p1, p2 and p3

                            for p5 in primes() :
                                if concatAndTest( p1, p5 ) and concatAndTest( p2, p5 ) and concatAndTest( p3, p5 ) and concatAndTest( p4, p5 ) :
                                    print "Found one!! ", p1, p2, p3, p4, p5, p1+p2+p3+p4+p5
                                    break

