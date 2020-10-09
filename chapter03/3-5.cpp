// ABC081 B

#include <iostream>
#include <vector>
const int INF = 1e9;
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];

  int ans = INF;
  for (int i = 0; i < N; ++i) {
    int ans_tmp = 0;
    while ((a[i] % 2) == 0) {
      ans_tmp++;
      a[i] /= 2;
    }
    ans = min(ans, ans_tmp);
  }
  cout << ans << endl;
}