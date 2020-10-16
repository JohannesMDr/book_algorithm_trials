#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i >= ll(b); i--)

template<class T> void chmin(T& a, T b) {
  if (a > b) a = b;
}

const int INF = 1 << 29;

int main() {
  string S, T;
  cin >> S >> T;

  vector<vector<int> > dp(S.size() + 1, vector<int>(T.size() + 1, INF));
  dp[0][0] = 0;

  REP(s, S.size() + 1) {
    REP(t, T.size() + 1) {
      if (s > 0 && t > 0) {
        if (S[s-1] == T[t-1]) chmin(dp[s][t], dp[s-1][t-1]);
        else chmin(dp[s][t], dp[s-1][t-1] + 1);
      }
      if (s > 0) chmin(dp[s][t], dp[s-1][t] + 1);
      if (t > 0) chmin(dp[s][t], dp[s][t-1] + 1);
    }
  }

  cout << dp[S.size()][T.size()] << endl;
}

