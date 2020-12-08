// https://qiita.com/drken/items/996d80bcae64649a6580#3-4-%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88

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
  int N, M;
  cin >> N >> M;
  Graph G(N);
  vector<int> deg(N, 0);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    G[b].push_back(a);
    deg[a]++;
  }

  queue<int> que;
  REP(i, N) if (deg[i] == 0) que.push(i);

  vector<int> order;
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    order.push_back(v);

    for (auto nv : G[v]) {
      --deg[nv];
      if (deg[nv] == 0) que.push(nv);
    }
  }

  reverse(ALL(order));
  for (auto v : order) cout << v << endl;
}