#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
	int N;
	string needle, haystack;
	size_t found;
	int i;
	while (cin >> N)
	{
		i=0;
		cin >> needle >> haystack;
		found = haystack.find(needle,i);
		while (found!=string::npos)
		{
			cout << int(found) << endl;
			found = haystack.find(needle,int(found)+1);
		}
	}
}
