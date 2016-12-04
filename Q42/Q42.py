# Project Euler Question 42

import math

def isTriangular( integer ) :
    n = - 0.5 + math.sqrt( 2*integer + 0.25 )
    if n%1 == 0 : return True
    return False

f = open("p042_words.txt","r")      # Open text file
for line in f :
    words = line.split(",")         # All the words are on the first line, separated by commas
nWords = len(words)                 # Get the number of words

nTri = 0
for n in range(0,nWords) :          # Loop through each word
    letterSum = 0
    currentWord = words[n]
    currentWord = currentWord[1:len(currentWord)-1]   # Remove first and last characters (which are ")
    for i in range(0,len(currentWord)) :
        letterSum = letterSum + ord( currentWord[i] ) - 64    # Sum the value of each letter
    if isTriangular( letterSum ) :
        nTri = nTri + 1
        print currentWord, letterSum, nTri

