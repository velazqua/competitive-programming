/* Alex Velazquez
 * Start: November 20, 2011 @ 05:05PM
 * End  : November 20, 2011 @ ?????PM
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    int LIMIT = 10000;
    vector<int> primes;
    vector<bool> numbers(LIMIT);
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    //for (int i=2;i<LIMIT;++i)
    //    numbers[i] = false;
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
        if (numbers[i] == false && i > 1000)
        {
           primes.push_back(i);
		}
    }
    int size = primes.size(); 
	for( int i=0; i<size; ++i )
	{
		cout << primes[i] << endl;
	}
	cout << size << endl;

}
