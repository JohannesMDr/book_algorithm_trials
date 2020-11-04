// ARC037 C

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
  int N, K;
  cin >> N >> K;
  vector<ll> a(N), b(N);
  REP(i, N) cin >> a[i];
  REP(i, N) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll left = 0, right = a[N-1] * b[N-1] + 1;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    int cnt = 0;
    REP(i, N) {
      ll bmax = mid / a[i];
      // int bleft = lower_bound(b.begin(), b.end(), bmax) - b.begin();
      int bleft = upper_bound(b.begin(), b.end(), bmax) - b.begin();
      cnt += bleft;
    }
    if (cnt < K) left = mid;
    else right = mid;
  }
  cout << right << endl;
}