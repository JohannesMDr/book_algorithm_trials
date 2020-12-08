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
queue<int> que;

bool bfs(const Graph &G, int s) {
  color[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int next_v : G[v]) {
      if (color[next_v] != -1) {
        if (color[v] == color[next_v]) return false;
      }
      color[next_v] = color[v] + 1;
      que.push(next_v);
    }
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
    if (!bfs(G, v)) is_bipartite = false;
  }
  if (is_bipartite) cout << "Yes" << endl;
  else cout << "No" << endl;
}