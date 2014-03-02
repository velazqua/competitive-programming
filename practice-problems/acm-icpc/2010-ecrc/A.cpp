#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

struct Triple {
  string n1;
  string n2;
  int cost;
  Triple (string N1, string N2, int C) : n1(N1), n2(N2), cost(C) {}
};


int numBits(unsigned x)
{
      x = x - ((x >> 1) & 0x55555555);
          x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
              x = (x + (x >> 4)) & 0x0F0F0F0F;
                  x = x + (x >> 8);
                      x = x + (x >> 16);
                          return x & 0x0000003F;
}

int main ()
{
  int N;
  cin >> N;
  set<string> allNames;
  vector<Triple> edges;
  map<string, int> nameToID;
  for(int i = 0; i < N; i++) {
    string n1, n2;
    int cost;
    cin >> n1 >> n2 >> cost;
    allNames.insert(n1);
    allNames.insert(n2);
    edges.push_back(Triple(n1, n2, cost));
  }
  int id = 0;
  int park;
  for(set<string>::iterator it = allNames.begin();
      it != allNames.end();
      it++) {
    if (!(*it).compare("Park"))
      park = id;
    cout << "Name: " << *it << ". id: " << id << endl;
    nameToID[*it] = id++;
  }
  int maxCars;
  cin >> maxCars;
  int numPeople = allNames.size();
  vector< vector<int> > dist(numPeople, vector<int>(numPeople, 200000000));
  for(int i = 0; i < numPeople; i++)
    dist[i][i] = 0;
  for(vector<Triple>::iterator it = edges.begin();
      it != edges.end();
      it++) {
    int c1 = nameToID[it->n1];
    int c2 = nameToID[it->n2];
    dist[c1][c2] = it->cost;
    dist[c2][c1] = it->cost;
  }
  for(int k = 0; k < numPeople; k++)
    if (k != park)
    for(int i = 0; i < numPeople; i++)
      for(int j = 0; j < numPeople; j++)
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
  for(int i = 0; i < numPeople; i++)
    for(int j = 0; j < numPeople; j++)
      cout << "i: " << i << ". j: " << j << ". dist: " << dist[i][j] << endl;
  int miles = 200000000;
  for(int i = 0; i < (1<<numPeople); i++) {
    if (numBits(i) <= maxCars && ((1<<park)&i) == 0) {
      vector<int> cars;
      cout << "Ks: " << endl;
      for(int k = 0; k < numPeople; k++) {
        if ((i&(1<<k)) > 0) {
          cars.push_back(k);
          cout << k << " ";
        }
      }
      cout << endl;
      int carsSize = cars.size();
      int totalCost = 0;
      for(int k = 0; k < numPeople; k++) {
        int minn = 200000000;
        if (k == park) continue;
        for(int j = 0; j < carsSize; j++) {
          minn = min(minn, dist[k][cars[j]]);
        }
        cout << "Car: " << k << ". minDist: " << minn << endl;
        totalCost += minn;
      }
      cout << "cost of trips to places: " << totalCost << endl;
      for(int k = 0; k < carsSize; k++) {
        totalCost += dist[cars[k]][park];
      }
      cout << "i: " << i << ". " << totalCost << endl;
      miles = min(miles, totalCost);
    }
  }
  cout << "Total miles driven: " << miles << endl;
}
