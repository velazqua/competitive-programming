#include <iostream>
#include <stack>

using namespace std;

int main ()
{
	int t;
	cin >> t;
	for (int i=0;i<t;++i)
	{
		string expr;
		cin >> expr;
		stack<char> op;
		for (string::iterator it=expr.begin();it!=expr.end();++it)
		{
			if ( *it == ')' )
			{
				cout << op.top();
				op.pop();
			}
			else if ( *it == '(');
			else if (*it=='+'||*it=='-'||*it=='*'||*it=='/'||*it=='^')
				op.push(*it);
			else
				cout << *it;
		}
		cout << endl;
	}
}
