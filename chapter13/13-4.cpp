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


vector<vector<int> > dist, prev_x, prev_y;
queue<pair<int,int> > que;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main() {
  START
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  REP(i, H) cin >> field[i];

  int sx, sy, gx, gy;
  REP(h, H) {
    REP(w, W) {
      if (field[h][w] == 'S') {
        sx = h;
        sy = w;
      }
      if (field[h][w] == 'G') {
        gx = h;
        gy = w;
      }
    }
  }

  dist.assign(H, vector<int>(W, -1));
  dist[sx][sy] = 0;
  prev_x.assign(H, vector<int>(W, -1));
  prev_y.assign(H, vector<int>(W, -1));
  que.push({sx,sy});

  while (!que.empty()) {
    pair<int,int> current_pos = que.front();
    int x = current_pos.first;
    int y = current_pos.second;
    que.pop();

    REP(d, 4) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (field[nx][ny] == '#') continue;

      if (field[nx][ny] == -1) {
        que.push({nx,ny});
        dist[nx][ny] = dist[x][y] + 1;
        prev_x[nx][ny] = x;
        prev_y[nx][ny] = y;
      }
    }
  }

  int x = gx, y = gy;
  while (x != -1 && y != -1) {
    field[x][y] = 'o';
    int px = prev_x[x][y];
    int py = prev_y[x][y];
    x = px, y = py;
  }
  REP(h, H) {
    REP(w, W) {
      cout << setw(3) << field[h][w];
    }
    cout << endl;
  }
}