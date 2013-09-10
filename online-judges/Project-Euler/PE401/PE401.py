def getDivisors (n):
  divs = []
  for i in xrange(1,n+1):
    if n%i == 0:
      divs.append(i)
  return divs

def sigma2 (n):
  divs = getDivisors(n)
  return sum([x*x for x in divs])

def SIGMA2 (n):
  return sum([sigma2(x) for x in xrange(1,n+1)])

def sumS (n):
  return n*(n+1)*(2*n+1)/6

def sumSR (a,b):
  return sumS(b)-sumS(a-1)

def binary_search (i, n, s, u):
  mid = (i+n)/2
  if i >= n:
    return i
  if u/mid == s and u/mid != u/(mid+1):
    return mid
  else:
    if u/mid == s:
      return binary_search(mid, n, s, u)
    else:
      return binary_search(i, mid, s, u)

def count (n):
  i = 1
  ans = 0
  while i <= n:
    if n/i == 1:
      #print "adding " + str(sumSR(i,n))
      ans += sumSR(i,n)
      return ans
    if n/i != n/(i+1):
      #print "adding " + str(n/i) + "*" + str(i*i)
      ans += (n/i)*(i*i)
      i += 1
    else:
      #do binary search
      j = binary_search(i,n,n/i,n)
      #print "adding " + str(n/i) + "*" + str(sumSR(i,j))
      ans += (n/i)*sumSR(i,j)
      i = j+1
    ans %= 1000000000
  return ans

"""
n = 1000
for i in xrange(1,n+1):
  print i, n/i
"""
#print binary_search(6,10,10/6,10)
n = 10**15
print count(n)%(10**9)

