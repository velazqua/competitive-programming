/* Name: Alex Velazquez
 * Start Date: October 03, 2011 @ 01:06PM
 * End Date:   October 03, 2011 @ ???
 * Purpose: To solve the SPOJ problem ROBBERY2 - Robbery 2
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

ULL square_root (ULL S)
{
	ULL x = S/2;
	ULL nextX = x;
	while (1)
	{
		nextX = (x+S/x)/2;
		if (x == nextX)
			break;
		x = nextX;
	}
	return x;
}

int main ()
{
	int T;
	cin >> T;
	for (int i=0;i<T;++i)
	{
		int k;
		ULL n;
		cin >> n >> k;
		ULL x = (square_root(1ULL+8ULL*n)-1ULL)/2ULL;
		//cout << "x: " << x << endl;
		ULL vals[k];
		ULL l = x%(ULL)k;
		//cout << "l: " << l << endl;
		ULL d, extra, N;
		N = x/k;
		for (int j=0;j<k;++j)
		{
			if ((ULL)j < l)
			{
				d = 1ULL;
				extra = 0ULL;
			}
			else if ((ULL)j == l)
			{
				d = 0ULL;
				extra = n-x*(x+1ULL)/2ULL;
				//cout << "extra: " << extra << endl;
			}
			else
			{
				d = 0ULL;
				extra = 0ULL;
			}
			vals[j] = (N+d)*((2*((ULL)j+1ULL)+((ULL)N+d-1ULL)*k))/2ULL+extra;
			cout << ((j!=0)?" ":"");
			cout << vals[j];
		}
		cout << endl;
	}
}
