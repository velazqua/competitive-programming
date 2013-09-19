/* Alex Velazquez
 * Start: November 20, 2011 @ 09:50PM
 * End  : November 20, 2011 @ 11:21PM
*/

#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

#define DEBUG 0

typedef long long LL;

LL computeOnes( int N )
{
	LL X = 0LL;
	LL C = 1LL;
	for( int i=0; i<N; ++i )
	{
		X += C;
		C *= 10LL;
	}
	return X;
}

LL powerTen( int N )
{
	LL X = 1LL;
	if ( N == 0 ) return X;
	for( int i=0; i<N; ++i )
		X *= 10LL;
	return X;
}

LL toDecimal( string s )
{
	LL X = 0LL;
	int size = s.size();
	int j = 0;
	deque<int> zeroes;
	int t = 0;
	#if DEBUG
		cout << "s: " << s << endl;
	#endif
	for( int i=size-2; i>=0; i-=2 )
	{
		if( i == size-2 ) zeroes.push_front( 0 );
		else	
			zeroes.push_front( t );
		t += s[i]-48;
		#if DEBUG
			cout << "t: " << t << ". i: " <<  i << endl;
		#endif
	}
		
	for( int i=0; i<size; i+=2 )
	{
		X += ( s[i+1]-48 )*computeOnes( s[i]-48 )*powerTen( zeroes[j] );
		#if DEBUG
			cout << ( s[i+1]-48 ) << "*" << computeOnes( s[i]-48 );
			cout << "*" << powerTen( zeroes[j] ) << endl; 
		#endif
		++j;
	}
	return X;
}

string toRunLength( string S )
{
	int size = S.size();
	if( size == 1 )
		return "1"+S;
	char prev = S[0];
	string result = "";
	int num = 1;
	for( int i=0; i<size; ++i )
	{
		//cout << "prev: " << prev << ". S[" << i<< "]: " << S[i] << ". num: " << num << endl;
		if( i == size-1 )
		{
			stringstream out;
			out << num;
			//cout << "num: " << out.str() << endl;
			out << S[i];
			//cout << "prev: " << out.str() << endl;
			result += out.str();
			prev = S[i];
			num = 1;
		}
		else
		{
			if( S[i] != S[i+1] || num == 9 )
			{
				stringstream out;
				out << num;
				//cout << "num: " << out.str() << endl;
				out << S[i];
				//cout << "prev: " << out.str() << endl;
				result += out.str();
				prev = S[i];
				num = 1;
			}
			else
				++num;
		}
	}
	return result;
}

int main ()
{
	string num1, num2;
	char op;
	while( cin >> num1 >> op >> num2 )
	{
		#if DEBUG
			cout << num1 << " " << num2 << endl;
			cout << toDecimal( num1 ) << " " << toDecimal( num2 )<< endl;
		#endif
		
		LL n1 = toDecimal( num1 );
		LL n2 = toDecimal( num2 );
		LL result;
		switch( op )
		{
			case '+':
			{
				result = n1+n2;
				break;
			}
			case '-':
			{
				result = n1-n2;
				break;
			}
			case '*':
			{
				result = n1*n2;
				break;
			}
			case '/':
			{
				result = n1/n2;
				break;
			}
		}
		cout << num1 << " " << op << " " << num2 << " = ";
		stringstream ss;
		ss << result;
		//cout << "result: " << ss.str() << endl;
		cout << toRunLength( ss.str() ) << endl;
		
	}
}
