/* Alex Velazquez
 * Start: Mon Oct 29 15:12:46 EDT 2012
 * End  : Mon Oct 29 15:41:00 EDT 2012
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

string intToString (int n) {
   stringstream val;
   val << n;
   return val.str();
}

pair<bool, string> isPalindrome (int h, int m) {
   bool isIt;
   string result = "";
   if (!h) {
      string S1 = intToString(m);
      string S2 = S1;
      reverse(S2.begin(), S2.end());
      #if DEBUG
         cout << "S1: " << S1 << ". S2: " << S2 << endl;
      #endif
      isIt = (S1 == S2);
      result = "00:";
      result += ((m < 10) ? "0":"") + S1; 
   }
   else {
      string S1 = intToString(h);
      string S2 = "";
      if (m < 10) {
         S2 = '0';
      }
      S2 += intToString(m);
      #if DEBUG
         cout << "S1: " << S1 << ". S2: " << S2 << endl;
      #endif
      string S3 = S1+S2;
      string S4 = S3;
      reverse(S4.begin(), S4.end());
      isIt = (S3 == S4);
      result = ((h < 10) ? "0":"") + S1 + ":" + S2;
   }
   return make_pair(isIt, result);
}

int main ()
{
   int T;
   cin >> T;
   REP(t, T) {
      string time;
      cin >> time;
      int hours = (time[0]-48)*10 + (time[1]-48);
      int minutes =  (time[3]-48)*10 + (time[4]-48);
      int currTime = hours*60 + minutes;
      for( int i=1; i<=60*24; ++i) {
         int time = currTime + i;
         int h = (time / 60) % 24;
         int m = time % 60;
         pair<bool, string> result = isPalindrome(h, m); 
         if (result.first) {
            cout << result.second << endl;
            break;
         }
      }
   }
}
