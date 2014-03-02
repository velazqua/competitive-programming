#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
  string A, B;
  cin >> A >> B;
  vector<int> a(26, 0);
  vector<int> b(26, 0);
  for(int i = 0; i < int(A.size()); i++) {
    a[A[i]-'a']++;
  }
  for(int i = 0; i < int(B.size()); i++) {
    b[B[i]-'a']++;
  }
  int total = 0;
  for(int i = 0; i < 26; i++) {
    total += abs(a[i]-b[i]);
  }
  cout << total << endl;
}
