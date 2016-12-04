# Project Euler Question 41

import math
import itertools

def isPrime( integer ) :
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for n in range(3, int( math.ceil( math.sqrt( integer ) ) ) + 1) :
        if integer%n == 0 : return False
    return True

maxPrime = 0

for n in range(3,9) :
    intStr = str(1)
    for i in range(1,n) :             # Make a string of '123...n'
        intStr = intStr + str(i+1)

    for s in itertools.permutations( intStr ) :         # Loop through all permutations of string
        newInt = 0
        for j in range(0,n) :
            newInt = newInt + pow(10,j)*int(s[j])       # Make new integer from this permutation

        if isPrime(newInt) :
            if newInt > maxPrime :
                maxPrime = newInt
                print maxPrime, " NEW MAX PRIME!!"

print "Max pandigital prime number: ", maxPrime





