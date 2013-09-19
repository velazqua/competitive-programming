/* Alex Velazquez
 * Start: Fri Aug 16 19:37:24 EDT 2013
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

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    if (t != 0)
      cout << endl;
    int B, SG, SB;
    cin >> B >> SG >> SB;
    map<int, int> green, blue;
    int num;
    REP(i, SG) {
      cin >> num;
      green[num]++;
    }
    REP(i, SB) {
      cin >> num;
      blue[num]++;
    }
    while (green.size() > 0 && blue.size() > 0) {
      map<int, int> temp_green, temp_blue;
      REP(i, B) {
        if (green.size() == 0 || blue.size() == 0)
          break;
        map<int,int>::reverse_iterator git = green.rbegin();
        map<int,int>::reverse_iterator bit = blue.rbegin();
        int G = git->first, B = bit->first;
        if (G > B)
          temp_green[G-B]++;
        else if (B > G)
          temp_blue[B-G]++;
        git->second--;
        bit->second--;
        if (git->second == 0)
          green.erase(--git.base());
        if (bit->second == 0)
          blue.erase(--bit.base());
      }
      for(map<int, int>::iterator it = temp_green.begin();
          it != temp_green.end();
          it++) {
        green[it->first] += it->second;
      }

      for(map<int, int>::iterator it = temp_blue.begin();
          it != temp_blue.end();
          it++) {
        blue[it->first] += it->second;
      }
    }
    int gSize = green.size();
    int bSize = blue.size();
    if (gSize == 0 && bSize == 0)
      cout << "green and blue died" << endl;
    else if (bSize == 0) {
      cout << "green wins" << endl;
      for(map<int, int>::iterator it = green.begin();
          it != green.end();
          it++) {
        for(int k = 0; k < it->second; k++)
          cout << it->first << endl;
      }
    }
    else {
      cout << "blue wins" << endl;
      for(map<int, int>::iterator it = blue.begin();
          it != blue.end();
          it++) {
        for(int k = 0; k < it->second; k++)
          cout << it->first << endl;
      }
    }
  }
}
