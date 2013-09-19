/* Alex Velazquez
 * Start: Sat May 12 22:12:23 EDT 2012
 * End  :
*/
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> LIST;                            // linked list type
typedef LIST::size_type LIST_SIZE;              // size type for list, e.g., unsigned
typedef LIST::iterator LIST_ITER;                 // iterator type
typedef LIST::value_type LIST_CONTAINS;   // type in the list, i.e., a string

void merge_sort(LIST_ITER beg, LIST_ITER end, LIST_SIZE sz);
void merge(LIST_ITER bLeft, LIST_ITER bRight, LIST_ITER end);

long long inv = 0LL;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

int main()
{	
	int T;
	scanf( "%d", &T );
	//cout << "T: " << T << endl;
	REP( i, T )
	{
		int N;
		scanf( "%d", &N );
		//cout << "N: " << N << endl;
		vector<int> nums( N );
		REP( j, N )
			scanf( "%d", &nums[j] );
			
		LIST_ITER it = nums.begin();
		LIST_ITER itEnd = nums.end();

		merge_sort(it,itEnd,distance(it,itEnd));
		cout << inv << endl;
		inv = 0;
	}
}

void merge_sort(LIST_ITER beg, LIST_ITER end, LIST_SIZE sz)
{
	if ( sz <= 1 )
		return;
	
	int n = sz/2;
	
	LIST_ITER middle = beg;
	advance(middle, n);

	merge_sort(beg,middle,n);
	merge_sort(middle,end,sz-n);
	merge(beg,middle,end);
}

void merge(LIST_ITER bLeft, LIST_ITER bRight, LIST_ITER end)
{
	LIST_ITER first = bLeft, mid = bRight;

	LIST lTemp;

	while (first != bRight && mid != end)
	{
		if (*first < *mid)
		{
			lTemp.push_back(*first);
			first++;
		}
		else
		{
			inv += distance( first, bRight );
			lTemp.push_back(*mid);
			mid++;
		}
	}

	while (first != bRight)
	{
		lTemp.push_back(*first);
		first++;
	}

	while (mid != end)
	{
		lTemp.push_back(*mid);
		mid++;
	}

	for (LIST_ITER it = lTemp.begin(); it != lTemp.end() ; ++it)
	{
		*bLeft = *it;
		++bLeft;
	}
}
