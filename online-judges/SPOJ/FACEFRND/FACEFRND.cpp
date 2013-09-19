/* Name: Alex Velazquez
 * Start Date: October 22, 2011 @ 09:20PM
 * End Date:   October 22, 2011 @ ??:??PM
*/

#include <iostream>
#include <set>

using namespace std;

int main ()
{
	int F;
	cin >> F;
	set<string> friendsOfFriends;
	set<string> friends;
	for (int i=0;i<F;++i)
	{
		string f;
		cin >> f;
		friends.insert(f);
		int n;
		cin >> n;
		for (int j=0;j<n;++j)
		{
			cin >> f;
			friendsOfFriends.insert(f);
		}
		for( set<string>::iterator it = friends.begin(); it != friends.end(); ++it)
		{
			friendsOfFriends.erase(*it);
		}
	}
	cout << (int)friendsOfFriends.size() << endl;
}
