// ABC132 E - Hopscotch Addit
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

int main() {
  START
  int N, M; cin >> N >> M;
  Graph G(N);
  REP(i, M) {
    int u, v; cin >> u >> v; --u, --v;
    G[u].push_back(v);
  }
  int s, t; cin >> s >> t; --s, --t;

  vector<vector<ll>> dist(N, vector<ll>(3, -1));
  dist[s][0] = 0;
  queue<pair<int,int>> que;
  que.push({s, 0});
  while (!que.empty()) {
    pair<int,int> cur = que.front(); que.pop();
    int v = cur.first, parity = cur.second;
    for (auto nv : G[v]) {
      int np = (parity + 1) % 3;
      if (dist[nv][np] == -1) {
        dist[nv][np] = dist[v][parity] + 1;
        que.push({nv, np});
      }
    }
  }
  if (dist[t][0] == -1) cout << "-1" << endl;
  else cout << dist[t][0] / 3 << endl;
}