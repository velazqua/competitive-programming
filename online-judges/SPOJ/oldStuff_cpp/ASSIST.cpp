#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

struct range {
	int curr;
	range() {curr=1;}
	int operator ()() {return ++curr;}
};

using namespace std;

int main ()
{
	// precompute values!
	vector<int> nums (20);
	vector<int>::iterator it;
	vector<int>::iterator it2;
	generate (nums.begin(),nums.end(),range());
	for (it=nums.begin();it!=nums.end();++it)
	{
		cout << *it << ": ";
		for (it2=it;it2!=nums.end();advance(it2,2))
		{
			cout << *it2 << ", ";
		}
		cout << endl;
	}
	
	// taking input, displaying output :)
	/*
	int N;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
	}
	*/
}
