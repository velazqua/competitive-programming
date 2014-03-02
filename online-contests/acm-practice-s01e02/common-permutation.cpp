#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ischar (char c) {
  return (c - 'a' >= 0 && c - 'a' < 26) ? true : false;
}

int main ()
{
  string a, b;
  while (getline(cin, a) && getline(cin, b)) {
    vector<int> A(26, 0), B(26, 0);
    for(int i = 0; i < int(a.size()); i++)
      if (ischar(a[i]))
        A[a[i]-'a']++;
    for(int i = 0; i < int(b.size()); i++)
      if (ischar(b[i]))
        B[b[i]-'a']++;
    string S;
    for(int i = 0; i < 26; i++) {
      if (A[i] > 0 && B[i] > 0) {
        int s = min(A[i], B[i]);
        for(int k = 0; k < s; k++)
          S += char(97+i);
      }
    }
    sort(S.begin(), S.end());
    cout << S << endl;
  }
}
