/* Name: Alex Velazquez
 * Start Date: September 26, 2011 @ 09:36PM
 * End Date:   September 26, 2011 @ 03:54PM
 * Purpose: To solve the UVa problem 583 - "Prime Factors"
 * 
 * Sample Input 

-190
-191
-192
-193
-194
195
196
197
198
199
200
0
Sample Output 

-190 = -1 x 2 x 5 x 19
-191 = -1 x 191
-192 = -1 x 2 x 2 x 2 x 2 x 2 x 2 x 3
-193 = -1 x 193
-194 = -1 x 2 x 97
195 = 3 x 5 x 13
196 = 2 x 2 x 7 x 7
197 = 197
198 = 2 x 3 x 3 x 11
199 = 199
200 = 2 x 2 x 2 x 5 x 5
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main ()
{
	int LIMIT = 50000;
    vector<int>primes;
    bool numbers[LIMIT];
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    for (int i=2;i<LIMIT;++i)
        numbers[i] = false;
    while (i <= int(sqrt(LIMIT)))
    {
          for (int j=i+i;j<=LIMIT;j+=i)
              numbers[j] = true;    
          i++;
          while (numbers[i] == true)
                i++;
    }
    for (int i=0;i<LIMIT;++i)
    {
        if (numbers[i] == false)
           primes.push_back(i);
    }

	int num;
	while (cin >> num)
	{
		if (num == 0)
			break;
		vector<int> factors;
		cout << num << " = ";
		if (num < 0)
		{
			factors.push_back(-1);
			num *= -1;
		}
		bool hadFactor = false;
		for (vector<int>::iterator it=primes.begin();it!=primes.end();++it)
		{
			if (num == 1)
				break;
			while (num%*it==0)
			{
				num /= *it;
				hadFactor = true;
				factors.push_back(*it);
			}
		}
		if (hadFactor == false)
			factors.push_back(num);
		cout << *factors.begin();
		vector<int>::iterator it = factors.begin();
		++it;
		for (;it!=factors.end();++it)
		{
			cout << " x " << *it;
		}
		cout << endl;
	}
}
