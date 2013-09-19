def sumDigits( x ):
	if( x < 10 ):
		return x
	else:
		return x%10 + sumDigits( x/10 )
		
def S ( n ):
	t = 0
	for i in xrange( 0, n ):
		t += 10**i 
	return t*t
	
def SS( n ):
	s = []
	t = 0
	for i in xrange( 1, 19, 2 ):
		t += i
		s.append( t )
	s.append( 0 )
	print s
	p = 81
	return p * ( n/9 ) + s[n%9-1]

i = 10001
print SS( 1000000000000000000 )
