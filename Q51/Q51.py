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

def threeFromNCombos( N ) :
    for s in itertools.product('001', repeat=N) :
        nOnes = 0
        for i in range(0,N) :
            if s[i] == '1' : nOnes += 1
        if nOnes == 3 and s[0] != '1' : yield s

def makeString( string, n1, n2, n3, i ) :
    list = []
    for n in range(0,len(string)) :
        if n == n1 :
            list.append( str(i) )
        elif n == n2 :
            list.append( str(i) )
        elif n == n3 :
            list.append( str(i) )
        else :
            list.append( string[n] )
    newString = list[0]
    for m in range(1,len(string)) :
        newString = newString + list[m]
    return newString

def primeFamilyTest( string, n1, n2, n3 ) :
    N = 0
    for i in range(0,10) :
        newString = makeString( string, n1, n2, n3, i )
        if string == '121313' : print newString, n1, n2, n3, i, isPrime(int(newString))
        if isPrime( int( newString ) ) :
            N += 1
    if N > 7 :
        return True
    else :
        return False

def comboTest( primeString, N ) :
    for s in threeFromNCombos( N ) :    # Loop through all combinations of two ones in five binary digits
        n1 = 0
        while s[n1] == '0' :
            n1 += 1
        n2 = n1 + 1
        while s[n2] == '0' :
            n2 += 1
        n3 = n2 + 1
        while s[n3] == '0' :
            n3 += 1

        if primeFamilyTest( primeString, n1, n2, n3 ) :
            print "8 prime family found!!", primeString
            return True
    return False

# Loop through primes until an 8-prime family is found
for p in primeGenerator() :
    print p
    primeString = str(p)
    N = len( primeString )
    if comboTest( primeString, N ) : break



