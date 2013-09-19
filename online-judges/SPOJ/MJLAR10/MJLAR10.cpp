/* Name: Alex Velazquez
 * Start Date: October 02, 2011 @ 11:26PM
 * End Date:   October 02, 2011 @ 11:53PM
 * Purpose: To solve the SPOJ problem MJLAR10 - Jollo
 */
#include <iostream>
#include <set>

using namespace std;

int main ()
{
	int A, B, C, X, Y;
	while (1)
	{
		cin >> A >> B >> C >> X >> Y;
		if (A==0&&B==0&&C==0&&X==0&&Y==0)
			break;
		set<int> pss, p, all;
		pss.insert(A); pss.insert(B); pss.insert(C);
		p.insert(X); p.insert(Y);
		all.insert(A); all.insert(B); all.insert(C);
		all.insert(X); all.insert(Y);
		
		// There are 3 cases:
		// Case 1: Both of Prince's numbers are greater than all
		// 		of the Pricess' numbers
		set<int>::iterator pssEnd = pss.end();
		set<int>::iterator p1Iter = p.begin();
		set<int>::iterator p2Iter = p.begin(); p2Iter++;
		--pssEnd;
		if (*p1Iter > *pssEnd && *p2Iter > *pssEnd) 
		{
			int answer = 1;
			while (all.find(answer) != all.end()) ++answer;
			if (answer >= 53)
				cout << -1 << endl;
			else
				cout << answer << endl;
			continue;
		}
		
		// Case 2: One of the Prince's numbers is less than
		// 		some of the Princess' numbers
		p2Iter = p.begin();
		for (p1Iter=pss.begin();p1Iter!=pss.end();++p1Iter)
		{
			if (*p1Iter > *p2Iter) 
			{
				pss.erase(p1Iter);
				p.erase(p2Iter);
				p1Iter = pss.begin();
				p2Iter = p.begin();
				if (*p2Iter > *p1Iter)
				{
					p1Iter++;
					if (*p2Iter > *p1Iter)
					{
						int answer = *p1Iter+1;
						while (all.find(answer) != all.end()) ++answer;
						if (answer >= 53)
							cout << -1 << endl;
						else
							cout << answer << endl;
						break;
					}
					else
					{
						cout << -1 << endl;
						break;
					}
				}
				else
				{
					cout << -1 << endl;
					break;
				}
			}
		}
		// Case 3: Both of the Prince's numbers are less than
		// 		the Princess' numbers
		// cout << -1 << endl; // No number can help the Prince
	}
}
