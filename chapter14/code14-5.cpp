#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);

const ll INF = 1LL << 60;

int main() {
  START
  int N, M;
  cin >> N >> M;

  vector<vector<ll> > dp(N, vector<ll>(N, INF));
  REP(e, M) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    dp[a][b] = w;
  }
  REP(v, N) dp[v][v] = 0;

  // Warshall-Floyd algorithm
  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  bool exist_negative_cycle = false;
  REP(v, N) {
    if (dp[v][v] < 0) exist_negative_cycle = true;
  }
  if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
  else {
    REP(i, N) {
      REP(j, N) {
        if (j) cout << " ";
        if (dp[i][j] < INF/2) cout << dp[i][j];
        else cout << "INF";
      }
      cout << endl;
    }
  }
}