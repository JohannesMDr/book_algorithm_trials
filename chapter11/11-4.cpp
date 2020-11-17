// ARC090 D - People on a Line
// https://qiita.com/drken/items/cce6fc5c579051e64fab
// weighted Union-Find

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);


template<class Abel> struct WeightedUnionFind {
  vector<int> par;
  vector<Abel> diff_weight;
  WeightedUnionFind(int n, Abel SUM_UNITY = 0) : par(n, -1), diff_weight(n, SUM_UNITY) {}

  int root(int x) {
    if (par[x] == -1) return x;
    else {
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = root(par[x]);
    }
  }

  Abel weight(int x) {
    root(x);
    return diff_weight[x];
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y, Abel w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y), w = -w;
    par[x] += par[y];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }

  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

template<class Abel> struct UnionFind {
    const Abel UNITY_SUM = 0;      // to be set
    vector<int> par;
    vector<Abel> diff_weight;

    UnionFind() { }
    UnionFind(int n) : par(n, -1), diff_weight(n, UNITY_SUM) {}
    void init(int n) { par.assign(n, -1), diff_weight.assign(n, UNITY_SUM); }

    int root(int x) {
        if (par[x] < 0) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel calc_weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w = 0) {
        w += calc_weight(x); w -= calc_weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y), w = -w; // merge technique
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return calc_weight(y) - calc_weight(x);
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
  START
  int N, M;
  cin >> N >> M;
  UnionFind<ll> uf(N);
  REP(i, M) {
    int l, r, d;
    cin >> l >> r >> d;
    --l, --r;
    if (uf.issame(l, r)) {
      ll diff = uf.diff(l, r);
      if (diff != d) {
        cout << "No" << endl;
        // puts("No");
        return 0;
      }
    } else {
      uf.merge(l, r, d);
    }
  }
  cout << "Yes" << endl;
}