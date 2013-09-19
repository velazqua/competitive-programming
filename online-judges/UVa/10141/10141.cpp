/* Alex Velazquez
 * Start: Sun Sep  1 13:35:15 EDT 2013
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

struct Proposal {
  int id_;
  string name_;
  double price_;
  int rMet_;
  Proposal(int id, string name, double price, int rMet) :
    id_(id), name_(name), price_(price), rMet_(rMet) {}
};

bool operator < (Proposal const& A, Proposal const& B) {
  if (A.rMet_ != B.rMet_)
    return A.rMet_ > B.rMet_;
  else if (A.price_ != B.price_)
    return A.price_ < B.price_;
  else
    return A.id_ < B.id_;
}

int main ()
{
  int numRequirements, numProposals;
  int c = 1;
  while (cin >> numRequirements >> numProposals) {
    if (!numRequirements && !numProposals)
      break;
    if (c > 1)
      cout << endl;
    REP(i, numRequirements) {
      string r;
      if (i == 0) cin.ignore();
      getline(cin, r);
    }
    set<Proposal> P;
    REP(i, numProposals) {
      string name;
      getline(cin, name);
      double d;
      int rMet;
      cin >> d >> rMet;
      REP(j, rMet) {
        string reqMet;
        if (j == 0) cin.ignore();
        getline(cin, reqMet);
      }
      P.insert(Proposal(i, name, d, rMet));
    }
    cout << "RFP #" << c++ << endl;
    cout << P.begin()->name_ << endl;
  }
}
