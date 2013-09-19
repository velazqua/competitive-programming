def numDigits (n):
    if n/10==0:
        return 1
    else:
        return 1+numDigits(n/10)
n = 1
for i in xrange(1,50):
    n*=i
    print i, numDigits(n)