# Project Euler Question 59

import collections

def intToBinary( integer ) :
    binStr = bin( integer )[2:]    # First two digits are '0b', so exclude them.
    if len( binStr ) < 8 :                  # Pad with zeros if less than 8 bits long.
        for i in range(0,8-len(binStr)) :
            binStr = '0' + binStr
    return binStr

def makeStringFromList( list ) :
    string = list[0]
    for i in range(1,len(list)) :
        string = string + list[i]
    return string


def XOR( intStr, key ) :           # Exclusive disjunction algorithm.
    integer = int(intStr)
    bin = intToBinary( integer )
    binKey = intToBinary( key )
    newBin = ['0']*8
    for i in range(0,8) :
        if bin[i] == binKey[i] : newBin[i] = '0'
        if bin[i] != binKey[i] : newBin[i] = '1'
    newBin = makeStringFromList( newBin )
    return int(newBin,2)

def unEncrypt( encryptedValues, keys ) :
    length = len( encryptedValues)
    unEncryptedValues = [0]*length
    for i in range( 0, length, 3) :
        unEncryptedValues[i] = str( unichr( XOR( encryptedValues[i], keys[0] ) ) )
    for j in range( 1, length, 3) :
        unEncryptedValues[j] = str( unichr( XOR( encryptedValues[j], keys[1] ) ) )
    for k in range( 2, length, 3) :
        unEncryptedValues[k] = str( unichr( XOR( encryptedValues[k], keys[2] ) ) )
    return unEncryptedValues

# Open the file of encrypted ASCII values.
file  = open("p059_cipher.txt", mode = "r")
for line in file :
    encryptedValues = line.split(",")

# Loop through all combinations of three lower case letters. This corresponds to
# looping through all ASCII values of 97-122.
for key1 in range(97,123) :
    for key2 in range(97,123) :
        for key3 in range(97,123) :
            keys = [key1, key2, key3]
            string = makeStringFromList( unEncrypt( encryptedValues, keys ) )
            letter = collections.Counter(string).most_common(1)[0]
            letter = letter[0]
            if 'the' in string : print key1, key2, key3, string

# The above loop prints out the unencrypred ASCII codes that contain the combination 'the',
# which is the most common word in the english language. You can then see which
# combination of key1, key2 and key3 works. Use that combo below (103, 111 100). Loop through
# all the characters of this string and sum the ASCII values.
key1 = 103; key2 = 111; key3 = 100

string = makeStringFromList( unEncrypt( encryptedValues, [key1,key2,key3] ) )
sum = 0
for c in string :
    sum = sum + ord(c)

print "Sum of unencrypted ASCII values: ", sum





