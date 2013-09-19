/* Alex Velazquez
 * Start: November 17, 2011 @ 07:21PM
 * End  : November 17, 2011 @ 07:34PM
*/

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int N, P;
		cin >> N >> P;
		int r;
		bool conditionI = true, conditionII = true, conditionIII = true;
		vector<int> counterI( P, 0 );
		vector<int> numSolvedProblems( N, 0 );
		for( int j=0; j<N; ++j )
		{
			for( int k=0; k<P; ++k )
			{
				cin >> r;
				if( r == 1 )
				{
					++counterI[k]; // count problem as solved
					++numSolvedProblems[j]; // 
				}
			}
		}
		for( int j=0; j<P; ++j )
			if( counterI[j] == 0 ) // problem has not been solved!
				conditionI = false;
		for( int j=0; j<N; ++j )
		{
			if( numSolvedProblems[j] == 0 ) // condition II not fulfilled
				conditionII = false;
			else if( numSolvedProblems[j] == P ) // condition III broken
				conditionIII = false;
		}
		int total = 0;
		if( conditionI ) 	total += 4;
		if( conditionII )	total += 2;
		if( conditionIII )	total += 1;
		cout << "Case " << i+1 << ": " << total << endl; 
	}
}
