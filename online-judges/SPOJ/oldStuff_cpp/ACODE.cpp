#include <iostream>
#include <string>

using namespace std;

int count (string s)
{
	if (s.size() == 1)
		return 1;
	
	int a = (int)s[0]-48;
	int b = a*10+(int)s[1]-48;
	if (s.size() == 2)
	{
		if (b<27)
			return 2;
		else
			return 1;
	}
	else
	{
		if (b < 27)
			return count(s.substr(1,s.size()-1)) + count(s.substr(2,s.size()-2));
		else
			return count(s.substr(1,s.size()-1));
	}
}

int main ()
{
	string n;
	while (cin >> n && n != "0")
		cout << count(n) << endl;
}
