/* Alex Velazquez
 * Start: Tue Jan 17 22:51:55 EST 2012
 * End  : Wed Jan 18 00:51:50 EST 2012
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

typedef long long int LL;

using namespace std;

int sumDigits( int N )
{
	int summ = 0;
	while( N >= 10 )
	{
		summ += N%10;
		N /= 10;
	}
	summ += N;
	return summ;
}

int main ()
{
	int N;
	cin >> N;
	REP( i, N )
	{
		string num="";
		string t;
		REP( j, 4 )
		{
			cin >> t;
			num += t;
		}
		int doubled = 0;
		int notDoubled = 0;
		REP( j, 16 )
		{
			int digit = num[j]-'0';
			//cout << "digit: " << digit << " ";
			if( j%2 == 0 )
			{
				doubled += sumDigits(2*digit);
			}
			else
			{
				notDoubled += digit;
			}
		}
		
		//cout << doubled << "+ " << notDoubled << " = " << doubled+notDoubled << endl;
		if( (doubled+notDoubled)%10 != 0 )
			cout << "Invalid" << endl;
		else
			cout << "Valid" << endl;
		
	}
}
