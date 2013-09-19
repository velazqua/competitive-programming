/* Alex Velazquez
 * Start: Mon Sep 16 12:28:42 EDT 2013
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

string clean_up (string S) {
  string newS;
  for(string::iterator it = S.begin();
      it != S.end();
      it++) {
    if (*it != 32)
      newS.push_back(*it);
  }
  sort(newS.begin(), newS.end());
  return newS;
}

void process (map<string, vector<string> >& M) {
  vector<pair<string, string> > V;
  for(map<string, vector<string> >::iterator it = M.begin();
      it != M.end();
      it++) {
    sort(it->second.begin(), it->second.end());
    int size = it->second.size();
    for(int i = 0; i < size-1; i++) {
      for(int j = i+1; j < size; j++) {
        V.push_back(make_pair(it->second[i], it->second[j]));
      }
    }
  }
  sort(V.begin(), V.end());
  for(vector<pair<string, string> >::iterator it = V.begin();
      it != V.end();
      it++) {
    cout << it->first << " = " << it->second << endl;
  }
}

int main ()
{
  int T;
  cin >> T;
  string line;
  cin.ignore();
  int c = 0;
  map<string, vector<string> > M;
  while (getline(cin, line)) {
    if (!line.compare("")) {
      c++;
      if (!M.empty()) {
        process(M);
        if (c > 1)
          cout << endl;
      }
      M.clear();
    }
    else {
      M[clean_up(line)].push_back(line);
    }
  }
  if (!M.empty())
    process(M);
}
