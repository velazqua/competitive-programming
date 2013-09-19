def F1( a, b, n, M ):
	return (a**n + b*((1-a**n)/(1-n)))%M;

def F2( a, b, n, M ):
	return (((a**n)*(1-n-b)+b)/(1-n))%M;
#print F( 1, 1, 1, 10 );
print F1( 5, 4, 5, 3 );
print F1( 5, 2, 20, 30 );
print F1( 2, 1, 2, 5 );
print F2( 5, 4, 5, 3 );
print F2( 5, 2, 20, 30 );
print F( 2, 1, 2, 5 );
