#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ulld;

string toString (ulld num) {
  stringstream ss;
  ss << num;
  return ss.str();
}

ulld toInt (string s) {
  ulld num = 0;
  reverse(s.begin(), s.end());
  ulld pw = 1;
  for(string::iterator it = s.begin();
      it != s.end();
      it++) {
    if (*it == '9') {
      num += pw * 9;
    }
    pw *= 10;
  }
  return num;
}

int main ()
{
  set<ulld> allNums;
  set<string> S;
  S.insert("0");
  S.insert("9");
  for(int i = 0; i < 12; i++) {
    set<string> Q;
    for(set<string>::iterator it = S.begin();
        it != S.end();
        it++) {
      Q.insert("0" + *it);
      Q.insert("9" + *it);
    }
    for(set<string>::iterator it = Q.begin();
        it != Q.end();
        it++) {
      allNums.insert(toInt(*it));
    }
    S = Q;
  }
  vector<bool> done(501, false);
  vector<ulld> ans(501, 0);
  for(set<ulld>::iterator it = allNums.begin();
      it != allNums.end();
      it++) {
    ulld num = *it;
    for(int n = 1; n <= 500; n++) {
      if (done[n])
        continue;
      if (n > num)
        break;
      if (num % n == 0) {
        done[n] = true;
        ans[n] = num;
      }
    }
  }
  for(int i = 1; i <= 500; i++) {
    cout << ans[i] << ",";
  }
  cout << endl;
  return 0;
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
}
