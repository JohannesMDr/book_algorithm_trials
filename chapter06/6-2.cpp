// ABC077 C - Snuke Festival

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
  vector<int> a(N), b(N), c(N);
  REP(i, N) cin >> a[i];
  REP(i, N) cin >> b[i];
  REP(i, N) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;
  REP(i, N) {
    ll ca, cc;
    ca = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    cc = c.end() - upper_bound(c.begin(), c.end(), b[i]);
    ans += ca * cc;
  }

  cout << ans << endl;

}