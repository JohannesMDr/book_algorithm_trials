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

vector<int> bfs(const Graph &G, int s) {
  int N = (int)G.size();
  vector<int> dist(N, -1);
  queue<int> que;

  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int x : G[v]) {
      if (dist[x] != -1) continue;
      dist[x] = dist[v] + 1;
      que.push(x);
    }
  }
  return dist;
}