# Project Euler Question 40

import math

d1 = 1
d2 = 10
d3 = 100
d4 = 1000
d5 = 10000
d6 = 100000
d7 = 1000000

n = 1
digitSum = 0
digitProd = 1

while digitSum < d1+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n1 = 1
print digitSum, n-1, n1


while digitSum > d1 and digitSum < d2+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n2 = string[len(string)-(digitSum-d2)-1]
print digitSum, n-1, n2

while digitSum > d2 and digitSum < d3+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n3 = string[len(string)-(digitSum-d3)-1]
print digitSum, n-1, n3

while digitSum > d3 and digitSum < d4+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n4 = string[len(string)-(digitSum-d4)-1]
print digitSum, n-1, n4

while digitSum > d4 and digitSum < d5+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n5 = string[len(string)-(digitSum-d5)-1]
print digitSum, n-1, n5

while digitSum > d5 and digitSum < d6+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n6 = string[len(string)-(digitSum-d6)-1]
print digitSum, n-1, n6

while digitSum > d6 and digitSum < d7+1 :
    digitSum = digitSum + len(str(n))
    n = n + 1
string = str(n-1)
n7 = string[len(string)-(digitSum-d7)-1]
print digitSum, n-1, n7

print "Product of digits: ", int(n1)*int(n2)*int(n3)*int(n4)*int(n5)*int(n6)*int(n7)