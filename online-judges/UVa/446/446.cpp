/* Alex Velazquez
 * Start: Sun Apr 22 13:34:46 EDT 2012
 * End  : Sun Apr 22 14:06:01 EDT 2012
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
#include <string>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

string toBinary( string HEX, map<char,string> &M )
{
	string A = "0";
	int size = HEX.size(); 
	if( size == 1 ) A += "00000000";
	if( size == 2 ) A += "0000"; 
	for( string::iterator it=HEX.begin(); it!=HEX.end(); ++it )
		A += M[*it];
	return A;
}

int toDecimal( string HEX, map<char,int> &M )
{
	int m = 1;
	int total = 0;
	for( string::reverse_iterator it=HEX.rbegin(); it!=HEX.rend(); ++it )
	{
		total += m*M[*it];
		m *= 16;
	}
	return total;
}

int main ()
{
	map<char,int> M;
	for( char c='0'; c <= '9'; ++c )
		M[c] = c-'0';
	for( char c='A'; c <= 'F'; ++c )
		M[c] = c-'A'+10;
	map<char,string> B;
	B['0'] = "0000";
	B['1'] = "0001"; B['2'] = "0010"; B['3'] = "0011";
	B['4'] = "0100"; B['5'] = "0101"; B['6'] = "0110";
	B['7'] = "0111"; B['8'] = "1000"; B['9'] = "1001";
	B['A'] = "1010"; B['B'] = "1011"; B['C'] = "1100";
	B['D'] = "1101"; B['E'] = "1110"; B['F'] = "1111";
	int T;
	cin >> T;
	REP( i, T )
	{
		string HEX1, HEX2;
		char op;
		cin >> HEX1 >> op >> HEX2;
		cout << toBinary( HEX1, B ) << " " << op << " " << toBinary( HEX2, B );
		cout << " = ";
		int DEC1 = toDecimal( HEX1, M );
		int DEC2 = toDecimal( HEX2, M );
		if( op == '+' )
			cout << DEC1+DEC2 << endl;
		else
			cout << DEC1-DEC2 << endl;
	}
}
