/* Alex Velazquez
 * Start: Sun Sep 29 17:35:15 EDT 2013
 * End  : Sun Sep 29 17:42:36 EDT 2013
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

string isNice (string S) {
  int A = (S[0]-'A')*26*26 + (S[1]-'A')*26 + S[2]-'A';
  int B = (S[4]-'0')*1000 + (S[5]-'0')*100 + (S[6]-'0')*10 + S[7]-'0';
  if (abs(A-B) <= 100)
    return "nice";
  else
    return "not nice";
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    string S;
    cin >> S;
    cout << isNice(S) << endl;
  }
}
