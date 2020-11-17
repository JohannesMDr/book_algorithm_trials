// ABC049 D - 連結

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
  int N, K, L;
  cin >> N >> K >> L;
  vector<pair<int, int> > road(K), train(L);
  REP(i, K) {
    int p, q;
    cin >> p >> q;
    road[i].first = --p;
    road[i].second = --q;
  }
  REP(i, L) {
    int r, s;
    cin >> r >> s;
    train[i].first = --r;
    train[i].second = --s;
  }

  UnionFind uf_road(N), uf_train(N);
  REP(i, K) uf_road.unite(road[i].first, road[i].second);
  REP(i, L) uf_train.unite(train[i].first, train[i].second);

  vector<pair<int,int> > ans(N);
  map<pair<int,int>, int> mp;
  REP(i, N) {
    ans[i] = {uf_road.root(i), uf_train.root(i)};
    mp[ans[i]]++;
  }

  REP(i, N) {
    if (i != N-1) cout << mp[ans[i]] << " ";
    else cout << mp[ans[i]] << endl;
  }
}