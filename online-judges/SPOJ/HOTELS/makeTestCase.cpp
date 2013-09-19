#include <iostream>

using namespace std;

int main ()
{
	cout << 300000 << " " << 2147000000 << endl;
	cout << 999991;
	for( int i=0;i<300000-1;++i )
	{
		cout << " " << 999999;
	}
	cout << endl;
}
