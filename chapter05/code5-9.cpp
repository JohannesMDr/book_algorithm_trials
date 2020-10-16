#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i >= ll(b); i--)

template<class T> void chmin(T& a, T b) {
  if (a > b) a = b;
}

const ll INF = 1 << 60;

int main() {
  int N;
  cin >> N;
  vector<vector<ll> > c(N+1, vector<ll>(N+1));
  REP(i, N+1) {
    REP(j, N+1) cin >> c[i][j];
  }

  vector<ll> dp(N+1, INF);
  dp[0] = 0;

  REP(i, N+1) {
    REP(j, i) {
      chmin(dp[i], dp[j] + c[j][i]);
    }
  }

  cout << dp[N] << endl;
}

