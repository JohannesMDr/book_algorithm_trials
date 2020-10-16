#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i >= ll(b); i--)

template<class T> void chmax(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  // dp(N+1, W+1): can make w by choosing from a[0]~a[n]?
  vector<vector<bool> > dp(N+1, vector<bool>(W+1, false));
  REP(i, N+1) dp[i][0] = true;

  FOR(i, 0, N) {
    FOR(j, 0, W+1) {
      if (j - a[i] >= 0 && dp[i][j - a[i]]) dp[i+1][j] = true;
      if (dp[i][j]) dp[i+1][j] = true;
    }
  }

  cout << dp[N][W] << endl;

}

