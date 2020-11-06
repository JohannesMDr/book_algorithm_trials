#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define START ios::sync_with_stdio(false);cin.tie(0);

using Interval = pair<int, int>;

bool cmp(const Interval &a, const Interval &b) {
  return a.second < b.second;
}

int main() {
  START
  int N;
  cin >> N;
  vector<Interval> inter(N);
  REP(i, N) cin >> inter[i].first >> inter[i].second;

  sort(inter.begin(), inter.end(), cmp);

  int res = 0;
  int current_end_time = 0;
  REP(i, N) {
    if (inter[i].first < current_end_time) continue;
    ++res;
    current_end_time = inter[i].second;
  }
  cout << res << endl;
}