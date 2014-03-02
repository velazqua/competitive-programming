from math import *
r5 = sqrt(5)
p1 = (1 + r5)/2.0
p2 = (1 - r5)/2.0

def firstTenDigits (f):
  digits = int(log10(f))
  k = digits - 9
  return int(f/(10**k))

def NthFib (n):
  return firstTenDigits((p1**n)/r5)

def isPandigital (f):
  dp = [False] * 10
  for i in xrange(9):
    dig = f % 10
    f /= 10
    dp[dig] = True
  for i in xrange(1, 10):
    if dp[i] == False:
      return False
  return True

fibs =[0,1,1]
limit = 100000
for i in xrange(3,limit):
  fibs.append((fibs[i-1]+fibs[i-2])%10000000000)
  if isPandigital(fibs[i]):
    print i, fibs[i]
