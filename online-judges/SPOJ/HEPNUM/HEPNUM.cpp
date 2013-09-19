/* Alex Velazquez
 * Start: November 23, 2011 @ 08:47PM
 * End  : November 23, 2011 @ 09:01PM
*/

#include <iostream>

#define DEBUG 0

using namespace std;

int main ()
{
	string A, B;
	while( cin >> A >> B )
	{
		#if DEBUG 
			cout << A << " " << B << endl;
		#endif
		if( A == "*" && B == "*" )
			break;
		int i = 0, j = 0; //compare indices
		int aSize = A.size(), bSize = B.size();
		// move indices to first char that is not a 0
		while( A[i] == '0' ) ++i;
		while( B[j] == '0' ) ++j;
		int aActual = aSize-i, bActual = bSize-j;
		#if DEBUG
			cout << "i: " << i << ". j: " << j << endl;
			cout << "aActual: " << aActual << ". bActual: " << bActual << endl;
		#endif
		if( aActual > bActual )
			cout << ">" << endl;
		else if( aActual < bActual )
			cout << "<" << endl;
		else
		{
			// same number of digits ...
			// compare rest of digits
			bool over = false;
			for( int k=0; k<aActual; ++k )
			{
				if( A[i+k] < B[j+k] )
				{
					cout << "<" << endl;
					over = true;
					break;
				}
				else if( A[i+k] > B[j+k] )
				{
					cout << ">" << endl;
					over = true;
					break;
				}
			}
			// all digits were equal!
			if( !over )
				cout << "=" << endl;
		}
	}
}
