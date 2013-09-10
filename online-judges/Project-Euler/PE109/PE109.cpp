#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

void printStuff(vector< pair<int,int> >& V) {
  cout << "{";
  for(auto &v : V) {
    if (v.second == 1)
      cout << "S";
    else if (v.second == 2)
      cout << "D";
    else
      cout << "T";
    cout << v.first << ", ";
  }
  cout << "}" << endl;
}

int main ()
{
  set< vector< pair<int,int> > > S;

  // ones
  for(int i = 1; i <= 25; i++) {
    if (i >= 21 && i <= 24)
      continue;
    vector< pair<int,int> > T;
    T.push_back(make_pair(i, 2));
    if (i * 2 < 100) {
      printStuff(T);
      S.insert(T);
    }
  }

  // twos
  for(int i = 1; i <= 25; i++) {
    if (i >= 21 && i <= 24)
      continue;
    for(int k = 1; k <= 3; k++) {
      if (k == 3 && i == 25)
        continue;
      for(int j = 1; j <= 25; j++) {
        if (j >= 21 && j <= 24)
          continue;
        if (i * k + 2 * j < 100) {
          vector< pair<int,int> > T;
          T.push_back(make_pair(i, k));
          T.push_back(make_pair(j, 2));
          auto result = S.insert(T);
            if (result.second == true)
              printStuff(T);
        }
      }
    }
  }

  // threes
  for(int i = 1; i <= 25; i++) {
    if (i >= 21 && i <= 24)
      continue;
    for(int k = 1; k <= 3; k++) {
      if (k == 3 && i == 25)
        continue;
      for(int j = 1; j <= 25; j++) {
        if (j >= 21 && j <= 24)
          continue;
        for(int k2 = 1; k2 <= 3; k2++) {
          if (j == 25 && k2 == 3)
            continue;
          for(int l = 1; l <= 25; l++) {
            if (l >= 21 && l <= 24)
              continue;
            if (i * k + j * k2 + 2 * l < 100) {
              vector< pair<int,int> > T;
              T.push_back(make_pair(i, k));
              T.push_back(make_pair(j, k2));
              sort(T.begin(), T.end());
              T.push_back(make_pair(l, 2));
              auto result = S.insert(T);
              if (result.second == true) {
                printStuff(T);
              }
            }
          }
        }
      }
    }
  }
  cout << S.size() << endl;
}
