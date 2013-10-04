/* Alex Velazquez
 * Start: Fri Oct  4 14:29:47 EDT 2013
 * End  : Fri Oct  4 15:13:56 EDT 2013 
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

int valueCard (string S) {
  char c = S[0];
  if (c >= '2' && c <= '9')
    return c-'0';
  else
    return 10;
}

int main ()
{
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case " << t+1 << ": ";
    vector<string> cards;
    REP(i, 52) {
      string hand;
      cin >> hand;
      cards.push_back(hand);
    }
    int Y = 0;
    vector<string>::iterator iterEnd = cards.begin(), iterBegin;
    advance(iterEnd, 26);
    iterBegin = iterEnd;
    REP(i, 3) {
      int X = valueCard(*iterBegin);
      Y += X;
      advance(iterBegin, ((10-X) * -1) - 1);
    }
    cards.erase(iterBegin+1, iterEnd+1);
    cout << cards[Y-1] << endl;
  }
}
