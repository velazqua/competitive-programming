#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > prizes(n);
    vector<int> prizeMoney(n);
    for(int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for(int j = 0; j < k; j++) {
        int num;
        cin >> num;
        prizes[i].push_back(num);
      }
      cin >> prizeMoney[i];
    }
    vector<int> stickers(m+1);
    for(int i = 0; i < m; i++) {
      cin >> stickers[i+1];
    }
    int total = 0;
    for(int i = 0; i < n; i++) {
      int minn = 1000000;
      for(int k = 0; k < int(prizes[i].size()); k++) {
        minn = min(minn, stickers[prizes[i][k]]);
      }
      total += minn * prizeMoney[i];
    }
    cout << total << endl;
  }
}
