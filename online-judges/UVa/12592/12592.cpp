/* Alex Velazquez
 * Start: Sun Sep 29 16:05:01 EDT 2013
 * End  : Sun Sep 29 16:08:25 EDT 2013
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
  map<string, string> M;
  REP(t, N) {
    if (t == 0) cin.ignore();
    string firstLine, secondLine;
    getline(cin, firstLine);
    getline(cin, secondLine);
    M[firstLine] = secondLine;
  }
  int Q;
  cin >> Q;
  REP(i, Q) {
    if (i == 0) cin.ignore();
    string line;
    getline(cin, line);
    cout << M[line] << endl;
  }
}
