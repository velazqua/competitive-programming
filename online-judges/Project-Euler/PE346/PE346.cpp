/* Name: Alex Velazquez
 * Start Date: September 05, 2011 @ 04:56PM
 * End Date:   ???
 * Purpose: To solve the Project Euler problem #346
 * Link: http://projecteuler.net/index.php?section=problems&id=346
 * */

#include <iostream>
#include <cmath>
#include <map>

using namespace std;

typedef unsigned long long ULL;

ULL power (ULL base, int exponent)
{
	ULL s=(ULL)1;
	for (int i=0;i<exponent;++i)
		s *= base;
	return s;
}

// converts a number composed of n 1's into base 10 number
ULL convertToDecimal (int n, int base)
{
	ULL s = 1;
	for (int i=1;i<n;++i)
		s += power(base,i);
	return s;
}

string repunit (int n)
{
	string t;
	for (int i=0;i<n;++i)
		t += "1";
	return t;
}

int main ()
{
	map<ULL,int> strong_repunits;
	// loop through number of 1s
	for (int i=2;i<40;++i)
	{
		// loop through number bases
		for (int j=2;j<500000;++j)
		{
			//cout << repunit(i) << "_" << j << " = " << convertToDecimal(i,j) << endl;
			++strong_repunits[convertToDecimal(i,j)];
		}
	}
	ULL c=1ULL;
	int k=12;
	for (map<ULL,int>::iterator it = strong_repunits.begin();it!=strong_repunits.end();++it)
	{
		if (it->second > 1 && it->first < power(10,k)){
			cout << it->first << " => " << it->second << endl;
			c += it->first;
		}
	}
	cout << c << endl;
}
