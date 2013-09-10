#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long ulld;

int main ()
{
  map<int,ulld> M;
  for(int i = 1; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      for(int k = 0; k < 10; k++) {
        if (i + j + k <= 9) {
          M[j*10+k]++;
        }
      }
    }
  }
  for(int i = 4; i <= 20; i++) {
    map<int,ulld> T;
    for(map<int,ulld>::iterator it = M.begin();
        it != M.end();
        it++) {
      for(int c = 0; c < 10; c++) {
        int a = it->first / 10;
        int b = it->first % 10;
        if (a + b + c <= 9) {
          T[b*10+c] += it->second;
        }
      }
    }
    M = T;
  }
  ulld total = 0;
  for(map<int,ulld>::iterator it = M.begin();
      it != M.end();
      it++) {
    total += it->second;
  }
  cout << total << endl;
}
