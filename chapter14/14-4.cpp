// ARC005 C
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
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

int main() {
  START
  int H, W; cin >> H >> W;
  vector<string> c(H);
  REP(i, H) cin >> c[i];
  vector<vector<int>> dist(H, vector<int>(W, INF));
  int sh, sw, gh, gw;
  REP(h, H) {
    REP(w, W) {
      if (c[h][w] == 's') sh = h, sw = w;
      if (c[h][w] == 'g') gh = h, gw = w;
    }
  }
  dist[sh][sw] = 0;
  deque<pair<int,int>> que;
  que.push_back({sh,sw});

  while (!que.empty()) {
    int h = que.front().first;
    int w = que.front().second;
    que.pop_front();

    if (h == gh && w == gw) break;
    REP(i, 4) {
      int nh = h + dy[i], nw = w + dx[i];
      if (nh < 0 || nh > H-1 || nw < 0 || nw > W-1) continue;
      if (dist[nh][nw] == INF) {
        if (c[nh][nw] == '#') {
          dist[nh][nw] = dist[h][w] + 1;
          que.push_back({nh,nw});
        } else {
          dist[nh][nw] = dist[h][w];
          que.push_front({nh,nw});
        }
      }
    }
  }

  if (dist[gh][gw] <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}