/* Name: Alex Velazquez
 * Start Date: October 11, 2011 @ 06:10PM
 * End Date:   October 11, 2011 @ ??:??PM
*/

#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

string areBracketsMatching ( char* s, int &N )
{
	stack<char> t;
	for (int i=0;i<N;++i)
	{
		if (s[i] == '(') // insert to stack
			t.push('(');
		else
		{
			if (t.empty()) return "NO";
			else
			{
				t.pop();
			}
		}
	}
	if (t.empty()) return "YES";
	else return "NO";
}

int main ()
{
	for (int i=0;i<10;++i)
	{
		int N;
		scanf("%d\n", &N);
		char B[N];
		scanf("%s\n", B);
		int O;
		scanf("%d\n", &O);
		printf("Test %d:\n", i+1);
		for (int j=0;j<O;++j)
		{
			int A;
			scanf("%d\n",&A);
			//printf("Command: %d. Current brackets: %s\n", A, B);
			if (A == 0)
				cout << areBracketsMatching(B,N) << endl;
			else
				B[A-1] = ((B[A-1]=='(')?')':'(');
		}
	}
}
