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

vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
  color[v] = cur;
  for (auto next_v : G[v]) {
    if (color[next_v] != -1) {
      if (color[next_v] == cur) return false;
      continue;
    }
    if (!dfs(G, next_v, 1-cur)) return false;
  }
  return true;
}

int main() {
  START
  int N, M;
  cin >> N >> M;
  Graph G(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  color.assign(N, -1);
  bool is_bipartite = true;
  REP(v, N) {
    if (color[v] != -1) continue;
    if (!dfs(G, v)) is_bipartite = false;
  }
  if (is_bipartite) cout << "Yes" << endl;
  else cout << "No" << endl;
}