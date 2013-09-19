#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	string s;
	cin >> s;
	int M;
	cin >> M;
	int A, B;
	string::iterator it = s.begin();
	//cout << "starting: " << s << endl;
	for (int i=0;i<M;++i)
	{	
		cin >> A >> B;
		reverse(it+A-1,it+B);
	//	cout << s << endl;	
	}
	cout <<  s << endl;
}
