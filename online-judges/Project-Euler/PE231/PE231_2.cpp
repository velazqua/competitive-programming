#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<int> num;
  vector<int> den;
  int NUM = 20000000, DEN = 5000000;
  while (NUM > 15000000 && DEN >= 2) {
    cout << "NUM: " << NUM << ". DEN: " << DEN << endl;
    if (NUM % DEN == 0) {
      DEN--;
      NUM--;
      num.push_back(NUM/DEN);
    }
    else {
      num.push_back(NUM);
      NUM--;
    }
  }
  for( ; NUM > 15000000; NUM--)
    num.push_back(NUM);
  for( ; DEN >= 2; DEN--) {
    den.push_back(DEN);
  }

}
