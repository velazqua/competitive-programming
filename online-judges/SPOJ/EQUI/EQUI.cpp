/* Name: Alex Velazquez
 * Start Date: October 08, 2011 @ 09:40PM
 * End Date:   October 08, 2011 @ ??:??PM
*/
 
#include <iostream>
#include <set>

using namespace std;

typedef long long ULL;

int main ()
{
	ULL N,t;
	while (cin >> N)
	{
		if (N == (long long)-1)
			break;
		set<ULL> nums;
		ULL sumOfSet = (long long) 0;
		for (int i=0;i<(int)N-1;++i)
		{
			cin >> t;
			nums.insert(t);
			sumOfSet += t;
		}
		// find numbers that can be median (two of them) + unknown number
		set<ULL>::iterator first = nums.begin(), second;
		for (int i=0;i<(int)N/2;++i)
			++first;
		second = first; --second;
		int answers = 0;
		//cout << "first: " << *first << ". second: " << *second << endl;
		//cout << *first*N-sumOfSet << " " << *second*N-sumOfSet << " " << sumOfSet/(N-(long long)1) << endl;
		set<ULL> possibleAnswers;
		possibleAnswers.insert(*first*N-sumOfSet);
		possibleAnswers.insert(*second*N-sumOfSet);
		if (sumOfSet%(N-(long long)1) == (long long)0)
			possibleAnswers.insert(sumOfSet/(N-(long long)1));
		set<ULL>::iterator it = possibleAnswers.begin();
		for (; it!=possibleAnswers.end();++it)
		{
			if (nums.find(*it) == nums.end()) // not found
				++answers;	
		}
		cout << answers << endl;
	}
}
