#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ulld;

struct People {
  int id;
  string name;
  ulld K;
  ulld D;
  People(int i, string n, ulld k, ulld d) : id(i), name(n), K(k), D(d) {}
};

bool operator < (People const& A, People const& B) {
  return A.K*B.D < A.D*B.K;
}

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    vector<People> losers;
    vector<People> winners;
    vector<bool> uninstall(10, false);
    vector<string> names;
    for(int i = 0; i < 10; i++) {
      ulld K, D;
      string name;
      cin >> name >> K >> D;
      names.push_back(name);
      if (i < 5)
        winners.push_back(People(i, name, K, D));
      else
        losers.push_back(People(i, name, K, D));
      int mult = (i < 5) ? 3 : 2;
      if ((mult * K < D || K == 0) && (D > 0))
        uninstall[i] = true;
    }
    sort(losers.begin(), losers.end());
    ulld kLoser = losers[0].K, dLoser = losers[0].D;
    for(auto it = losers.begin();
        it != losers.end();
        it++) {
      if (kLoser * it->D == dLoser * it->K)
        uninstall[it->id] = true;
      else
        break;
    }
    for(int i = 0; i < 10; i++) {
      if (uninstall[i])
        cout << names[i] << " plz uninstall" << endl;
    }
  }
}
