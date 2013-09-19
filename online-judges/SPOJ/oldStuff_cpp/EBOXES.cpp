#include <iostream>

using namespace std;

int main ()
{
	int cases;
	cin >> cases;
	for (int i=0;i<cases;++i)
	{
		int N,K,T,F;
		cin >> N >> K >> T >> F;
		cout << (N-F)/(1-K)+F << endl;
	}
}
