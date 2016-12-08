# Project Euler Question 58

import math

def isPrime( n ) :                  # Test if the integer 'n' is prime
    if n==2 : return True
    if n==3 : return True
    if n%2 == 0 : return False
    for i in range(3, int( math.ceil( math.sqrt( n ) ) + 1 ) ) :
        if n%i == 0 : return False
    return True

sideLength = 7              # Start from a spiral of side length 7
nPrimes = 8.0
nDiagonals = 13.0
primeRatio = nPrimes/nDiagonals
nNumbers = sideLength**2

while primeRatio > 0.1 :
    firstDiag = nNumbers + sideLength + 1     # Top right diagonal
    secondDiag = firstDiag + sideLength + 1    # Top left diagonal
    thirdDiag = secondDiag + sideLength + 1     # Bottom left diagonal
    fourthDiag = thirdDiag + sideLength + 1    # Bottom right diagonal

    if isPrime( firstDiag ) : nPrimes += 1
    if isPrime( secondDiag ) : nPrimes += 1
    if isPrime( thirdDiag ) : nPrimes += 1
    if isPrime( fourthDiag ) : nPrimes += 1

    nDiagonals += 4
    sideLength += 2
    nNumbers = sideLength**2
    primeRatio = float(nPrimes)/nDiagonals
    print nPrimes, primeRatio, sideLength


