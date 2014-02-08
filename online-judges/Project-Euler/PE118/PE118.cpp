#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

#define DEBUG 0

using namespace std;

void sieve (vector<bool> &p) {
  int t = p.size();
  for (int i = 3; i < t; i += 2) {
    p[i] = true;
    p[i-1] = false;
  }
  p[0] = p[1] = false;
  p[2] = true;
  int r = ceil(sqrt(t));
  if ((t&1) == 1) p[t-1] = false;
  for (int i = 3; i < r; i += 2) {
    if (p[i]) {
      for (int j = 3; j*i < t; j += 2) {
        p[j*i] = false;
      }
    }
  }
}

pair<bool, int> unique_digits (int X) {
  vector<bool> dig(10, false);
  vector<int> digits;
  while (X > 0) {
    int d = X%10;
    digits.push_back(d);
    if (dig[d] || d == 0) {
      return {false, 0};
    }
    else {
      dig[d] = true;
    }
    X /= 10;
  }
  sort(digits.begin(), digits.end());
  reverse(digits.begin(), digits.end());
  int newX = 0;
  int ten = 1;
  for(auto& d : digits) {
    newX += (d * ten);
    ten *= 10;
  }
  return {true, newX};
}

int number_size (int X) {
  int sz = 0;
  while (X) {
    sz++;
    X /= 10;
  }
  return sz;
}

vector<int> getDigits (int X) {
  vector<int> digits;
  while (X) {
    int d = X%10;
    digits.push_back(d);
    X /= 10;
  }
  return digits;
}

void update_used(vector<bool>& used, vector<int>& digits, bool status) {
  for(auto& d : digits) {
    used[d] = status;
  }
}

bool ableToAdd (vector<bool> &used, vector<int> &digits) {
  for(auto& d : digits) {
    if (used[d])
      return false;
  }
  return true;
}

void displayUsed (vector<bool>& used) {
  cout << "used: ";
  for(int i = 1; i <= 9; i++) {
    cout << used[i] << " ";
  }
  cout << endl;
}

void displaySet (vector<int>& st) {
  cout << "setsUsed: {";
  for(auto& e : st) {
    cout << e << ", ";
  }
  cout << "}" << endl;
}

void recurse (map<int,int>::iterator it,
              int &currSum,
              vector<bool>& used,
              vector<int>& setsUsed,
              int &numberSize,
              map<int,int>& num_class) {
#if DEBUG
  cout << "it: " << it->first << endl;
  cout << "currSum: " << currSum << endl;
  displayUsed(used);
  displaySet(setsUsed);
  cout << "numberSize: " << numberSize << endl;
#endif
  if (numberSize == 9) {
    int prod = 1;
    for (auto& n : setsUsed) {
      prod *= num_class[n];
    }
    currSum += prod;
  }
  else {
    for(; it != num_class.end(); it++) {
      vector<int> digits = getDigits(it->first);
      if (ableToAdd(used, digits)) {
        int sz = number_size(it->first);
        if ((9-numberSize-sz != 0) && (9-numberSize-sz < sz)) continue;
        update_used(used, digits, true);
        setsUsed.push_back(it->first);
        numberSize += sz;
        recurse(it, currSum, used, setsUsed, numberSize, num_class);
        update_used(used, digits, false);
        setsUsed.pop_back();
        numberSize -= sz;
      }
    }
  }
}

int main ()
{
  int LIMIT = 100000000;
  vector<bool> primes(LIMIT);
  sieve(primes);
  map<int, int> number_classes;
  number_classes[2]++;
  for (int i = 3; i < LIMIT; i += 2) {
    if (primes[i]) {
      auto result = unique_digits(i);
      if (result.first) {
        number_classes[result.second]++;
      }
    }
  }
  int currSum = 0;
  vector<bool> used(10, false);
  vector<int> setsUsed;
  int numberSize = 0;
  recurse(number_classes.begin(), currSum, used, setsUsed, numberSize, number_classes);
  cout << currSum << endl;
}
