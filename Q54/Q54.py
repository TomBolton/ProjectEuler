# Project Euler Question 54

import math

def replaceLettersAndSort( hand ) :          # Replace Queen with 12 and King with 13, etc
    for i, item in enumerate( hand ) :
        if item[0] == '2': hand[i] = '02' + item[1]
        if item[0] == '3': hand[i] = '03' + item[1]
        if item[0] == '4': hand[i] = '04' + item[1]
        if item[0] == '5': hand[i] = '05' + item[1]
        if item[0] == '6': hand[i] = '06' + item[1]
        if item[0] == '7' : hand[i] = '07' + item[1]
        if item[0] == '8' : hand[i] = '08' + item[1]
        if item[0] == '9' : hand[i] = '09' + item[1]
        if item[0] == 'T' : hand[i] = '10' + item[1]
        if item[0] == 'J' : hand[i] = '11' + item[1]
        if item[0] == 'Q' : hand[i] = '12' + item[1]
        if item[0] == 'K' : hand[i] = '13' + item[1]
        if item[0] == 'A' : hand[i] = '14' + item[1]
    hand.sort()
    return hand

def isFlush( hand ) :       # Test hand for a flush ( all five have the same suit )
    card1 = hand[0]
    card2 = hand[1]
    card3 = hand[2]
    card4 = hand[3]
    card5 = hand[4]
    if card1[2] == card2[2] and card1[2] == card3[2] and card1[2] == card4[2] and card1[2] == card5[2] :
        return True
    return False

def isStraight( hand ) :    # Test hand for a straight ( five consecutive values )
    n1 = int( hand[0][0:2] )
    n2 = int( hand[1][0:2] )
    n3 = int( hand[2][0:2] )
    n4 = int( hand[3][0:2] )
    n5 = int( hand[4][0:2] )
    if n1+1 == n2 and n2+1 == n3 and n3+1 == n4 and n4+1 == n5 :
        return True
    return False

def isFourOfAKind( hand ) :     # Test hand for four of a kind
    list = [ int(hand[0][0:2]), int(hand[1][0:2]), int(hand[2][0:2]), int(hand[3][0:2]), int(hand[4][0:2]) ]
    if list.count( list[0] ) == 4 : return True
    if list.count( list[1] ) == 4 : return True
    return False

def isThreeOfAKind( hand ) :     # Test hand for three of a kind
    list = [ int(hand[0][0:2]), int(hand[1][0:2]), int(hand[2][0:2]), int(hand[3][0:2]), int(hand[4][0:2]) ]
    if list.count( list[0] ) == 3 : return True
    if list.count( list[1] ) == 3 : return True
    if list.count( list[2] ) == 3 : return True
    return False

def isPair( hand ) :             # Test hand for a pair
    list = [int(hand[0][0:2]), int(hand[1][0:2]), int(hand[2][0:2]), int(hand[3][0:2]), int(hand[4][0:2])]
    if list.count(list[0]) == 2: return True
    if list.count(list[1]) == 2: return True
    if list.count(list[2]) == 2: return True
    if list.count(list[3]) == 2: return True
    return False

def isTwoPair( hand ) :          # Test hand for two pairs
    list = [int(hand[0][0:2]), int(hand[1][0:2]), int(hand[2][0:2]), int(hand[3][0:2]), int(hand[4][0:2])]
    N = 0
    for i, item in enumerate( list ) :
        if list.count( item ) == 2 : N += 1
    if N == 4 : return True
    return False

def highestCard( hand1, hand2 ) :
    list1 = [int(hand1[0][0:2]), int(hand1[1][0:2]), int(hand1[2][0:2]), int(hand1[3][0:2]), int(hand1[4][0:2])]
    list2 = [int(hand2[0][0:2]), int(hand2[1][0:2]), int(hand2[2][0:2]), int(hand2[3][0:2]), int(hand2[4][0:2])]

    for i in range(4,-1,-1) :
        if list1[i] > list2[i] : return 1
        elif list1[i] < list2[i] : return 2

