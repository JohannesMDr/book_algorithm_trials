#include <iostream>
#include <vector>
const int INF = 1e9;
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  int min = INF;
  int min2 = INF;
  for (int i = 0; i < N; ++i) {
    if ((a[i] < min2) && (a[i] > min)) {
      min2 = a[i];
    }
    if (a[i] < min) {
      min2 = min;
      min = a[i];
    }
  }
  cout << min << endl;
  cout << min2 << endl;
}