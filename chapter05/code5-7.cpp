// AtCoder Educational DP Contest D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i >= ll(b); i--)

template<class T> void chmax(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int N;
  ll W;
  cin >> N >> W;
  vector<ll> weight(N), value(N);
  REP(i, N) cin >> weight[i] >> value[i];

  vector<vector<ll> > dp(N+1, vector<ll>(W+1, 0));

  REP(i, N) {
    for (int w = 0; w <= W; ++w) {
      if (w - weight[i] >= 0) {
        chmax(dp[i+1][w], dp[i][w-weight[i]] + value[i]);
      }
      chmax(dp[i+1][w], dp[i][w]);
    }
  }

  cout << dp[N][W] << endl;
}

