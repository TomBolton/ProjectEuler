# Project Euler Question 57

import math

def rootTwoIterations( n ) :             # Apply 'n' iterations of the continued fraction of sqrt(2).
    a = 5; b = 2                         # Starting fraction is 5/4
    for i in range(1,n-1) :
        aNew = 2*a + b
        bNew = a
        a = aNew; b = bNew
    aNew = a + b
    bNew = a
    return [aNew,bNew]

def isMoreDigits( a, b ) :              # Test to see if the numerator has more digits
    aStr = str(a)                       # than the denominator
    bStr = str(b)
    if len( aStr ) > len( bStr ) : return True
    return False


N = 0
for n in range(2,1001) :
    newValues = rootTwoIterations( n )
    a = newValues[0]
    b = newValues[1]
    print n, ": ", a, "/", b
    if isMoreDigits( a, b ) : N += 1

print "  ", N