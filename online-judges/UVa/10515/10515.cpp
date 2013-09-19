/* Alex Velazquez
 * Start: Tue Aug 28 00:07:40 EDT 2012
 * End  : Tue Aug 28 00:55:34 EDT 2012
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	string m, n;
	while( cin >> m >> n )
	{
		if( !m.compare( "0" ) && !n.compare( "0" ) )
			break;
		
		int sizeM = SZ(m);
		int M = m[sizeM-1]-48;
		int sizeN = SZ(n);
		int lastDigitN = n[sizeN-1]-48;
		#if DEBUG
			cout << "m: " << m << ". sizeM: " << sizeM << ". M: " << M << endl;
			cout << "n: " << n << ". sizeN: " << sizeN << ". N: " << lastDigitN << endl;
		#endif
		if( sizeN == 1 && lastDigitN == 0 )
			cout << 1 << endl;
		else if( M == 0 || M == 1 || M == 5 || M == 6 )
			cout << M << endl;
		else
		{
			int secondLastDigitN = ( sizeN > 1) ? n[sizeN-2]-48: 0; 
			int nModFour = (2*(secondLastDigitN%4)+lastDigitN)%4;
			if( M == 2 )
			{
				int arr[] = {6,2,4,8};
				cout << arr[nModFour] << endl;
			}
			else if( M == 3 )
			{
				int arr[] = {1,3,9,7};
				cout << arr[nModFour] << endl;
			}
			else if( M == 4 )
			{
				if( lastDigitN % 2 == 0 )
					cout << 6 << endl;
				else 
					cout << 4 << endl;
			}
			else if( M == 7 ) 
			{
				int arr[] = {1,7,9,3};
				cout << arr[nModFour] << endl;	
			}
			else if( M == 8 )
			{
				int arr[] = {6,8,4,2};
				cout << arr[nModFour] << endl;	
			}
			else if( M == 9 )
			{
				if( lastDigitN % 2 == 0 )
					cout << 1 << endl;
				else 
					cout << 9 << endl;			
			}
		}
	}

}
