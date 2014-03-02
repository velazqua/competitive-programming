#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    unsigned long long n, k;
    cin >> n >> k;
    string line;
    cin.ignore();
    getline(cin, line);
    istringstream ss(line);
    unsigned long long token;
    vector<unsigned long long> vals;
    while (ss >> token) {
      vals.push_back(token);
    }
    sort(vals.begin(), vals.end());
    unsigned long long a1;
    int K = k;
    for(int i = 0; i < n; i++) {
      if (i == 0) {
        a1 = vals[i]/k;
        cout << a1;
        K--;
      }
      else {
        cout << " " << vals[i]-K*a1;
      }
    }
    cout << endl;
  }
}
