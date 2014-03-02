#include <iostream>
#include <vector>

typedef unsigned long long ulld;

using namespace std;

ulld factorial (int n) {
  if (n == 0 || n == 1)
    return 1;
  ulld result = 1;
  for(int i = 2; i <= n; i++)
    result *= i;
  return result;
}

ulld multinomial_coefficient (int n, int a, int b, int c) {
  ulld result = factorial(n);
  result /= factorial(a);
  result /= factorial(b);
  result /= factorial(c);
  return result;
}

int main ()
{
  ulld result = 0;
  for(int i = 3; i <= 16; i++) {
    cout << i << " digits: " << endl;
    for(int a = 1; a <= i-1; a++) {
      for(int b = 0; b <= (i-1)-a; b++) {
        int c = i-1-a-b;
        if (b + c >= 1) {
          int m = (b > 0 && c > 0) ? 2 : 1;
          cout << a << " " << b << " " << c << endl;
          result += (m * multinomial_coefficient(i-1, a, b, c));
        }
      }
    }
    cout << "result: " << result << endl;
  }
  // this is the decimal result, the hex result i just googled.
  cout << result << endl;
}
