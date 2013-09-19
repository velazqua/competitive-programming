#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <string>
#include <iterator>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	int S;
	list<pair<string,string> > P;
	string R1, R2;
	for (int i=0;i<T;++i)
	{
		cin >> S;
		for (int j=0;j<S-1;++j)
		{
			cin >> R1 >> R2;
			P.push_back(make_pair(R1,R2));
		}
		list<string> router;
		int c=0;
		string f;
		string l;
		list<pair<string,string> >::iterator t;
		while (!P.empty())
		{
			
			if (c == 0)
			{
				t = P.begin();
				f=t->first;
				l=t->second;
				P.pop_front();
				//cout << "First: " << f << ". Last: " << l << endl;
				router.push_back(f);
				router.push_back(l);
			}
			else
			{
				f=router.front();
				l=router.back();
				//cout << "First: " << f << ". Last: " << l << endl;
			}
			++c;
			list<pair<string,string> >::iterator it=P.begin();
			list<pair<string,string> >::iterator itEnd=P.end();
			pair<string,string> iter;
			for (; it != itEnd; ++it)
			{
				iter = *it;
				if (f.compare(iter.second) == 0) //if equal
				{
					//cout << "First: " << f << ". Match: " << iter.second << endl;
					router.push_front(iter.first);
					P.erase(it);
					break;
				}
				else if (l.compare(iter.first) == 0)
				{
					//cout << iter.second << endl;
					//cout << "Last: " << l << ". Match: " << iter.first << endl;
					router.push_back(iter.second);
					P.erase(it);
					break;
				}
			}
		}
		cout << "Scenario #" << i+1 << ":" <<endl;
		for (list<string>::iterator it=router.begin();it!=router.end();++it)
		{
			cout << *it << endl;
		}
		cout << endl;
	}
}
