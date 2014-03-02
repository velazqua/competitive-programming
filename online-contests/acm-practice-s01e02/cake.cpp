#include <iostream>
#include <vector>

using namespace std;

double getArea(vector<double>& points) {
  int size = points.size()/2;
  double area = 0.0;
  for(int i = 0; i < size; i++) {
    area += (points[(2*i)%size]*points[(2*i+3)%size]-points[(2*i+1)%size]*points[(2*i+2)%size]/2.0;
  }
  return abs(area);
}

int main ()
{
  while (true) {
    vector<double> points(8);
    bool done = true;
    for(int i = 0; i < 8; i++) {
      cin >> points[i];
      if (points[i] != 0)
        done = false
    }
    if (done)
      break;
    double totalArea = getArea(points);
    //add midpoints
    for(int i = 0; i < 4; i++) {
      points.insert(points.begin()+2*i+1
    }
  }
}
