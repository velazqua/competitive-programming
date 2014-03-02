/* Alex Velazquez
 * Start: Thu Jan  2 17:51:36 EST 2014
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

vector<string> tokenize (string name) {
  vector<string> result;
  size_t found = name.find_first_of(" ");
  while (found != string::npos) {
    result.push_back(name.substr(0, found));
    name = name.substr(found+1);
    found = name.find_first_of(" ");
  }
  result.push_back(name);
#if DEBUG
  for(vector<string>::iterator it = result.begin();
      it != result.end();
      it++) {
    cout << "token: " << *it << endl;
  }
#endif
  return result;
}

bool areConfusing (string name1, string name2) {
  size_t name1Size = name1.size();
  size_t name2Size = name2.size();
  if (name1[0] != name2[0] || name1[name1Size-1] != name2[name2Size-1])
    return false;
  for(size_t i = 1; i < name1Size-1; i++) {
    for(size_t j = 1; j < name2Size-1; j++) {
      if (name1[i] == name2[j])
        return true;
    }
  }
  return false;
}

bool sameOriginal (string name1, string name2, string newString) {
  return (!name1.compare(newString) || !name2.compare(newString));
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    if (t != 0) cout << endl;
    if (t == 0) cin.ignore();
    string name1, name2;
    getline(cin, name1);
    getline(cin, name2);
    set<string> confusingNames;
    vector<string> name1Tokens = tokenize(name1);
    vector<string> name2Tokens = tokenize(name2);
    map<string, set<string> > confused;

    for(vector<string>::iterator it = name1Tokens.begin();
        it != name1Tokens.end();
        it++) {
      confused[*it].insert(*it);
      for(vector<string>::iterator it2 = name2Tokens.begin();
          it2 != name2Tokens.end();
          it2++) {
        confused[*it2].insert(*it2);
        if (areConfusing(*it, *it2)) {
#if DEBUG
          cout << *it << " and " << *it2 << " are confusing" << endl;
#endif
          confused[*it].insert(*it2);
          confused[*it2].insert(*it);
        }
      }
    }

    // generate all names
    if (name1Tokens.size() == 1) {
      for(set<string>::iterator it = confused[name1Tokens[0]].begin();
          it != confused[name1Tokens[0]].end();
          it++) {
        if (name1Tokens[0].compare(*it)){
          if (!sameOriginal(name1, name2, *it))
            confusingNames.insert(*it);
        }
      }
    }
    else if (name1Tokens.size() == 2) {
      for(set<string>::iterator it = confused[name1Tokens[0]].begin();
          it != confused[name1Tokens[0]].end();
          it++) {
        for(set<string>::iterator it2 = confused[name1Tokens[1]].begin();
          it2 != confused[name1Tokens[1]].end();
          it2++) {
          if (name1Tokens[0].compare(*it) || name1Tokens[1].compare(*it2)) {
            if (!sameOriginal(name1, name2, *it + " " + *it2))
              confusingNames.insert(*it + " " + *it2);
          }
        }
      }
    }
    else {
      for(set<string>::iterator it = confused[name1Tokens[0]].begin();
          it != confused[name1Tokens[0]].end();
          it++) {
        for(set<string>::iterator it2 = confused[name1Tokens[1]].begin();
          it2 != confused[name1Tokens[1]].end();
          it2++) {
          for(set<string>::iterator it3 = confused[name1Tokens[2]].begin();
            it3 != confused[name1Tokens[2]].end();
            it3++) {
            if (name1Tokens[0].compare(*it) || name1Tokens[1].compare(*it2) || name1Tokens[2].compare(*it3)) {
              if (!sameOriginal(name1, name2, *it + " " + *it2 + " " + *it3))
                confusingNames.insert(*it + " " + *it2 + " " + *it3);
            }
          }
        }
      }
    }

    if (name2Tokens.size() == 1) {
      for(set<string>::iterator it = confused[name2Tokens[0]].begin();
          it != confused[name2Tokens[0]].end();
          it++) {
        if (name2Tokens[0].compare(*it)){
          if (!sameOriginal(name1, name2, *it))
            confusingNames.insert(*it);
        }
      }
    }
    else if (name2Tokens.size() == 2) {
      for(set<string>::iterator it = confused[name2Tokens[0]].begin();
          it != confused[name2Tokens[0]].end();
          it++) {
        for(set<string>::iterator it2 = confused[name2Tokens[1]].begin();
          it2 != confused[name2Tokens[1]].end();
          it2++) {
          if (name2Tokens[0].compare(*it) || name2Tokens[1].compare(*it2)) {
            if (!sameOriginal(name1, name2, *it + " " + *it2))
              confusingNames.insert(*it + " " + *it2);
          }
        }
      }
    }
    else {
      for(set<string>::iterator it = confused[name2Tokens[0]].begin();
          it != confused[name2Tokens[0]].end();
          it++) {
        for(set<string>::iterator it2 = confused[name2Tokens[1]].begin();
          it2 != confused[name2Tokens[1]].end();
          it2++) {
          for(set<string>::iterator it3 = confused[name2Tokens[2]].begin();
            it3 != confused[name2Tokens[2]].end();
            it3++) {
            if (name2Tokens[0].compare(*it) || name2Tokens[1].compare(*it2) || name2Tokens[2].compare(*it3)) {
              if (!sameOriginal(name1, name2, *it + " " + *it2 + " " + *it3))
                confusingNames.insert(*it + " " + *it2 + " " + *it3);
            }
          }
        }
      }
    }

    cout << "Case " << t+1 << ":" << endl;
    if (confusingNames.size() == 0) {
      cout << "None" << endl;
    }
    else {
      for(set<string>::iterator it = confusingNames.begin();
          it != confusingNames.end();
          it++) {
        cout << *it << endl;
      }
    }
  }
}
