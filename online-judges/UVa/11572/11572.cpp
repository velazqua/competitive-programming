/* Alex Velazquez
 * Start: Fri Aug 16 18:55:31 EDT 2013
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
    int N;
    cin >> N;
    deque<int> ourList;
    map<int, int> M;
    int first_element = 0;
    int maxx = 0;
    REP(i, N) {
      int num;
      cin >> num;
      map<int, int>::iterator f = M.find(num);
      ourList.push_back(num);
      if (f == M.end()) { 
        M.insert(make_pair(num, i));
      }
      else if (f->second == -1)  {
        M[num] = i;
      }
      else {
        int index = f->second;
        for(int k = first_element; k <= index; k++) {
          M[ourList[k]] = -1;
        }
        M[num] = i;
        first_element = index + 1;
      }
      maxx = max(maxx, i-first_element+1);
    }
    cout << maxx << endl;
  }
}
