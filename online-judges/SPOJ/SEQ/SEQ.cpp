/* Alex Velazquez
 * Start: November 16, 2011 @ 09:46PM
 * End  : November 16, 2011 @ ?????PM
*/

#include <iostream>
#include <map>
#include <vector>

#define DEBUG 1

using namespace std;

int f(	map<int,int> &a, 
		vector<int>  &b,
		vector<int>  &c,
		int &n,
		int &k,
		int  i )
{
	if( a[i] == -1 ) // key wasn't found. compute it!
	{
		cout << i << " " << k << endl;
		if( i > k )
		{
			#if DEBUG
				cout << "a[" << i << "] = ";
			#endif
			for( int p=0; p<k; ++p )
			{
				a[i] += (c[p] * f( a, b, c, n, k, i-(p+1)))%1000000000;
				#if DEBUG
					cout << c[p] << " * " << a[i-1] << " + ";
				#endif
			}
			#if DEBUG
				cout << endl;			
			#endif
			return a[n];
		}
		else
		{
			a[i] = b[i-1];
			return a[i];
		}
	}
	else
	{
		#if DEBUG
			cout << "a[i] was already computed: " << a[i] << endl;
		#endif
		return a[i];
	}
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int k, n;
		cin >> k;
		vector<int> b, c;
		map<int,int> a;
		for( int j=0; j<k; ++j )
		{
			cin >> n;
			b.push_back( n );
		}
		for( int j=0; j<k; ++j )
		{
			cin >> n;
			c.push_back( n );
		}
		cin >> n;
		#if DEBUG
			for( int j=0; j<k; ++j )
			{
				cout << "b[" << j << "] = " << b[j];
				cout << ". c[" << j << "] = " << c[j] << endl;
			}
			cout << endl;
			cout << "k: " << k << " " << "n: " << n << endl;
		#endif
		for( int i=1; i<=n )
		a[n] = f( a, b, c, n, k, n );
		cout << a[n] << endl;
	}
}
