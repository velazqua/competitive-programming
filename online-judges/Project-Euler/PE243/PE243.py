def gcd (a, b):
  while b != 0:
    t = b
    b = a % t
    a = t
  return a

def R(n):
  c = 1.0
  for i in xrange(2, n):
    if gcd(n, i) == 1:
      c += 1
  return c/(n-1)

for i in xrange(2, 10000):
  if R(i) < 15499.0/94744:
    print i
    break
