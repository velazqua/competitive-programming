/* Alex Velazquez
 * Start: Fri May 11 20:18:06 EDT 2012
 * End  : Fri May 11 20:28:21 EDT 2012
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

int main ()
{
	string low_encrypt = "34567890-=ertyuiop[]dfghjkl;'cvbnm,./";
	string low_decrypt = "1234567890qwertyuiopasdfghjklzxcvbnm,";
	string upp_encrypt = "ERTYUIOP[]DFGHJKL;'CVBNM,./";
	string upp_decrypt = "QWERTYUIOPASDFGHJKLZXCVBNM,";
	map<char,char> M;
	REP( i, upp_encrypt.size() )
		M[upp_encrypt[i]] = upp_decrypt[i];
	REP( i, low_encrypt.size() )
		M[low_encrypt[i]] = low_decrypt[i];
	string word;
	getline( cin, word );
	REP( i, word.size() )
	{
		if( word[i] == ' ' )
			cout << ' ';
		else
			cout << M[word[i]];
	}
	cout << endl;
}
