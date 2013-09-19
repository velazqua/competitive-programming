/* Alex Velazquez
 * Start: Thu Sep  5 14:02:05 EDT 2013
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
    int N, M;
    cin >> N >> M;
    map<int, int> list1, list2;
    set<int> allNumbers;
    int num;
    REP(i, N) {
      cin >> num;
      allNumbers.insert(num);
      list1[num]++;
    }
    REP(i, M) {
      cin >> num;
      allNumbers.insert(num);
      list2[num]++;
    }
    int total = 0;
    for(set<int>::iterator it = allNumbers.begin();
        it != allNumbers.end();
        it++) {
      total += abs(list1[*it]-list2[*it]);
    }
    cout << total << endl;
  }
}
