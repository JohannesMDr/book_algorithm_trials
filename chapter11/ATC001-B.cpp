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
  int N, Q;
  cin >> N >> Q;
  vector<int> p(Q), a(Q), b(Q);
  REP(i, Q) cin >> p[i] >> a[i] >> b[i];

  UnionFind uf(N);
  REP(i, Q) {
    if (p[i] == 0) {
      uf.unite(a[i], b[i]);
    } else {
      bool ans = uf.issame(a[i], b[i]);
      if (ans) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}