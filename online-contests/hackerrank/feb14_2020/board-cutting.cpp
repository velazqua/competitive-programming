#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ulld;

bool comp1 (pair<int,int> const& A, pair<int,int> const& B) {
  if (A.first > B.first)
    return true;
  else if (A.first < B.first)
    return false;
  else
    return A.second < B.second;
}

bool comp2 (pair<int,int> const& A, pair<int,int> const& B) {
  if (A.first > B.first)
    return true;
  else if (A.first < B.first)
    return false;
  else
    return A.second > B.second;
}

int main ()
{
  int MOD = 1000000000 + 7;
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int M, N;
    cin >> M >> N;
    vector<pair<int,int> > P1, P2;
    for(int i = 0; i < M-1; i++) {
      int x;
      cin >> x;
      P1.push_back(make_pair(x, 1));
      P2.push_back(make_pair(x, 1));
    }
    for(int i = 0; i < N-1; i++) {
      int x;
      cin >> x;
      P1.push_back(make_pair(x, 0));
      P2.push_back(make_pair(x, 0));
    }
    sort(P1.begin(), P1.end(), comp1);
    sort(P2.begin(), P2.end(), comp2);

    ulld total1 = 0, total2 = 0;
    ulld x = 1, y = 1;
    for(int i = 0; i < M+N-2; i++) {
      if (P1[i].second == 1) {
        total1 += (y * P1[i].first);
        total1 %= MOD;
        x++;
      }
      else {
        total1 += (x * P1[i].first);
        total1 %= MOD;
        y++;
      }
    }

    x = 1, y = 1;
    for(int i = 0; i < M+N-2; i++) {
      if (P2[i].second == 1) {
        total2 += (y * P2[i].first);
        total2 %= MOD;
        x++;
      }
      else {
        total2 += (x * P2[i].first);
        total2 %= MOD;
        y++;
      }
    }

    cout << min(total1, total2) << endl;
  }
}
