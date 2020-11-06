// AGC009 A - Multiple Array

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
  vector<ll> a(N), b(N);
  REP(i, N) cin >> a[i] >> b[i];

  ll sum = 0;
  REPD(i, N) {
    a[i] += sum;
    ll r = a[i] % b[i];
    if (r != 0) sum += b[i] - r;
  }
  cout << sum << endl;
}