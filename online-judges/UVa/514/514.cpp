/* Alex Velazquez
 * Start: Sat Aug 24 00:28:00 EDT 2013
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
#include <stack>
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
  int c = 0;
  while (cin >> N) {
    if (!N)
      break;
    bool notDone = true;
    while (notDone) {
      stack<int> st;
      vector<int> order;
      REP(i, N) {
        int num;
        cin >> num;
        if (num == 0) {
          notDone = false;
          break;
        }
        order.push_back(num);
      }
      if (!notDone)
        break;
      int i = 0;
      int currentNumber = 1;
      while (currentNumber <= N+1 && i < N) {
        /*
        cout << "currentNumber: " << currentNumber;
        cout << ". i: " << i;
        cout << ". order[i]: " << order[i] << endl;
        */
        if (order[i] != currentNumber) {
          if (!st.empty() && (st.top() == order[i])) {
            st.pop();
            i++;
          }
          else {
            st.push(currentNumber);
            currentNumber++;
          }
        }
        else {
          currentNumber++;
          i++;
        }
      }
      if (i == N && st.empty())
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
      c++;
    }
    cout << endl;
  }
}
