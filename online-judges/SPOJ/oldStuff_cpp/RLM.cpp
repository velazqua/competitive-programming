#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ULL;

ULL pow (int a, int b)
{
	ULL x=1LL;
	for (int i=0;i<b;++i)
		x *= a;
	return x;
}

ULL RLM2INT (string n)
{
	ULL x=0LL;
	int k=0,j=0;
	while (n.size())
	{
		//cout << n << endl;
		int next=n[(int)n.size()-2]-48;
		int num=n[(int)n.size()-1]-48;
		for (int i=k;i<k+next;++i)
		{
		//	cout << "Adding: " << num*pow(10,i) << endl;  
			x += num*pow(10,i);
			++j;
		}	
		k=j;
		n.erase(n.end()-2,n.end());
	}
	return x;
}

ULL INT2RLM (ULL x)
{
	ULL cur=x;
	int c=0;
	int k=0;
	ULL lastDig;
	ULL answer=0;
	int n=0;
	if (x%10==0)
	{
		answer += cur*pow(10,n);
		answer += 1*pow(10,n+1);
		return answer;
	}
	while (x % 10 != 0)
	{
		lastDig = x%10;
		if (k==0) // first iteration
		{
			cur=lastDig;
			++c;
			++k;
			x /= 10;
			continue;
		}
		if (lastDig != cur) // if digits are different
		{
			answer += cur*pow(10,n);
			answer += c*pow(10,n+1);
			n += 2;
			cur = lastDig;
			c = 1;
		}
		else
		{
			++c;
		}
		x /= 10;
	}
	answer += cur*pow(10,n);
	answer += c*pow(10,n+1);
			
	return answer;
}

int main ()
{
	string x, y;
	char op;
	while (cin >> x >> op >> y)
	{
		ULL x1=RLM2INT(x), y1=RLM2INT(y);
		cout << x1 << " " << op << " " << y1 << " = " << x1-y1 << endl;
	
		switch(op)
		{
			case '+' : 
				cout << INT2RLM(x1+y1) << endl;
				break;
			case '-' : 
				cout << INT2RLM(x1-y1) << endl;
				break;
			case '*' : 
				cout << INT2RLM(x1*y1) << endl;
				break;
			case '/' : 
				cout << INT2RLM(x1/y1) << endl;
				break;
		}
	}
	return 0;
}
