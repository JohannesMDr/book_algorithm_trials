#include <iostream>
#include <vector>
const int INF = 1e9;
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  int minimum = INF;
  int maximum = -1;
  for (int i = 0; i < N; ++i) {
    if (a[i] < minimum) {
      minimum = a[i];
    }
    if (a[i] > maximum) {
      maximum = a[i];
    }
  }
  cout << maximum - minimum << endl;
}