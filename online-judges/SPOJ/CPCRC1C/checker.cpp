#include <iostream>

using namespace std;

int sumDigits ( int x )
{
	if( x/10 == 0 ) // x is one digit
		return x;
	else
		return sumDigits( x/10 ) + x%10;
}

int main ()
{
	int total = 0;
	for (int i=100; i<124; ++i )
		total += sumDigits( i );
	cout << total << endl;
}	
