#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);

int main() {
  START
  int N, M;
  cin >> N >> M;
  vector<pair<int,int> > ab(N);
  REP(i, N) cin >> ab[i].first >> ab[i].second;

  sort(ALL(ab));
  ll ans = 0;
  int bought = 0;
  REP(i, N) {
    if (bought + ab[i].second >= M) {
      ans += (ll)ab[i].first * (ll)(M - bought);
      break;
    }
    ans += (ll)ab[i].first * (ll)ab[i].second;
    bought += ab[i].second;
  }
  cout << ans << endl;
}