# Project Euler Question 51

import math
import itertools

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for i in range(3, int( math.ceil( math.sqrt( integer ) ) + 1 )) :
        if integer%i == 0 : return False
    return True

def primeGenerator( n = 10**5 ) :
    while True :
        if isPrime( n ) : yield n
        n += 1

def makeListFromPrime( prime ) :    # A function to make an integer into a list of digits
    primeString  = str( prime )
    list = []
    for i in range(0,len( primeString ) ) :
        list.append( int( primeString[i] ) )
    return list

def makePrimeFromList( list ) :     # A function to make a number from a list of digits
    prime = str( list[0] )
    for i in range(1,len( list ) ) :
        prime = prime + str( list[i] )
    prime = int( prime )
    return prime

def testPrimeFamily( prime, positions ) :    # Positions is a list of digit positions to be replaced.
    nPrimes = 0
    for i in range(0,10) :                      # Loop through all replacement numbers 0,1,2,3... etc
        primeList = makeListFromPrime(prime)
        for j in range(0, len(positions) ) :    # Loop through all digits to be replaced.
            primeList[ positions[j] ] = i
        newPrime = makePrimeFromList( primeList )
        if isPrime( newPrime ) : nPrimes += 1
    return nPrimes

def countOnesInList( list ) :
    nOnes = 0
    for i in range(0,len(list)) :
        if list[i] == '1' : nOnes += 1
    return nOnes

def digitPositions( n, p ) :            # Make different combinations of digits to replace.
    for combo in itertools.product('01', repeat = len( str( p ) ) - 1 ) :
        combo = list( combo )
        if countOnesInList( combo ) == n :
            combo.append('0')
            pos = [0]*n
            N = 0
            for i in range(0,len( str(p) ) ) :
                if combo[i] == '1' :
                    pos[N] = i
                    N += 1
            yield pos


# Loop through primes until you find an 8 prime family
for p in primeGenerator() :
    print p
    for pos in digitPositions( 3, p ) :
        if testPrimeFamily( p, pos ) > 7 :
            print "DING DING DING", p


















