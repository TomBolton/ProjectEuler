# Project Euler Question 47

import math
import itertools

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for i in  range(3, int( math.ceil( math.sqrt( integer ) ) + 1 ) ) :
        if integer%i == 0 : return False
    return True

def primeGenerator( n=2 ) :
    while( True ) :
        if isPrime( n ) : yield n
        n += 1

def findPrimeFactors( integer ) :
    primeList = []
    for prime in primeGenerator() :
        if len( primeList ) > 4 : break                    # We only care about integers with 4 prime factors
        if prime > integer : break                # Only consider primes that are less than integer
        if integer%prime == 0 :                   # Check if prime is a factor
            primeList.append( prime )             # Add prime to the list

    return primeList

def areDistinct( list ) :
    N = len(list)
    for i in range(0,N) :
        for j in range(0,N) :
            if i != j  and list[i] == list[j] : return False
    return True

def areDistinctAndFourLong( list1, list2, list3, list4 ) :
    if len(list1) == 4 and len(list2) == 4 and len(list3) == 4 and len(list4) == 4 :
        if areDistinct( list1 ) and areDistinct( list2 ) and areDistinct( list3 ) and areDistinct( list4 ) :
            return True
    return False

# Loop through all four-digit integers and calculate the
# prime factors of the four consecutive integers
n = 10

list1 = findPrimeFactors( n )
list2 = findPrimeFactors( n+1 )
list3 = findPrimeFactors( n+2 )
list4 = findPrimeFactors( n+3 )

while not areDistinctAndFourLong( list1, list2, list3, list4 ) :

    list1 = list2
    list2 = list3
    list3 = list4
    list4 = findPrimeFactors( n+3 )

    if len(list4) > 4 :
        n += 4
    else :
        n += 1

    print n

print n



