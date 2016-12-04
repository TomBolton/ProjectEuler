# Project Euler Question 53

import math
import itertools

def makeStringFromList( s ) :           # Itertool outputs normally produce a list of individual
    string = s[0]                       # characters, instead of a string
    for i in range(1,len(s)) :
        if s[i] in string : return []   # Return [] is number is already present in string. This prevents repitition.
        string = string + s[i]
    return string

def isUnique( permStr, list ) :                         # Test if this permutation of digits has occured before
    for s in itertools.permutations( permStr ) :        # ( we only want unique combinations of digits )
        sString = makeStringFromList( s )
        if sString in list : return False
    return True


def calcUniqueCombos( string, r ) :                         # Calculate the number of unique permutations of
    list  = []                                              # choosing r values from n choices
    for s in itertools.product( string, repeat = r) :
        permStr = makeStringFromList( s )
        if permStr == [] : continue
        if isUnique( permStr, list ) :
            list.append( permStr )
    return len(list)                        # 'List' stores all unique permutations, so its length
                                            # is the value of n choose r

def nChooseR( n, r ) :
    string = '1'
    for i in range(2,n+1) :                 # Make a string of '123...n'
        string = string + str(i)
    NcR = calcUniqueCombos( string, r )
    return NcR


# Loop through all values of n and r and
N = 0
for n in range(1,101) :
    print n
    for r in range(1,n) :
        if nChooseR( n, r ) > 10**6 :
            N += 1
            print "nCr =", nChooseR( n, r ), " n =", n, " r =", r
