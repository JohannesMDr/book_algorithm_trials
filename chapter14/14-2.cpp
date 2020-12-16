// ABC061 D - Score Attack

#include <bits/stdc++.h>
using namespace std;
// using Graph = vector<vector<int> >;
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
struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge> >;

int main() {
  START
  int N, M;
  cin >> N >> M;
  Graph G(N);
  REP(i, M) {
    int a, b, c; cin >> a >> b >> c; --a, --b;
    G[a].push_back(Edge(b, -c));
  }

  // Bellman-Ford Algorithm
  bool is_inf = false;
  vector<ll> dist(N, INF);
  dist[0] = 0;
  REP(iter, N) {
    bool update = false;
    REP(v, N) {
      if (dist[v] == INF) continue;
      for (auto e : G[v]) {
        if (chmin(dist[e.to], dist[v] + e.w)) {
          update = true;
        }
      }
    }
    if (!update) break;
    if (iter == N-1 && update) is_inf = true;
  }

  if (is_inf) cout << "inf" << endl;
  else cout << -dist[N-1] << endl;
}