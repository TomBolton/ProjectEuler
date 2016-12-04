# Project Euler Question 35


import itertools
import math
from datetime import datetime

startTime = datetime.now()

def isPrime(integer):
    if integer == 2 : return True
    if integer == 3 : return True
    if integer%2 == 0 : return False
    for n in range(3,int( math.ceil( math.sqrt( integer ) ) )) :
        if integer % n == 0 : return False
    return True

def isCircularPrime(integer) :
    intString = str(integer)                           # Convert integer into a string
    N = len(intString)

    for i in range(1, N) :
        intString = cyclicPermute(intString)
        if not isPrime(int(intString)) : return False
    return True

def cyclicPermute(string) :
    n = len(string)
    newString = string[n-1]
    for i in range(0,n-1) :
        newString = newString + string[i]
    return newString


nCircular = 0

for n in range(3,pow(10,6),2) :
    if isPrime(n) :
        if isCircularPrime(n) :
            nCircular = nCircular + 1
            print nCircular, "     ", n


print nCircular, "<- Number of circular primes under one million"
print datetime.now() - startTime



