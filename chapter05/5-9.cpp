// AtCoder Educational DP Contest N - Slimes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define START ios::sync_with_stdio(false);cin.tie(0);

template<class T> void chmax(T& a, T b) {
  if (a < b) a = b;
}
ll INF = 9e10;

int main() {
  START
  int N;
  cin >> N;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  vector<ll> pref(N+1);
  // pref[0] = 0;
  REP(i, N) pref[i+1] = pref[i] + a[i];

  vector<vector<ll> > dp(N, vector<ll>(N));
  // REP(i, N) {
  for (int i = N-1; i >= 0; i--) {
    FOR(j, i+1, N) {
      dp[i][j] = 9e18;
      FOR(k, i, j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
      }
      dp[i][j] += pref[j+1] - pref[i];
    }
  }
  cout << dp[0][N-1] << '\n';
  return 0;
}

