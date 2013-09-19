/* Alex Velazquez
 * Start: Thu May  9 17:00:54 EDT 2013
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
  int N;
  cin >> N;
  vector< vector<int> > L(N, vector<int>(N, 0));
  vector<int> V(N, 0);
  REP(i, N)
    cin >> V[i];
  for (int k = 0; k < N; k++) {
    int a = N-k;
    //cout << "a: " << a << endl;
    for(int i = 0; i < N-k; i++) {
      int j = i+k;
      int A = 0, B = 0;
      if (i >= 0 && i < N && j-1 >= 0 && j-1 <N)
        A = L[i][j-1] + V[j]*a;
      if (i+1 >= 0 && i+1 < N && j >= 0 && j <N)
        B = L[i+1][j] + V[i]*a;
      L[i][j] = max(A, B);
      //cout << "L[" << i << "," << j<<"] = " << L[i][j] << " = max(" << A << "," << B << ")" <<  endl;
    }
  }
  cout << L[0][N-1] << endl;
}
