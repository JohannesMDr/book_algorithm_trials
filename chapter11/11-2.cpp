// ABC120 D - Decayed Bridges

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
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll> > v(M);
  REP(i, M) {
    ll a, b;
    cin >> a >> b;
    v[i].first = --a;
    v[i].second = --b;
  }

  vector<ll> ans(M);
  ans[M-1] = N * (N-1) / 2;

  UnionFind uf(N);
  FORD(i, M-1, 0) {
    if (uf.issame(v[i].first, v[i].second)) {
      ans[i-1] = ans[i];
    } else {
      ans[i-1] = ans[i] - uf.size(v[i].first) * uf.size(v[i].second);
      uf.unite(v[i].first, v[i].second);
    }
  }

  REP(i, M) {
    cout << ans[i] << endl;
  }
}