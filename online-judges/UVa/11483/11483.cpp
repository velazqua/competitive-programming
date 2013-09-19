/* Alex Velazquez
 * Start: Mon Oct 29 14:39:24 EDT 2012
 * End  : Mon Oct 29 15:08:30 EDT 2012
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
   int N;
   int c = 1;
   while(cin >> N) {
      if (!N) {
         break;
      }
      cout << "Case " << c++ << ":" << endl;
      cout << "#include<string.h>\n#include<stdio.h>\nint main()\n{" << endl;
      REP( i, N ) {
         string line;
         while (getline(cin, line) && line == "");
         cout << "printf(\"";
         int size = SZ(line);
         REP( k, size ) {
            if (line[k] == '"') {
               cout << '\\';
               cout << "\"";
            }
            else if (line[k] == '\\') {
               cout  << "\\\\";
            }
            else {
               cout << line[k];
            }
         }
         cout << "\\n\");" << endl;
      }
      cout << "printf(\"\\n\");\nreturn 0;\n}" << endl;
   }
}
