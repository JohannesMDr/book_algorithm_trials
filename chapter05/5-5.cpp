#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)

template<class T> void chmax(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  vector<vector<bool> > dp(N+1, vector<bool>(W+1, 0));
  dp[0][0] = 1;

  FOR(i, 0, N) {
    FOR(j, 0, W+1) {
      if (j - a[i] >= 0 && dp[i+1][j-a[i]]) dp[i+1][j] = 1;
      if (dp[i][j]) dp[i+1][j] = 1;
    }
  }
  cout << dp[N][W] << endl;
}

