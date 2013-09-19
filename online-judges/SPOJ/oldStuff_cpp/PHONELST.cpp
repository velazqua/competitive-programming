#include <iostream>
#include <list>
#include <string>

using namespace std;

struct String {
	string s;
	String (string s_) : s(s_) {}
};

ostream& operator << (ostream& os, const String& c)
{
	os << c.s;
	return os;
}

bool operator < (const String& a, const String& b)
{
	return ((int)a.s.size() <= (int)b.s.size()) ? true : false; 
}

int main ()
{	

	int T;
	cin >> T;
	int N;
	for (int i=0;i<T;++i)
	{
		cin >> N;
		list<String> phones;
		string p;
		for (int j=0;j<N;++j)
		{
			cin >> p;
			phones.push_back(String(p));
		}
		phones.sort();
		list<String>::iterator it=phones.begin();
		list<String>::iterator itEnd=phones.end();
		--itEnd;
		list<String>::iterator it2;
		list<String>::iterator itActualEnd=phones.end();
		bool e=true;
		for (;it!=itEnd&&e;++it)
		{
			it2 = it;
			++it2;
			for (;it2!=itActualEnd&&e;++it2)
			{
				if ((*it).s.compare((*it2).s.substr(0,(int)(*it).s.size())) == 0) // equal
				{
					cout << "NO" << endl;
					e=false;
				}
			}
		}
		if (e)
			cout << "YES" << endl;
	}
	
}
