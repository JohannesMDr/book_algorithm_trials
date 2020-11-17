#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class Abel> struct WeightedUnionFind {
  vector<int> par, siz;
  vector<Abel> diff_weight;
  WeightedUnionFind(int n, Abel SUM_UNITY = 0) : par(n, -1), siz(n, 1), diff_weight(n, SUM_UNITY) {}

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
    if (siz[x] > siz[y]) swap(x, y), w = -w;
    par[y] = x;
    siz[x] += siz[y];
    diff_weight[y] = w;
    return true;
  }

  Abel diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

