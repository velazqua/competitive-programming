/* Alex Velazquez
 * Start: Wed Oct 31 12:27:48 EDT 2012
 * End  : Wed Oct 31 12:42:15 EDT 2012
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

int toDecimal (string S, vector<int> &pows2) {
   int size = SZ(S);
   int total = 0;
   for( int i=0; i<size; ++i ) {
      if (S[i] == '1')
         total += pows2[size-1-i];
   }
   return total;
}

int main ()
{
   vector<int> pows2(31, 1);
   for( int i=1; i<31; ++i ) {
      pows2[i] = pows2[i-1] * 2;
   }
   string token;
   int flag = 0;
   string currentVal;
   while (cin >> token) {
      if (!token.compare("~"))
         break;
      if (!token.compare("#")) {
         cout << toDecimal(currentVal, pows2) << endl;
         flag = 0;
         currentVal.clear();
         continue;
      }
      else if (!token.compare("0"))
         flag = 1;
      else if (!token.compare("00"))
         flag = 0;
      else {
         int size = SZ(token)-2;
         currentVal.append(size, char(flag+48));
      }
   }
}
