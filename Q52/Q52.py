# Project Euler Question 52

import math
import itertools

def isEqual( s2, s) :
    for i in range(0,len(s)) :
        if s2[i] != s[i] : return False
    return True

def isPerm( s1, s2 ) :
    for s in itertools.permutations( s1 ) :
        if isEqual( s2, s ) : return True
    return False

def isMultiPerm( integer ) :
    s1 = str( integer )
    s2 = str( 2*integer )
    s3 = str( 3*integer )
    s4 = str( 4*integer )
    s5 = str( 5*integer )
    s6 = str( 6*integer )

    if isPerm(s1,s2) and isPerm(s1,s3) and isPerm(s1,s4) and isPerm(s1,s5) and isPerm(s1,s6) :
        return True
    return False

n = 1
while not isMultiPerm( n ) :
    n += 1
    if n%1000 == 0 : print n

print "   ", n