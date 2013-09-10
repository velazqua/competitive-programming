/* Name: Alex Velazquez
 * Start Date: September 10, 2011 @ 10:07PM
 * End Date:   ???
 * Purpose: To solve the Project Euler problem #94
 * Link: http://projecteuler.net/index.php?section=problems&id=94
 * */

#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ULL;

ULL squareRoot (ULL x)
{
	ULL n = x/2, lastN;
	while (1)
	{
		lastN = n;
		n = 0.5*(n+x/n);
		if (n >= lastN)
			return lastN;
	}
	return x;
}

int main ()
{
	// contains all square numbers
	// 2.23*10^8 => 250000000 (maximum upper limit to populate the isSquares map)
	/*
	const int maxSquare = 25000000;
	map<ULL,bool> isSquare;
	for (int i=1;i<maxSquare;++i)
		isSquare[(ULL)i*i] = true;
	cout << "calculated all squares" << endl;
	*/
	const int maxA = 333333333;
	ULL answer=0ULL;
	ULL x, y, z;
	ULL isqrt;
	bool M,L;
	for (int a=5;a<maxA;++a)
	{
		M=false; L=false;
		x = (a-1)*((ULL)a-1);
		y = 4*(ULL)a*a;
		if (y > x)
			z = x*(y-x);
		else
			z = x*(x-y);
		if (z % 16 == 0) // if its divisible by 16, check if its a square
		{
			isqrt=squareRoot(z/16);
			if (isqrt*isqrt == z/16)
			{
				cout << "a: " << a << ". b: " << a-1;
				cout << ". x: " << x << ". y: " << y;
				cout << ". isqrt: " << isqrt << ". isqrt^2: " << isqrt*isqrt;
				cout << ". z/16: " << z/16 << endl;
				answer += 2*a+a-1;
				L=true;
			}
		}	
		x = (a+1)*((ULL)a+1);
		if (y > x)
			z = x*(y-x);
		else
			z = x*(x-y);
		if (z % 16 == 0) // if its divisible by 16, check if its a square
		{
			isqrt=squareRoot(z/16);
			if (isqrt*isqrt == z/16)
			{
				cout << "a: " << a << ". b: " << a+1;
				cout << ". x: " << x << ". y: " << y;
				cout << ". isqrt: " << isqrt << ". isqrt^2: " << isqrt*isqrt;
				cout << ". z/16: " << z/16 << endl;
				answer += 2*a+a+1;
				M=true;
			}
		}
		if (M&&L) answer -= 6*a;
	}
	cout << "Answer: " << answer << endl;

	
}
