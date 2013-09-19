#include <iostream>
#include <set>

using namespace std;

int main ()
{
	int A[500000+1];
	A[0]=0;
	set<int> nums;
	nums.insert(0);
	for (int i=1;i<500000+1;++i)
	{
		A[i] = (A[i-1]-i>0 && nums.find(A[i-1]-i)==nums.end())?A[i-1]-i:A[i-1]+i;
		nums.insert(A[i]);
	}	

	for (int i=1;i<50;++i)
	{
		if (A[i] > A[i-1])
			cout << "U ";
		else
			cout << "D ";
	}
	cout << endl;
	int k;
	while (1)
	{
		cin >> k;
		if (k == -1)
			break;
		cout << A[k] << endl;
	}
}
