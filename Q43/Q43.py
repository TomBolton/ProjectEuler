# Project Euler Question 43

import math
import itertools

string = "0123456789"

sum = 0

for s in itertools.permutations( string ) :
    if s[0] != 0 :                              # Ignore all permutations with a leading zero

        if ( int( s[1]+s[2]+s[3] ) )%2 == 0 :
            if ( int( s[2]+s[3]+s[4] ) )%3 == 0 :
                if ( int( s[3]+s[4]+s[5] ) )%5 == 0 :
                    if ( int( s[4]+s[5]+s[6] ) )%7 == 0 :
                        if( int( s[5]+s[6]+s[7] ) )%11 == 0 :
                            if( int( s[6]+s[7]+s[8] ) )%13 == 0 :
                                if( int( s[7]+s[8]+s[9] ) )%17 == 0 :
                                    sum = sum + int( s[0]+s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9] )
                                    print s
print sum