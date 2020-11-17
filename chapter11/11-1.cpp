// ABC075 C - Bridge

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}

  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);

    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x) {
    return siz[root(x)];
  }
};

int main() {
  START
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > v(M);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    v[i].first = --a;
    v[i].second = --b;
  }

  int ans = 0;
  REP(i, M) {
    UnionFind uf(N);
    REP(j, M) {
      if (i == j) continue;
      else uf.unite(v[j].first, v[j].second);
    }
    if (uf.size(0) != N) ans++;
  }
  cout << ans << endl;
}