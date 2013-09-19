#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector<vector<int> > mults;
	for( int i=0; i<48; ++i )
	{
		mults.push_back( vector<int>(1,-42) );
	}
	for( int i=48; i<58; ++i )
	{
		vector<int> t;
		for( int k=0; k<48; ++k )
		{
			t.push_back( -42 );
		}
		for( int j=48; j<58; ++j )
		{
			t.push_back( (i-48)*(j-48) );
		}
		mults.push_back( t );
	} 
}
