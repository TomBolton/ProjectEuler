# Project Euler Question 44

import math

def isPentagonal( p ) :
    n = 1.0/6 + math.sqrt(1.0/36 + 2.0*p/3)
    if n%1 == 0 : return True
    return False

dMin = pow(10,9)

for n in range(1,10000) :
    for m in range(1,10000) :
        if n != m :
            p1 = ( 3*n-1 )*n/2
            p2 = ( 3*m-1 )*m/2
            if isPentagonal( p1+p2 ) and isPentagonal( abs(p1-p2) ) :
                print p1, " ", p2
                if abs(p1-p2) < dMin : dMin = abs(p1-p2)

print dMin

print isPentagonal(145)