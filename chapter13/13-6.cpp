// https://qiita.com/drken/items/996d80bcae64649a6580#3-5-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891

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
  int N;
  cin >> N;
  Graph G(N);
  vector<int> deg(N, 0);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
    ++deg[a], ++deg[b];
  }

  queue<int> que;
  REP(v, N) if (deg[v] == 1) que.push(v);

  vector<bool> is_pushed(N, false);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    is_pushed[v] = true;
    for (auto nv : G[v]) {
      --deg[nv];
      if (deg[nv] == 1) que.push(nv);
    }
  }

  int Q; cin >> Q;
  REP(_, Q) {
    int a, b; cin >> a >> b; --a, --b;
    if (!is_pushed[a] && !is_pushed[b]) cout << 2 << endl;
    else cout << 1 << endl;
  }
}