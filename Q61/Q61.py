# Project Euler Question 61

import math
import itertools

# For any 4 digit number, if the 3rd digit is zero, then this will produce a three digit number
# if using the last two digits to make a new 4 digit number. Therefore do not loop through
# numbers with zero as the third digit.

def genTriangular( n = 45 ) :           # 45 produces the first triangular number larger than 1000
    while n*( n + 1 )/2 < 10000 :
        if str( n*( n + 1 )/2 )[2] != '0' : yield n*( n + 1 )/2
        n += 1

def genSquare( n = 32 ) :        # 32 produces the first square number larger than 1000
    while n*n < 10000 :
        if str( n*n )[2] != '0' : yield n*n
        n += 1

def genPentagonal( n = 26 ) :            # 26 produces the first pentagonal number larger than 1000
    while n*( 3*n - 1 )/2 < 10000 :
        if str( n*( 3*n -1 )/2 )[2] != '0' : yield n*( 3*n -1 )/2
        n += 1

def genHexagonal( n = 23 ) :          # 23 produces the first hexagonal number larger than 1000
    while n*( 2*n - 1 ) < 10000 :
        if str( n*( 2*n - 1 ) )[2] != '0' : yield n*( 2*n - 1 )
        n += 1

def genHeptagonal( n = 21 ) :           # 21 produces the first heptagonal number larger than 1000
    while n*( 5*n - 3 )/2 < 10000 :
        if str( n*( 5*n - 3 )/2 )[2] != '0' :yield n*( 5*n - 3 )/2
        n += 1

def genOctagonal( n = 19 ) :            # 19 produces the first octagonal number larger than 1000
    if __name__ == '__main__':
        while n*( 3*n -2 ) < 10000 :
            if str( n*( 3*n -2 ) )[2] != '0' :yield n*( 3*n -2 )
            n += 1

def isSixCyclic( n1, n2, n3, n4, n5, n6 ) :       # Test whether the six numbers form a six-cyclic ordered set
    n1 = str(n1)
    n2 = str(n2)
    n3 = str(n3)
    n4 = str(n4)
    n5 = str(n5)
    n6 = str(n6)

    for s in itertools.permutations([ n1, n2, n3, n4, n5, n6 ]) :
        if isComboCyclic( s ) : return True
    return False

def isComboCyclic( list ) :
    if list[0][0:2] == list[5][2:] :
        if list[0][2:] == list[1][0:2] :
            if list[1][2:] == list[2][0:2] :
                if list[2][2:] == list[3][0:2] :
                    if list[3][2:] == list[4][0:2] :
                        if list[4][2:] == list[5][0:2] :
                            print list
                            return True
    return False




# The method for this question is to simply loop through all combinations of six 4-digit
# numbers; the six numbers comprise of a triangular, square, pentagonal, hexagonal, heptagonal
# and octagonal numbers. Each combo is then tested to see if it is an ordered six-cyclic set.
for t in genTriangular() :
    for s in genSquare() :




