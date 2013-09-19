/* Alex Velazquez
 * Start: Tue Oct 30 15:21:15 EDT 2012
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

typedef unsigned long long int ULL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

int main ()
{
   vector<ULL> factorials(21, 1ULL);
   for( ULL i=2ULL; i<21ULL; ++i ) {
      factorials[i] = factorials[i-1] * i;
   }
   int N;
   cin >> N;
   REP(i, N) {
      string S;
      if (i == 0) 
         cin.ignore();
      getline(cin, S);
      vector<int> occur(30, 0);
      int size = SZ(S);
      REP(k, size) {
         occur[S[k]-'A']++;
      }
      cout << "Data set " << i+1 << ": ";
      if (!S.compare("")) {
         cout << 1 << endl;
      }
      else {
         ULL result = factorials[size];
         REP(k, 29) {
            if (occur[k] > 1) {
               result /= factorials[occur[k]];
            }
         }
         cout << result << endl;
      }
   }
}
