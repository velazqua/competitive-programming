def p(a, b):
  t = 1
  for i in xrange(b):
    t *= a
  return t

def f(n):
  return sum([p(n,x) for x in xrange(0,11,2)])+sum([-1*p(n,x) for x in xrange(1,10,2)])

l = []
for i in xrange(1, 12):
  l.append(f(i))

letters = ['a','b','c','d','e','f','g','h','i','j','k','l']
print l
for i in xrange(2, 12):
  A = "A = ["
  B = "B = ["
  for n in xrange(1, i+1):
    for e in xrange(i-1, -1, -1):
      A += str(p(n,e)) + " "
    A += ";"
    B += str(l[n-1]) + ";"
  A += "]"
  B += "]"
  Q = "["
  for k in xrange(i-1, -1, -1):
    Q += str(i+1) + "^" + str(k) +";"
  Q += "]"
  print A + "; " + B + ";C = A \ B; sum(C .* " + Q + ")"

print 57154490053 + 23772343751 + 9071313571 + 3093310441 + 898165577 + 205015603 + 32740951 + 3092453 + 130813 + 1365 + 1
