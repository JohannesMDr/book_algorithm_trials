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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int rec(Graph &G, vector<int> &dp, int v) {
  if (dp[v] != -1) return dp[v];

  int res = 0;
  for (auto nv : G[v]) {
    chmax(res, rec(G, dp, nv) + 1);
  }
  return dp[v] = res;
}

int main() {
  START
  int N, M;
  cin >> N >> M;
  Graph G(N);
  REP(i, M) {
    int x, y; cin >> x >> y; --x, --y;
    G[x].push_back(y);
  }

  vector<int> dp(N);
  REP(v, N) dp[v] = -1;

  int res = 0;
  REP(v, N) chmax(res, rec(G, dp, v));
  cout << res << endl;
}