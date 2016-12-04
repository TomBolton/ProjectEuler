# Project Euler Question 39

import math

maxN = 0
pMax = 0

for p in  range(4,1001) :
    N = 0
    for a in range(1,p) :
        for b in range(a+1,p) :
            c = math.sqrt( a*a + b*b )
            if c%1 == 0 and a+b+c == p :
                N = N + 1
                print a, b, c, p
    if N>maxN :
        maxN = N
        pMax = p

print maxN, pMax