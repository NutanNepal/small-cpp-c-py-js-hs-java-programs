from operator import mul    # or mul=lambda x,y:x*y
from fractions import Fraction
from functools import reduce

def nCk(n,k): 
  return int( reduce(mul, (Fraction(n-i, i+1) for i in range(k)), 1) )

def triangle(n):
    output = []
    for i in range (n):
        output += [nCk(i,k) for k in range(i+1)]
    
    return output

print(triangle(7))