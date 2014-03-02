/* Alex Velazquez
 * Start: Sun Nov 24 16:00:59 EST 2013
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
  int T;
  cin >> T;
  cin.ignore();
  REP(t, T) {
    if (t != 0)
      cout << endl;
    string line;
    int n;
    cin >> n;
    cin.ignore();
    vector<string> candidates;
    REP(i, n) {
      string name;
      getline(cin, name);
      candidates.push_back(name);
    }
    vector< vector<int> > choices;
    while (getline(cin, line)) {
      if (!line.compare("")) break;
      int num;
      vector<int> votes;
      istringstream ss(line);
      REP(k, n) {
        ss >> num;
        votes.push_back(num);
      }
      choices.push_back(votes);
    }
    vector<bool> deleted(n+1, false);
    bool found = false;
    while (!found) {
      // find the candidate with most votes
      // also find the candidate with less votes
      vector<int> mostVotes, lessVotes;
      vector<int> currentVotes(n+1, 0);
      int maxVotes = 0, minVotes = 10000;
      for(vector< vector<int> >::iterator it = choices.begin();
          it != choices.end();
          it++) {
        if (it->empty()) {
          choices.erase(it);
        }
        currentVotes[it->at(0)]++;
      }
      for(int i = 1; i < n+1; i++) {
        if (deleted[i]) continue;
        if (currentVotes[i] > maxVotes) {
          maxVotes = currentVotes[i];
          mostVotes.clear();
          mostVotes.push_back(i);
        }
        else if (currentVotes[i] == maxVotes) {
          mostVotes.push_back(i);
        }

        if (currentVotes[i] < minVotes) {
          minVotes = currentVotes[i];
          lessVotes.clear();
          lessVotes.push_back(i);
        }
        else if (currentVotes[i] == minVotes) {
          lessVotes.push_back(i);
        }
      }

      if ((mostVotes.size() == 1 && maxVotes > n/2) || (mostVotes == lessVotes)) {
        for(vector<int>::iterator it = mostVotes.begin();
            it != mostVotes.end();
            it++) {
          cout << candidates[*it-1] << endl;
          found = true;
        }
      }
      else {
        // remove the less popular candidates
        for(vector< vector<int> >::iterator it = choices.begin();
          it != choices.end();
          it++) {
          for(vector<int>::iterator cIt = lessVotes.begin();
              cIt != lessVotes.end();
              cIt++) {
            deleted[*cIt] = true;
#if DEBUG
            cout << "Deleting: " << *cIt << endl;
#endif
            vector<int>::iterator f = find(it->begin(), it->end(), *cIt);
            while (f != it->end()) {
              it->erase(f);
              f = find(it->begin(), it->end(), *cIt);
            }
          }
        }
      }
    }
  }
}
