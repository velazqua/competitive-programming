/* Alex Velazquez
 * Start: Thu Apr 25 23:20:11 EDT 2013
 * End  : Thu Apr 25 23:27:16 EDT 2013
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
  string w1, w2;
  while (cin >> w1 >> w2) {
    vector<int> a1(26,0), a2(26,0);
    for(string::iterator it = w1.begin();
        it != w1.end();
        it++) {
      a1[*it-97]++;
    }
    for(string::iterator it = w2.begin();
        it != w2.end();
        it++) {
      a2[*it-97]++;
    }
    string answer;
    for(int i = 0; i < 26; i++) {
      if (a1[i] > 0 && a2[i] > 0)
        answer += string(min(a1[i], a2[i]), char(i+97));
    }
    cout << answer << endl;
  } 
}
