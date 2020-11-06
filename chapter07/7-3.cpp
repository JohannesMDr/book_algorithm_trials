// ABC131 D - Megalomania
// https://atcoder.jp/contests/abc131/tasks/abc131_d

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
  vector<pair<int, int> > tasks(N);
  REP(i, N) {
    cin >> tasks[i].second >> tasks[i].first;
  }

  sort(tasks.begin(), tasks.end());
  int sum = 0;
  bool ans = true;
  REP(i, N) {
    sum += tasks[i].second;
    if (sum > tasks[i].first) ans = false;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}