/* Alex Velazquez
 * Start: Mon Sep 30 12:18:44 EDT 2013
 * End  : Mon Sep 30 12:58:09 EDT 2013
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

struct Weight {
  string L;
  string R;
  string O;
  Weight (string l, string r, string o) : L(l), R(r), O(o) {}
};

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    vector<Weight> weights;
    REP(k, 3) {
      string a, b, w;
      cin >> a >> b >> w;
      weights.push_back(Weight(a, b, w));
    }
    // For each coin, assume it is the counterfeit. If all rules
    // are not broken, then it is the counterfeit.
    for(int i = 0; i < 12; i++) {
      char c = 'A'+i;
      bool isHeavier = false, isLighter = false;
      bool looksGood = true;
      for(vector<Weight>::iterator it = weights.begin();
          it != weights.end();
          it++) {
        size_t f1 = it->L.find(c);
        size_t f2 = it->R.find(c);
        if (f1 == string::npos && f2 == string::npos && (it->O).compare("even")) {
          looksGood = false;
          break;
        }
        else if (f1 != string::npos) {
          if (!(it->O).compare("up")) {
            isHeavier = true;
          }
          else if (!(it->O).compare("down")) {
            isLighter = true;
          }
          else {
            looksGood = false;
            break;
          }
        }
        else if (f2 != string::npos) {
          if (!(it->O).compare("up")) {
            isLighter = true;
          }
          else if (!(it->O).compare("down")) {
            isHeavier = true;
          }
          else {
            looksGood = false;
            break;
          }
        }
 
      }
      if (looksGood && ((isHeavier && !isLighter) || (!isHeavier && isLighter)) ){
        cout << c << " is the counterfeit coin and it is " << ((isHeavier) ? "heavy." : "light.") << endl;
      }
    }
  }
}
