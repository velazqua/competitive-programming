/* Alex Velazquez
 * Start: Sun Sep 29 16:12:30 EDT 2013
 * End  : Sun Sep 29 16:42:09 EDT 2013
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

map<string, int> tokenize(string line) {
  string key;
  int value = 0;
  map<string, int> M;
  REP(i, SZ(line)) {
    if (line[i] == '{')
      continue;
    else if (line[i] >= 'a' && line[i] <= 'z') {
      key += line[i];
    }
    else if (line[i] == ',' || line[i] == '}') {
      if (!key.compare("") && value == 0)
        continue;
      M[key] = value;
      key.clear();
      value = 0;
    }
    else if (line[i] >= '0' && line[i] <= '9') {
      value *= 10;
      value += line[i]-'0';
    }
  }
  return M;
}

int main ()
{
  int T;
  cin >> T;
  REP(i, T) {
    if (i == 0) cin.ignore();
    string firstLine, secondLine;
    getline(cin, firstLine);
    getline(cin, secondLine);
    map<string, int> oldMap = tokenize(firstLine);
    map<string, int> newMap = tokenize(secondLine);

    bool changed = false, a = false, r = false, c = false;

    // look for added objects in newMap
    for(map<string, int>::iterator it = newMap.begin();
        it != newMap.end();
        it++) {
      map<string, int>::iterator f = oldMap.find(it->first);
      if (f == oldMap.end()) {
        if (!a) {
          cout << "+";
          a = true;
          cout << it->first;
        }
        else {
          cout << "," << it->first;
        }
      }
    }
    if (a)
      cout << endl;

    // look for deleted objects in oldMap
    for(map<string, int>::iterator it = oldMap.begin();
        it != oldMap.end();
        it++) {
      map<string, int>::iterator f = newMap.find(it->first);
      if (f == newMap.end()) {
        if (!r) {
          cout << "-";
          r = true;
          cout << it->first;
        }
        else {
          cout << "," << it->first;
        }
      }
    }
    if (r)
      cout << endl;

    // look for changed objects
    for(map<string, int>::iterator it = oldMap.begin();
        it != oldMap.end();
        it++) {
      map<string, int>::iterator f = newMap.find(it->first);
      if (f != newMap.end()) {
        if (it->second != f->second) {
          if (!c) {
            cout << "*";
            c = true;
            cout << it->first;
          }
          else {
            cout << "," << it->first;
          }
        }
      }
    }
    if (c)
      cout << endl;

    // No changes?
    changed = a || r || c;
    if (!changed) {
      cout << "No changes" << endl;
    }
    cout << endl;
  }
}
