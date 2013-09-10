#include <iostream>
#include <map>
#include <set>

using namespace std;

int o2( int N, bool d )
{
	int A = 0;
	set<int> nums;
	for( int i=1; i*i<=N; ++i )
	{
		if( N%i == 0 )
		{
			nums.insert( i );
			nums.insert( N/i );
			A += i*i;
			A += (N/i)*(N/i);
			if( i*i == N )
				A -= i*i;
		}
	}
	if( d )
	{
		cout << N << " = ";
		for( set<int>::iterator it=nums.begin(); it!=nums.end(); ++it )
			cout << " + " << *it;
		cout << endl;
	}	
	return A;
}

int main ()
{
	map<int,bool> isSquare;
	for( int i=1; i<30000; ++i )
		isSquare[i*i] = true;
	for( int i=1; i<=100000; ++i )
	{
		if( isSquare[o2(i,false)] )
			cout << "i: " << i << ". o2(i): " << o2( i, true ) << endl;
	}
}
