// ARC092 C - 2D Plane 2N Points
// https://atcoder.jp/contests/arc092/tasks/arc092_a

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define START ios::sync_with_stdio(false);cin.tie(0);

int main() {
  START
  int N;
  cin >> N;
  vector<pair<int,int> > red(N), blue(N);
  REP(i, N) cin >> red[i].first >> red[i].second;
  REP(i, N) cin >> blue[i].first >> blue[i].second;

  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());

  vector<bool> used(N, false);
  int ans = 0;
  REP(i, N) {
    int selected_idx = -1;
    int max_y = -1;
    REP(j, N) {
      if (!used[j] && red[j].first < blue[i].first && red[j].second < blue[i].second && max_y < red[j].second) {
        selected_idx = j;
        max_y = red[j].second;
      }
    }
    if (selected_idx != -1) {
      used[selected_idx] = true;
      ans++;
    }
  }
  cout << ans << endl;
}