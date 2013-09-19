/* Alex Velazquez
 * Start: Thu Mar 29 23:48:38 EDT 2012
 * End  : Fri Mar 30 00:18:17 EDT 2012
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int sumDigits( string num, int size )
{
	int summ = 0;
	REP( i, size )
		summ += num[i]-'0';
	return summ;
} 

bool isDivisible2( string num, int size )
{
	if( (num[size-1]-'0')%2 == 0 )
		return true;
	else 
		return false;
}

bool isDivisibleN( string num, int size, int N )
{
	if( sumDigits( num, size )%N == 0 )
		return true;
	else
		return false;
}

bool isDivisible4( string num, int size )
{
	if( size == 1 )
	{
		if( (num[0]-'0')%4 == 0 )
			return true;
	}
	else
	{
		if( ((num[size-2]-'0')*10+(num[size-1]-'0'))%4 == 0 )
			return true;
	}
	return false;
}

bool isDivisible( string num, int X )
{
	int size = num.size();
	
	if     ( X == 1 )
		return true;
	else if( X == 2 )
		return isDivisible2( num, size );
	else if( X == 3 )
		return isDivisibleN( num, size, 3 );
	else if( X == 4 )
		return isDivisible4( num, size );
	else if( X == 5 )
	{
		if( num[size-1] == '0' || num[size-1] == '5' )
			return true;
	}
	else if( X == 6 )
	{
		if( isDivisible2( num, size ) && isDivisibleN( num, size, 3 ) )
			return true;
	}
	else if( X == 7 )
	{
		int arr[] = {-2,-3,-1,2,3,1};
		int summ = 0;
		REP( i, size )
			summ += arr[i%6]*(num[i]-'0');
		if( summ%7 == 0 )
			return true;
	}
	else if( X == 8 )
	{
		if( size == 1 )
		{
			if( (num[0]-'0')%8 == 0 )
				return true;
		}
		else if( size == 2 )
		{
			if( ((num[0]-'0')*10+(num[1]-'0'))%8 == 0 )
				return true;
		}
		else
		{
			if( ((num[size-3]-'0')*100+(num[size-2]-'0')*10+(num[size-1]-'0'))%8 == 0 )
				return true;
		}
	}
	else if( X == 9 )
		return isDivisibleN( num, size, 9 );
	else if( X == 10 )
		return ( num[size-1] == '0' );
	else if( X == 11 )
	{
		int summ = 0;
		REP( i, size )
		{
			if( !( i%2 ) )
				summ += num[i]-'0';
			else
				summ -= num[i]-'0';
		}
		return ( summ%11 == 0 );
	}
	else
		if( isDivisibleN( num, size, 3 ) && isDivisible4( num, size ) )
			return true;
	return false;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		string num;
		cin >> num;
		int N;
		cin >> N;
		vector<int> nums( N );
		REP( j, N )
			cin >> nums[j];
		bool isWonderful = true;
		REP( j, N )
		{
			if( !isDivisible( num, nums[j] ) )
			{
				isWonderful = false;
				break;
			}
		}
		cout << num << " - " << (( isWonderful ) ? "Wonderful." : "Simple." ) << endl;
	}
}
