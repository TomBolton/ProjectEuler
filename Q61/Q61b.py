# Project Euler Question 61 (attempt b)

import math


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

def isSquare( n ) :                                 # This function and the four below tests if a number 'n' is
    if math.sqrt( n ) % 1 == 0 : return True        # either square, pentagonal, hexagonal, heptagonal or octagonal.
    return False

def isPentagonal( n ) :
    if ((1 + math.sqrt( 24*n + 1 ) )/6) % 1 == 0 : return True
    return False

def isHexagonal( n ) :
    if ( ( 1 + math.sqrt( 8*n + 1 ) )/4 ) % 1 == 0 : return True
    return False

def isHeptagonal( n ) :
    if ( ( 3 + math.sqrt( 40*n + 9) )/10 ) % 1 == 0 : return True
    return False

def isOctagonal( n ) :
    if ( ( 1 + math.sqrt( 3*n + 1 ) )/3 ) % 1 == 0 : return True
    return False

def isPolyNumber( n ) :         # Test the number to see if its one of the above: square, pent, hex, hep or oct.
    if isSquare( n ) : return 4
    if isPentagonal( n ) : return 5
    if isHexagonal( n ) : return 6
    if isHeptagonal( n ) : return 7
    if isOctagonal( n ) : return 8
    return 0

def makeNewNumber( n ) :            # This generator makes a new four digit number from the last
    n = str(n)                      # two digits of the integer 'n'.
    digit1 = n[2]
    digit2 = n[3]
    string = '0123456789'
    for c1 in string :
        for c2 in string :
            newString = digit1 + digit2 + c1 + c2
            yield int( newString )

# Make lists of all the square, pentagonal, hexagonal, heptagonal and octagonal
# numbers between 1000 and 10000.
squList = []
penList = []
hexList = []
hepList = []
octList = []

for s in genSquare() : squList.append(s)
for p in genPentagonal() : penList.append(p)
for hx in genHexagonal() : hexList.append(hx)
for hp in genHeptagonal() : hepList.append(hp)
for o in genOctagonal() : octList.append(o)


N = [0]*5

# Loop through all triangular numbers and form a new four digit number using the last two
# digits as the first two digits of the new number. Loop through all possible 4 digit numbers
# and test if it's square, pent, hex, hep or oct.
for n1 in genTriangular() :                       # 1st number in cyclic set (which is triangular)
    list = [n1]
    if str(n1)[2] == '0' : continue

    for n2 in makeNewNumber( n1 ) :         # 2nd number in cyclic set
        if str(n2)[2] == '0': continue
        N[0] = isPolyNumber( n2 )
        if N[0] != 0 :

            for n3 in makeNewNumber( n2 ) :        # 3rd number in cyclic set
                if str(n3)[2] == '0': continue
                N[1] = isPolyNumber( n3 )
                if N[1] != 0 :

                    for n4 in makeNewNumber( n3 ) :        # 4th number in cyclic set
                        if str(n4)[2] == '0': continue
                        N[2] = isPolyNumber( n4 )
                        if N[2] != 0:

                            for n5 in makeNewNumber( n4 ) :         # 5th number in cyclic set
                                if str(n5)[2] == '0': continue
                                N[3] = isPolyNumber( n5 )
                                if N[3] != 0 :

                                    for n6 in makeNewNumber( n5 ) :         # 6th number in cyclic set
                                        if str(n6)[2] == '0': continue
                                        N[4] = isPolyNumber( n6 )
                                        if N[4] != 0 and str(n6)[2] == str(n1)[0] and str(n6)[3] == str(n1)[1] :
                                            if 4 in N and 5 in N and 6 in N and 7 in N and 8 in N :     # Make sure squ, pen, hex, hep and oct are represented.
                                                print "DONE!!", n1, n2, n3, n4, n5, n6
                                                print "Sum = ", n1+n2+n3+n4+n5+n6




