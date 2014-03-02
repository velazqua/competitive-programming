#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0

using namespace std;

int main ()
{
  int N, T;
  cin >> N >> T;
  int num;
  vector<int> truckIntervalStart, truckIntervalEnd;
  vector<int> carIntervalStart, carIntervalEnd;
  int it = -1, itEnd = -1, ct = -1, ctEnd = -1;
  bool truck = false;
  bool car = false;
  for(int i = 0; i < N; i++) {
    cin >> num;
    if (num == 1) {
      truck = false;
      car = false;
      if (it >= 0) {
        itEnd = i-1;
        truckIntervalStart.push_back(it);
        truckIntervalEnd.push_back(itEnd);
        it = -1;
      }
      if (ct >= 0) {
        ctEnd = i-1;
        carIntervalStart.push_back(ct);
        carIntervalEnd.push_back(ctEnd);
        ct = -1;
      }
    }
    else if (num == 2) {
      if (!car) {
        ct = i;
      }
      truck = false;
      car = true;
      if (it >= 0) {
        itEnd = i-1;
        truckIntervalStart.push_back(it);
        truckIntervalEnd.push_back(itEnd);
        it = -1;
      }
    }
    else if (num == 3) {
      if (!car) {
        ct = i;
      }
      if (!truck) {
        it = i;
      }
      truck = true;
      car = true;
    }
  }
  if (truck) {
    truckIntervalStart.push_back(it);
    truckIntervalEnd.push_back(N-1);
  }
  if (car) {
    carIntervalStart.push_back(ct);
    carIntervalEnd.push_back(N-1);
  }

#if DEBUG
  cout << "truck intervals: " << truckIntervalStart.size() << endl;
  for(int i = 0; i < truckIntervalStart.size(); i++) {
    cout << truckIntervalStart[i] << " " << truckIntervalEnd[i] << endl;
  }
  cout << "car intervals: " << carIntervalStart.size() << endl;
  for(int i = 0; i < carIntervalStart.size(); i++) {
    cout << carIntervalStart[i] << " " << carIntervalEnd[i] << endl;
  }

#endif
  for(int t = 0; t < T; t++) {
    int i, j;
    cin >> i >> j;
    int truckSize = truckIntervalStart.size();
    int carSize = carIntervalStart.size();
    bool foundTruck = false;
    bool foundCar = false;
    for(int x = 0; x < truckSize; x++) {
      if (truckIntervalStart[x] > i) {
        break;
      }
      if (truckIntervalStart[x] <= i && i <= truckIntervalEnd[x] &&
          truckIntervalStart[x] <= j && j <= truckIntervalEnd[x]) {
        foundTruck = true;
        break;
      }
    }
    if (foundTruck) {
      cout << 3 << endl;
      continue;
    }
    for(int x = 0; x < carSize; x++) {
      if (carIntervalStart[x] > i) {
        break;
      }
      if (carIntervalStart[x] <= i && i <= carIntervalEnd[x] &&
          carIntervalStart[x] <= j && j <= carIntervalEnd[x]) {
        foundCar = true;
        break;
      }
    }
    if (foundCar) {
      cout << 2 << endl;
    }
    else {
      cout << 1 << endl;
    }
  }
}
