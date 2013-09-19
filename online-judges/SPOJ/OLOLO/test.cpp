#include <iostream>

using namespace std;

int main ()
{
	char a = 'V';
	int S = 17;
	cout << char(64+((int(a)-64)+(26-S))%26) << endl;
}
