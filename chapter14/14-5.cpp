// ARC084 D - Small Multiple
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

const int INF = 1LL << 30;

int main() {
  START
  int K; cin >> K;

  vector<int> dist(K, INF);
  vector<bool> seen(K);
  deque<int> que;
  que.push_back(1);
  dist[1] = 1;
  while (!que.empty()) {
    int v = que.front(); que.pop_front();
    if (seen[v]) continue;
    seen[v] = true;
    if (dist[(v+1)%K] > dist[v] + 1) {
      dist[(v+1)%K] = dist[v] + 1;
      que.push_back((v+1)%K);
    }
    if (dist[(v*10)%K] > dist[v]) {
      dist[(v*10)%K] = dist[v];
      que.push_front((v*10)%K);
    }
  }
  cout << dist[0] << endl;
}