#include <iostream>
#include <set>

using namespace std;

typedef long long int lld;

int main ()
{
  set<lld> fibs;
  fibs.insert(0);
  fibs.insert(1);
  lld a = 0;
  lld b = 1;
  lld c = 0;
  while (c <= 10000000000) {
    c = a + b;
    fibs.insert(c);
    a = b;
    b = c;
  }

  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    lld num;
    cin >> num;
    if (fibs.find(num) != fibs.end()) {
      cout << "IsFibo" << endl;
    }
    else {
      cout << "IsNotFibo" << endl;
    }
  }
}
