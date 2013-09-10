from math import *
def NthFib( k ):
	return floor((((1+sqrt(5))/2)**k)/sqrt(5)+0.5) 

def nineDig( n ):
	if( n/100000000000 == 0 ):
		return n
	else:
		return nineDig( n/10 )	

def power9Dig( base, exponent ):
	t = 1
	for i in xrange(0,exponent):
		t *= base
		t = nineDig(t)
	return t

def NthFibM( k ):
	return floor((power9Dig(((1+sqrt(5))/2),k))/sqrt(5)+0.5)  
		
fibs =[0,1,1]
mfibs=[0,1,1]
limit = 1000
for i in xrange(3,limit):
	fibs.append(fibs[i-1]+fibs[i-2])
	mfibs.append((mfibs[i-1]%1000000000+mfibs[i-2]%1000000000)%1000000000)

#this works
#for i in xrange(0,len(fibs)):
#	if fibs[i]%1000000000 != mfibs[i]:
#		print i

print power9Dig(((1+sqrt(5))/2),5)
