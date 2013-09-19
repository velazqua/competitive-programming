/* Alex Velazquez
 * Start: Sun Dec 11 03:58:50 EST 2011
 * End  : Sun Dec 11 04:57:11 EST 2011
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

int sumDigits( string S, int size )
{
	int summ = 0;
	for( int i=0; i<size; ++i )
	{
		summ += S[i]-'0';
	}
	return summ;
}

bool lastDigits( string S, int lastNdigits, int divBy, int size )
{
	int L = 0;
	int pow10 = 1;
	for( int i=0; i<lastNdigits; ++i )
	{
		L += (S[size-1-i]-'0')*pow10;
		pow10 *= 10;
	}
	if( L%divBy == 0 ) 	return true;
	else 				return false;
}

int main ()
{
	string number;
	while( cin >> number )
	{
		int size = number.size();
		int div = 0;
		int d = sumDigits( number, size );
		vector<int> seq(6);
		seq[0] = 1; seq[1] = 3; seq[2] = 2;
		seq[3] = 6; seq[4] = 4; seq[5] = 5;
		string revNumber = number;
		reverse( revNumber.begin(), revNumber.end() );
		int summ = 0;
		for( int j=0; j<size; ++j )
			summ += (revNumber[j]-'0')*seq[j%6];
		vector<int> nums(10);
		for( int i=0; i<size; ++i )
		{
			++nums[number[i]-'0'];
		}
		div += nums[1];
		for( int i=2; i<10; ++i )
		{
			bool divisible = false;
			if( nums[i] == 0 )
				continue;
			switch( i )
			{
				case 2:
				{
					if( number[size-1] == '0' ||
						number[size-1] == '2' ||
						number[size-1] == '4' ||
						number[size-1] == '6' ||
						number[size-1] == '8' )
						divisible = true;
					break;
				}
				case 3:
				{
					if( d%3 == 0 )
						divisible = true;
					break;					
				}
				case 4:
				{
					if( lastDigits( number, 2, 4, size ) )
						divisible = true;
					break;
				}
				case 5:
				{
					if( number[size-1] == '0' || number[size-1] == '5' )
						divisible = true;
					break;
				}
				case 6:
				{
					if( (number[size-1] == '0' ||
						number[size-1] == '2' ||
						number[size-1] == '4' ||
						number[size-1] == '6' ||
						number[size-1] == '8' ) && ( d%3 == 0 ) )
						divisible = true;
					break;
				}
				case 7:
				{
					//cout << summ << endl;
					if( summ%7 == 0 )
					{
						divisible = true;
					}
					break;
				}
				case 8:
				{
					if( lastDigits( number, 3, 8, size ) )
						divisible = true;
					break;
				}
				case 9:
				{
					if( d%9 == 0 )
						divisible = true;
					break;
				}
			}				
			if( divisible )
				div += nums[i];
		}
		cout << div << endl;
	}
}
