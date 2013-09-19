#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector<int> lastDigit;
	vector<int> firstDigit;
	for( int i=0; i<90; ++i )
	{
		lastDigit.push_back( i%10 );
		firstDigit.push_back( i/10 );
	}
}
