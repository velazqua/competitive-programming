#include <iostream>
#include <list>

using namespace std;

int main ()
{
	/* n is the amount of boxes
	 * k is the amount of screws needed per table
	 * s is the amount of tables needed
	 */
	int n, k, s;
	cin >> n >> k >> s;
	list<int> boxes;
	int screws;
	for (int i=0;i<n;++i)
	{
		cin >> screws;
		boxes.push_back(screws);
	}
	boxes.sort();
	int sum=0;
	int counter=1;
	list<int>::reverse_iterator rit;
	for (rit=boxes.rbegin();rit!=boxes.rend();++rit)
	{
		sum += *rit;
		if (sum >= k*s)
		{
			cout << counter << endl;
			break;
		}
		counter++;
	}
}
