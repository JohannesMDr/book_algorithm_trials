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

  // Dijkstra algorithm
  vector<bool> used(N, false);
  vector<ll> dist(N, INF);
  dist[s] = 0;
  REP(iter, N) {
    ll min_dist = INF;
    int min_v = -1;
    REP(v, N) {
      if (!used[v] && dist[v] < min_dist) {
        min_dist = dist[v];
        min_v = v;
      }
    }

    if (min_v == -1) break;
    for (auto e : G[min_v]) {
      chmin(dist[e.to], dist[min_v] + e.w);
    }
    used[min_v] = true;
  }

  REP(v, N) {
    if (dist[v] < INF) cout << dist[v] << endl;
    else cout << "INF" << endl;
  }
}