def highestCardTwo( hand1, hand2 ) :
    list1 = [int(hand1[0][0:2]), int(hand1[1][0:2]), int(hand1[2][0:2]), int(hand1[3][0:2]), int(hand1[4][0:2])]
    list2 = [int(hand2[0][0:2]), int(hand2[1][0:2]), int(hand2[2][0:2]), int(hand2[3][0:2]), int(hand2[4][0:2])]

    for i, item in enumerate( list1 ) :
        if list1.count( item ) > 1 : d1 = item
    for i, item in enumerate( list2 ) :
        if list2.count( item ) > 1 : d2 = item
    if d1>d2 : return 1
    if d1<d2 : return 2
    return highestCard(hand1,hand2)



def compareHands( hand1, hand2 ) :
    # First test for straight flush
    if isStraight( hand1 ) and not isStraight( hand2 ) :
        if isFlush( hand1 ) and not isFlush( hand2 ) : return 1
    if isStraight(hand2) and not isStraight(hand1) :
        if isFlush(hand2) and not isFlush(hand1) : return 2
    if isStraight(hand2) and isStraight(hand1) :
        if isFlush(hand2) and isFlush(hand1) :
            return highestCard( hand1, hand2 )

    # Test for four of a kind
    if isFourOfAKind( hand1 ) and not isFourOfAKind( hand2 ) : return 1
    if isFourOfAKind(hand2) and not isFourOfAKind(hand1) : return 2
    if isFourOfAKind(hand2) and isFourOfAKind(hand1):
        return highestCardTwo( hand1, hand2 )

    # Test for a full house
    if isThreeOfAKind( hand1 ) and not isThreeOfAKind( hand2 ) :
        if isPair( hand1) and not isPair( hand2 ) :   return 1
    if isThreeOfAKind(hand2) and not isThreeOfAKind(hand1):
        if isPair(hand2) and not isPair(hand1):  return 2
    if isThreeOfAKind(hand2) and isThreeOfAKind(hand1):
        if isPair(hand2) and isPair(hand1):
            return highestCardTwo( hand1, hand2 )

    # Test for a flush
    if isFlush( hand1 ) and not isFlush( hand2 ) : return 1
    if isFlush(hand2) and not isFlush(hand1): return 2
    if isFlush(hand2) and isFlush(hand1):
        return highestCard( hand1, hand2 )

    # Test for a straight
    if isStraight( hand1 ) and not isStraight( hand2 ) : return 1
    if isStraight(hand2) and not isStraight(hand1): return 2
    if isStraight(hand2) and isStraight(hand1):
        return highestCard( hand1, hand2 )

    # Test for three of a kind
    if isThreeOfAKind( hand1 ) and not isThreeOfAKind( hand2 ) : return 1
    if isThreeOfAKind(hand2) and not isThreeOfAKind(hand1): return 2
    if isThreeOfAKind(hand2) and isThreeOfAKind(hand1):
        return highestCardTwo( hand1, hand2 )

    # Test for two pairs
    if isTwoPair( hand1 ) and not isTwoPair( hand2 ) : return 1
    if isTwoPair(hand2) and not isTwoPair(hand1): return 2
    if isTwoPair(hand2) and isTwoPair(hand1):
        return highestCardTwo( hand1, hand2 )

    # Test for a pair
    if isPair( hand1 ) and not isPair( hand2 ) : return 1
    if isPair(hand2) and not isPair(hand1): return 2
    if isPair(hand2) and isPair(hand1):
        return highestCardTwo( hand1, hand2 )

    return highestCard( hand1, hand2 )







# Read in the data from the file
file = open('p054_poker.txt','r')
nLines = 0

# Keep track of how many hands each player has won
n1 = 0; n2 = 0

# Loop through all lines of the file and extract each players hand
for lines in file :
    hand1 = [ lines[0:2], lines[3:5], lines[6:8], lines[9:11], lines[12:14] ]         # The hand of player one
    hand2 = [ lines[15:17], lines[18:20], lines[21:23], lines[24:26], lines[27:29] ]  # The hand of player two

    hand1 = replaceLettersAndSort( hand1 )
    hand2 = replaceLettersAndSort( hand2 )

    testValue = compareHands( hand1, hand2 )
    if testValue == 1 : n1 += 1
    if testValue == 2 : n2 += 1

    nLines += 1
    print nLines

print n1,n2

