# Project Euler Question 55

import math

def reverseString( string ) :
    newString = string[len(string) - 1]
    for i in range(len(string) - 2, -1, -1):
        newString = newString + string[i]
    return newString

def reverseAndAdd( integer ) :
    string = str( integer )
    revString = reverseString( string )
    return integer + int( revString )

def isPalindromic( integer ) :
    string = str( integer )
    revString = reverseString( string )
    if string == revString : return True
    return False

def isLychrel( integer ) :
    n = 0
    while n<50 :
        newInt = reverseAndAdd( integer )
        if isPalindromic( newInt ) :
            print n, newInt
            return False
        integer = newInt
        n += 1
    return True

# Loop through all numbers from 1 to 10000
nLychrel = 0
for n in range(1,10000) :
    if isLychrel( n ) : nLychrel += 1

print nLychrel