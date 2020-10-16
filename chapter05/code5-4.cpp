// AtCoder Educational DP Contest A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> void chmin(T& a, T b) {
  if (a > b) a = b;
}

const ll INF = 1LL << 60;

int main() {
  int N;
  cin >> N;
  vector<ll> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];

  vector<ll> dp(N, INF);
  dp[0] = 0;

  for (int i = 0; i < N; ++i) {
    if (i + 1 < N) chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
    if (i + 2 < N) chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
  }

  cout << dp[N-1] << endl;
}