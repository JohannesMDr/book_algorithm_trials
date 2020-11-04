// JOI 2007/2008 本選 問題3
// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c

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
  int N, M;
  cin >> N >> M;
  vector<int> p(N+1);
  p[0] = 0;
  FOR(i, 1, N+1) cin >> p[i];

  vector<int> sum_p;
  FOR(i, 0, N+1) {
    FOR(j, i, N+2) {
      sum_p.push_back(p[i] + p[j]);
      // cout << "sum_p(" << i << ", " << j << "): " << p[i] + p[j] << endl;
    }
  }
  sort(sum_p.begin(), sum_p.end());

  int ans = 0;
  FOR(i, 0, sum_p.size()) {
    int left = 0, right = sum_p.size() - 1;
    while (right >= left) {
      int mid = left + (right - left) / 2;
      // cout << sum_p[i] + sum_p[mid] << endl;
      if (sum_p[i] + sum_p[mid] > M) right = mid - 1;
      else if (sum_p[i] + sum_p[mid] <= M) {
        ans = max(ans, sum_p[i] + sum_p[left]);
        left = mid + 1;
      }
    }
    // ans = max(ans, sum_p[i] + sum_p[left]);
  }

  cout << ans << endl;
}