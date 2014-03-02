/* Alex Velazquez
 * Start: Sun Sep 29 16:47:16 EDT 2013
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

pair<string, string> processNumber (string line) {
  pair<string, string> P = make_pair("", "");
  int c = 0;
  string curr;
  REP(i, SZ(line)) {
    if (line[i] >= '0' && line[i] <= '9') {
      curr += line[i];
    }
    if (line[i] == '-')
      continue;
    if (line[i] == 'A' || line[i] == 'B' || line[i] == 'C')
      curr += '2';
    if (line[i] == 'D' || line[i] == 'E' || line[i] == 'F')
      curr += '3';
    if (line[i] == 'H' || line[i] == 'G' || line[i] == 'I')
      curr += '4';
    if (line[i] == 'J' || line[i] == 'K' || line[i] == 'L')
      curr += '5';
    if (line[i] == 'M' || line[i] == 'N' || line[i] == 'O')
      curr += '6';
    if (line[i] == 'P' || line[i] == 'R' || line[i] == 'S')
      curr += '7';
    if (line[i] == 'T' || line[i] == 'U' || line[i] == 'V')
      curr += '8';
    if (line[i] == 'W' || line[i] == 'X' || line[i] == 'Y')
      curr += '9';
    if (line[i] >= 'A' && line[i] <= 'Z' || line[i] >= '0' && line[i] <= '9')
      c++;
    if (c == 3) {
      P.first = curr;
      curr.clear();
    }
  }
  P.second = curr;
  return P;
}

int main ()
{
  int T;
  cin >> T;
  REP(i, T) {
    if (i > 0)
      cout << endl;
    int N;
    cin >> N;
    map<pair<string, string>, int> M;
    REP(k, N) {
      string line;
      cin >> line;
      pair<string, string> phone = processNumber(line);
      M[phone]++;
    }
    bool duplicates = false;
    for(map<pair<string, string>, int>::iterator it = M.begin();
        it != M.end();
        it++) {
      if (it->second > 1) {
        duplicates = true;
        cout << it->first.first << "-" << it->first.second << " " << it->second << endl;
      }
    }
    if (!duplicates) {
      cout << "No duplicates." << endl;
    }
  }
}
