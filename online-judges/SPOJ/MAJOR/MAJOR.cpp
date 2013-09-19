/* Alex Velazquez
 * Start: October 31, 2011 @ 09:25PM
 * End  : October 31, 2011 @ ???????
*/

#include <iostream>
#include <set>
#include <cstdio>
#include <iterator> 
#include <utility>

using namespace std;

struct Major {
	int num;
	int occur;
	Major( int n ) : num( n ), occur( 0 ) {}
	Major( int n, int o ) : num( n ), occur( o ) {}
};

bool operator < ( Major const& A, Major const& B )
{
	if( A.occur > B.occur ) 
		return true;
	else if( A.occur < B.occur )
		return false;
	else
	{
		if( A.num > B.num )
			return true;
		else
			return false;
	}
}

int main ()
{
	int T;
	scanf( "%d\n", &T );
	for( int i=0; i<T; ++i )
	{
		int N, x;
		scanf( "%d\n", &N );
		set<Major> M;
		set<int> nums;
		cout << "Case " << i+1 << endl;
		for( int j=0; j<N; ++j )
		{
			scanf( "%d", &x );
			pair<set<int>::iterator, bool> result = nums.insert( x );
			if( result.second == false ) // insertion failed because x already in set
			{
				Major t( result.first->num, result.first->occur+1 );
				M.erase( result.first );
				M.insert( t );
			}
		}
		for( set<Major>::iterator it = M.begin(); it!=M.end(); ++it )
		{
			cout << "num: " << it->num << ". occur: " << it->occur << endl;
		}
	}
}
