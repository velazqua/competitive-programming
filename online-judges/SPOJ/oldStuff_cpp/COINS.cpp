#include <iostream>
#include <set>
#include <map>

using namespace std;

unsigned int exchange (unsigned int n, map<unsigned int, unsigned int> &nums)
{
	if (nums.find(n) != nums.end()) //if element in set
		return nums[n];
	if (n/2+n/3+n/4 >= n)
	{
		nums[n] = exchange(n/2,nums) + exchange(n/3,nums) + exchange(n/4,nums);
		return nums[n];
	}
	else
	{
		nums[n] = n;
		return n;
	}
}

int main ()
{
	unsigned int n;
	map<unsigned int,unsigned> nums;
	while (cin >> n)
	{
		cout << exchange(n,nums) << endl;
	}
	
}
