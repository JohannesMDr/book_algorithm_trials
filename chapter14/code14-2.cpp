#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);

const ll INF = 1LL << 60;

struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge> >;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  START
  int N, M, s;
  cin >> N >> M >> s;
  Graph G(N);
  REP(i, M) {
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }

  // Bellman-Ford algorithm
  bool exist_negative_cycle = false;
  vector<ll> dist(N, INF);
  dist[s] = 0;
  REP(iter, N) {
    bool update = false;
    REP(v, N) {
      if (dist[v] == INF) continue;
      for (auto e : G[v]) {
        if(chmin(dist[e.to], dist[v] + e.w)) {
          update = true;
        }
      }
    }
    if (!update) break;
    if (iter == N-1 && update) exist_negative_cycle = true;
  }

  if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
  else {
    REP(v, N) {
      if (dist[v] < INF) cout << dist[v] << endl;
      else cout << "INF" << endl;
    }
  }
}