#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> A(N, 0);
  for(int i = 0; i < N; i++)
    cin >> A[i];
  K = K % N;
  for(int i = 0; i < Q; i++) {
    int x;
    cin >> x;
    cout << A[(N+x-K)%N] << endl;
  }
}
