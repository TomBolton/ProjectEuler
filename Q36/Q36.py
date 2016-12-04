# Project Euler Question 36

import math
from datetime import datetime

startTime = datetime.now()

def isPalindromic( string ) :
    reverseString = string[::-1]
    if string == reverseString : return True
    return False

def base10ToBase2( integer ) :
    integer = float(integer)
    n = math.floor( math.log(integer,2.0) )
    string = str(1)                  # Most left hand digit of base-2 number will always be 1
    integer = integer - pow(2,n)
    for i in range(int(n-1),-1,-1) :
        if integer/pow(2,i) >= 1 :
            string = string + str(1)
            integer = integer - pow(2,i)
        else :
            string = string + str(0)
    return string


sum = 0
for i in range(1,pow(10,6)) :
    string1 = str(i)
    string2 = base10ToBase2(i)
    if isPalindromic( string1 ) and isPalindromic( string2 ) :
        print string1, "   ", string2
        sum = sum + i
print sum

