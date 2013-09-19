/* Alex Velazquez
 * Start: Tue Dec 27 18:05:10 EST 2011
 * End  :
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

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		string S;
		cin >> S;
		int size = S.size();
		bool possible = true;
		for( int j=0; j<size; ++j )
		{
			if( S[j] == 'D' )
			{
				possible = false;
				break;
			}
		}
		if( possible ) 
			cout << "Possible" << endl;
		else
			cout << "You shall not pass!" << endl;
	}
}
