/* Alex Velazquez
 * Start: Mon Jan  6 08:40:23 EST 2014
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

string toString (int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}

string encode (string S) {
  char currentChar = ' ';
  int charCount = 0;
  string encodedString;
  string currentString;
  REP(i, SZ(S)) {
    if (S[i] == currentChar) {
      charCount++;
      currentString += currentChar;
    }
    else {
      if (charCount > 3) {
        encodedString += toString(charCount) + "!" + currentChar;
      }
      else {
        encodedString += currentString;
      }
      currentString.clear();
      currentString += S[i];
      charCount = 1;
      currentChar = S[i];
    }
  }
  if (charCount > 3) {
    encodedString += toString(charCount) + "!" + currentChar;
  }
  else {
    encodedString += currentString;
  }
  return encodedString;
}

int main ()
{
  string S;
  while (cin >> S) {
    cout << encode(S) << endl;
  }
}
