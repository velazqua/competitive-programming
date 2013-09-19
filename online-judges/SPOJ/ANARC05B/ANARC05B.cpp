/* Name: Alex Velazquez
 * Start Date: October 02, 2011 @ 04:53PM
 * End Date:   October 02, 2011 @ 05:13PM
 * Purpose: To solve the SPOJ problem ANARC05B - The Double HeLiX
 */
#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

int main ()
{
	int S1, S2, t;
	while (1)
	{
		cin >> S1;
		if (S1 == 0)
			break;
		set<int> check, dupl;
		vector<int> list1, list2;
		for (int i=0;i<S1;++i)
		{
			cin >> t; 
			list1.push_back(t);
			check.insert(t);
		}
		cin >> S2;
		for (int i=0;i<S2;++i)
		{
			cin >> t;
			pair<set<int>::iterator, bool> result = check.insert(t);
			if (result.second == false) // duplicate
				dupl.insert(t);
			list2.push_back(t);
		}
		vector<int>::iterator list1_iter = list1.begin();
		vector<int>::iterator list2_iter = list2.begin();
		int SUM1 = 0, SUM2 = 0, ALLSUM = 0;
		for (set<int>::iterator it=dupl.begin();it!=dupl.end();++it)
		{
			SUM1 = 0;
			SUM2 = 0;
			while (*list1_iter != *it && list1_iter != list1.end())
			{
				SUM1 += *list1_iter;
				++list1_iter;
			}
			while (*list2_iter != *it && list2_iter != list2.end())
			{
				SUM2 += *list2_iter;
				++list2_iter;
			}
			ALLSUM += (SUM1 > SUM2)?SUM1:SUM2;
		}
		SUM1 = 0;
		SUM2 = 0;
		while (list1_iter != list1.end())
		{
			SUM1 += *list1_iter;
			++list1_iter;
		}
		while (list2_iter != list2.end())
		{
			SUM2 += *list2_iter;
			++list2_iter;
		}
		ALLSUM += (SUM1 > SUM2)?SUM1:SUM2;
		cout << ALLSUM << endl;
	}
}
