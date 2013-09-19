/* Alex Velazquez
 * Start: Wed Oct 31 23:52:19 EDT 2012
 * End  : Thu Nov  1 00:01:56 EDT 2012
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

int main ()
{
   string line;
   vector<string> cities;
   map< pair<char,char>, int > M;
   while (getline(cin, line)) {
      if (!line.compare("#"))
         break;
      if (line[0] == 'e') {
         int size = SZ(cities);
         int maxx = 0;
         int ans = 0;
         REP( i, size ) {
            int total = 0;
            total += M[make_pair(cities[i][0],cities[i][2])];
            total += M[make_pair(cities[i][4],cities[i][6])];
            total += M[make_pair(cities[i][8],cities[i][10])];
            total += M[make_pair(cities[i][12],cities[i][14])];
            total += M[make_pair(cities[i][16],cities[i][18])];
            if (total > maxx) {
               maxx = total;
               ans = i+1;
            }
         }
         cout << ans << endl;
         M.clear();
         cities.clear();
      }
      else {
         M[make_pair(line[0],line[2])]++;
         M[make_pair(line[4],line[6])]++;
         M[make_pair(line[8],line[10])]++;
         M[make_pair(line[12],line[14])]++;
         M[make_pair(line[16],line[18])]++;
         cities.PB(line);
      }
   }
}
