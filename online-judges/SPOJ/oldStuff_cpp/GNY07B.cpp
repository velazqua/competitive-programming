#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

pair<double,string> convert( double amount, string c)
{
	if (c == "kg")
		return make_pair(amount*2.2046,"lb");
	else if (c == "lb")
		return make_pair(amount*0.4536,"kg");
	else if (c == "l")
		return make_pair(amount*0.2642,"g");
	else
		return make_pair(amount*3.7854,"l");
}

int main ()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		double amount;
		string conversion;
		cin >> amount;
		cin >> conversion;
		pair<double,string> answer = convert(amount,conversion);
		cout << i << " " << fixed << setprecision(4) << answer.first;
		cout << " " << answer.second << endl;
	}
}
