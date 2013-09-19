/* Alex Velazquez
 * Start: October 29, 2011 @ 01:21AM
 * End  : October 29, 2011 @ ???????
*/

#include <iostream>

using namespace std;

int main ()
{
	string s;
	int numCase = 1;
	while( cin >> s )
	{
		int size = s.size();
		int M = 0;
		int c = 0;
		for( int i=0; i<size; ++i )
		{
			if( 	 s[i] == '1' && M%2==0 )
			{
				++c;
				++M;
			}
			else if( s[i] == '1' && M%2==1 )
			{
				// do nothing
			}
			else if( s[i] == '0' && M%2==0 )
			{
				// do nothing
			}
			else if( s[i] == '0' && M%2==1 )
			{
				++M;
				++c;
			}
		}
		cout << "Game #" << numCase++ << ": " << c << endl;
	}
}
