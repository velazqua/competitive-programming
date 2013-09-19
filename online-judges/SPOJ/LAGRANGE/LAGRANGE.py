from math import *
N = 211
i = int(floor(sqrt(N)))
counter = 0
for a in xrange(0,i+1):
    for b in xrange(a,i+1):
        for c in xrange(b,i+1):
            for d in xrange(c,i+1):
                if a*a+b*b+c*c+d*d == N:
                    print str(a)+"^2 + "+str(b)+"^2 + "+str(c)+"^2 + "+str(d) + "^2"
                    counter += 1


print "Answer is : " + str(counter)