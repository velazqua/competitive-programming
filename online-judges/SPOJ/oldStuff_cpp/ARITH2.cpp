#include <iostream>

using namespace std;

int main ()
{
	int N;
	cin >> N;
	long long int answer;
	long long int number;
	char op='X';
	for (int i=0;i<N;++i)
	{
		int s=2;
		bool end=true;
		while (end)
		{
			if (s==2)
			{
				cin >> answer;
				//cout << "answer: " << answer << endl;
			}
			else if (s%2) // operator
			{
				cin >> op;
				if (op=='=')
				{
					cout << answer << endl; end=false;
				}
				//cout << "op: " << op << endl;
			}
			else
			{
				cin >> number;
				//cout << "number: " << number << endl;
				if (op!='X')
				{
					switch(op)
					{
						case '+' : answer += number; break;
						case '-' : answer -= number; break;
						case '*' : answer *= number; break;
						case '/' : answer /= number; break;
					}
					op='X';
				}
			}
			++s;
		}
	} 
}
