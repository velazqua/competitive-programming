#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long int ulld;

int main ()
{
  set<ulld> squares;
  ulld MAX = 30000000;
  for (ulld i = 1; i <= 10000000; i+=1) {
    squares.insert(i*i);
  }
  ulld maxD = 1000;
  for (ulld D = 2; D <= maxD; D++) {
    if (squares.find(D) != squares.end()) {
      continue;
    }
    bool found = false;
    for (set<ulld>::iterator it = squares.begin();
        it != squares.end();
        it++) {
      ulld y = *it;
      ulld x = 1 + D*y;
      if (squares.find(x) != squares.end()) {
        cout << x << " - " << D << " * " << y << " = 1 " << endl;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "DIDN'T FIND FOR D: " << D << endl;
    }
  }
}
