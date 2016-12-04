# Project Euler Question 47 (method b)

import math

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for i in  range(3, int( math.ceil( math.sqrt( integer ) ) + 1 ) ) :
        if integer%i == 0 : return False
    return True

def primeGenerator( n=2 ) :
    while True :
        if isPrime( n ) : yield n
        n += 1

def howManyPrimeFactors( primeList, integer ) :
    num = 0
    for p in primeList :
        if integer%p == 0 :
            num += 1
            if num == 5 : break             # We only care about integers with four prime factors
    return num

def hasFourPrimeFactors( a, b, c, d, primeList ) :
    n1 = howManyPrimeFactors( primeList, a )
    n2 = howManyPrimeFactors( primeList, b )
    n3 = howManyPrimeFactors( primeList, c )
    n4 = howManyPrimeFactors( primeList, d )

    if n1 == 4 and n2 == 4 and n3 == 4 and n4 == 4 :
        return True
    else :
        return False





# First make a list of the first N prime numbers
N = 200
primeList = []
for p in primeGenerator() :
    primeList.append(p)
    if len(primeList) > N : break

# Now loop through sets of four consecutive integers, checking
# if the number of distinct prime factors is four
n = 10

while not hasFourPrimeFactors( n, n+1, n+2, n+3, primeList ) :
    n += 1
    if n%1000 == 0 : print n
print "    ", n



