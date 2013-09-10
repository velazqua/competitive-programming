#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    int LIMIT = 100;
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

}
