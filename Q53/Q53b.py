# Project Euler Question 53 (attempt b)

import math
import itertools

def numerator( n, r ) :
    prod = 1
    prod = long(prod)
    for i in range(n-r+1,n+1) :
        prod = prod*long(i)
    return prod

def denominator( r ) :
    prod = 1
    prod = long(prod)
    for i in range(1,r+1) :
        prod = prod*long(i)
    return prod


def nCr( n, r ) :
    value = numerator(n,r)/denominator(r)
    return value

N=0
for n in range(1,101) :
    for r in range(1,n) :
        if nCr( n, r) > 10**6 :
            N += 1
            print n, r
print "     ", N