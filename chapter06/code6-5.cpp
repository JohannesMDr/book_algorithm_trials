// ABC023 D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define START ios::sync_with_stdio(false);cin.tie(0);

const ll INF = 1LL << 60;

int main() {
  START
  int N;
  cin >> N;
  vector<ll> h(N), s(N);
  REP(i, N) cin >> h[i] >> s[i];

  ll left = 0, right = INF;
  while (right - left > 1) {
    ll mid = (left + right) / 2;

    bool ok = true;
    vector<ll> t(N, 0);
    REP(i, N) {
      if (mid < h[i]) ok = false;
      else t[i] = (mid - h[i]) / s[i];
    }

    sort(t.begin(), t.end());
    REP(i, N) {
      if (t[i] < i) ok = false;
    }

    if (ok) right = mid;
    else left = mid;
  }

  cout << right << endl;
}
