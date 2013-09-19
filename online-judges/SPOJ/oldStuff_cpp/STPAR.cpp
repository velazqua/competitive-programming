#include <iostream>
#include <stack>

using namespace std;

int main ()
{
	int n;
	while (cin >> n && n != 0)
	{
		int currCar = 1;
		stack<int> cars;
		int nextCar;
		for (int i=0;i<n;++i)
		{
			cin >> nextCar;
			bool added = false;
			if (cars.empty())
			{
				if (nextCar == currCar)
					currCar++;
				else
					cars.push(nextCar);
			}
			else // non empty cars
			{
				while (!cars.empty())
				{
					if (nextCar == currCar)
					{
						currCar++;
						added = true;
					}
					else if (cars.top() == currCar)
					{
						cars.pop();
						currCar++;
						added = true;
					}
					else if (nextCar != currCar && !added)
					{
						cars.push(nextCar);
						break;
					}
					else
						break;
				}
				
			}
		}
		if (cars.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
