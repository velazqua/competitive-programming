/* Alex Velazquez
 * Start: Sun Sep 29 17:28:34 EDT 2013
 * End  : Sun Sep 29 17:34:55 EDT 2013
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
  int N;
  cin >> N;
  REP(t, N) {
    string S;
    cin >> S;
    vector<int> nums(26, 0);
    REP(i, SZ(S)) {
      nums[S[i]-'A']++;
    }
    cout << min(nums['M'-'A'], min(nums[0]/3, min(nums['R'-'A']/2, min(nums['G'-'A'], min(nums['I'-'A'], nums['T'-'A']))))) << endl;
  }
}
