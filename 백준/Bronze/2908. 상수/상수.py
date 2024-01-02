import sys

import math

a,b=map(int, sys.stdin.readline().split())

global n, num1, num2, num3

def reverse(n):

    num3=math.floor(n/100) #백의 자리수

    num2=math.floor((n-100*num3)/10) #십의 자리수

    num1=n%10 #일의 자리수

   

    n=100*num1+10*num2+num3

    return n

if reverse(a)>reverse(b):

    print(reverse(a))

else: 

    print(reverse(b))