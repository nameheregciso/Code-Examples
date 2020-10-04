import operator as op
from functools import reduce
 
def ncr(n, r, p):
    if r > n:
        return 0
    r = min(r, n-r)
    if r == 0:
        return 1
    numer = reduce(op.mul, range(n, n-r, -1))
    denom = reduce(op.mul, range(1, r+1))
    return (numer//denom)%p

n=int(input())
sum = 0
for i in range(n+1):
    print(ncr(n,i,10000000))

