// AtCoder Educational DP Contest F - LCS

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)

template<class T> void chmax(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  string S, T;
  cin >> S >> T;

  vector<vector<int> > dp(S.size()+1, vector<int>(T.size()+1, 0));

  REP(i, S.size()) {
    REP(j, T.size()) {
      if (S[i] == T[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
      chmax(dp[i+1][j+1], dp[i+1][j]);
      chmax(dp[i+1][j+1], dp[i][j+1]);
      // cout << "dp[" << i+1 << "][" << j+1 << "] = " << dp[i+1][j+1] << endl;
    }
  }
  cout << dp[S.size()][T.size()] << endl;
}

