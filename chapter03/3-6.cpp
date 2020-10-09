// ABC051 B

#include <iostream>
#include <vector>
const int INF = 1e9;
using namespace std;

int main() {
  int K, S;
  cin >> K >> S;

  int ans = 0;
  for (int i = 0; i <= K; ++i) {
    for (int j = 0; j <= K; ++j) {
      if ((S - i - j >= 0) & (S - i - j <= K)) ans++;
    }
  }
  cout << ans << endl;
}