# Project Euler Question 50

import math

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for n in range(3, int( math.ceil( math.sqrt( integer ) ) + 1 ) ) :
        if integer%n == 0 : return False
    return True


def primes( n=2 ) :
    while n<100000 :
        if isPrime( n ) : yield n
        n += 1



# Loop through all the prime numbers below one million
# and make a list of them
primeList = []
for p in primes() :
    primeList.append( p )

# Loop through the list of primes, can calculate the sum of
# all previous primes. Check if this sum is prime
maxSum = 0
for n in range(0,len(primeList)) :
    for m in range(0,n) :
        sum = 0
        for l in range(m,n) :
            sum = sum + primeList[l]
            if sum>1000000 : break
        if isPrime( sum ) :
            if sum>maxSum :
                print sum
                maxSum = sum
