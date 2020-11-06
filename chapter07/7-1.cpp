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
  vector<int> a(N), b(N);
  REP(i, N) cin >> a[i];
  REP(i, N) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  REP(i, N) {
    int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

  }
}