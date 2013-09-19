#include <iostream>
#include <stack>

using namespace std;

int main ()
{
	string S;
	int c=0;
	while (1)
	{
		cin >> S;
		stack <char> pars;
		int counter=0;
		if (S[0] == '-')
			break;
		++c;
		for (int i=0;i<(int)S.size();++i)
		{
			if (S[i] == '{')
			{
				pars.push(S[i]);
			}
			else // }
			{
				if (pars.empty()) // if the stack is empty, we increment counter
				{
					++counter;
					pars.push('{');
				}
				else
				{
					pars.pop();
				}
			}
		}
		counter += (int)pars.size()/2;
		
		cout << c << ". " << counter << endl;
	}
}
