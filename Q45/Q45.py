# Project Euler Question 45

import math

def isTriangular( T ) :
    n = -0.5 + math.sqrt( 2.0*T + 0.25 )
    if n%1 == 0 :  return True
    return False

def isPentagonal( P ) :
    n = 1.0/6 + math.sqrt(1.0/36 + 2.0*P/3)
    if n%1 == 0 :  return True
    return False

def isHexagonal( H ) :
    n = 0.25 + math.sqrt( 1.0/16 + 0.5*H )
    if n%1 == 0 :   return True
    return False

m = 40755 + 1

while not ( isTriangular( m ) and isPentagonal( m ) and isHexagonal( m ) ) :
    m = m + 1


print m