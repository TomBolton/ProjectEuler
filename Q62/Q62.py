# Project Euler Question 62

def sortDigits( cube ) :       # Convert to a list of characters and sort from low to high value.
    charList = []
    for c in str( cube ) :
        charList.append( c )
    charList.sort()             # Sort list from low to high.
    newInt = charList[0]
    for i in range(1,len(charList)) :
        newInt = newInt + charList[i]
    newInt = int( newInt )            # Make new int from sorted characters.
    return newInt

# If a cube is a permutation of another cube, then it will have the same
# sorted digits generated from the sortedDigits function above. Therefore
# count the number of cubes in the list which have the same sorted digits.
def countCubePermutations( cube, cubeList ) :
    N = 0
    cubeKey = sortDigits( cube )
    for i in range(0,len(cubeList)) :
        sortedDigits = sortDigits( cubeList[i] )
        if cubeKey == sortedDigits and len(str(cube)) == len(str(cubeList[i])):
            N += 1
    return N

# Make a list of the first 20,000 cubes and store them
# in a list to use later.
cubeList = []
for n in range(1,20000) :
    cubeList.append( n**3 )

# Loop through each cube in the list and count how many cubes
# can be made from its permutations.
n = 0
while countCubePermutations( cubeList[n], cubeList ) < 5 :
    print n
    n += 1
print n+1, (n+1)**3

