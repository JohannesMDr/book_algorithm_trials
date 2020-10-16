// AtCoder Educational DP Contest C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i >= ll(b); i--)

template<class T> void chmax(T& a, T b) {
  if (a < b) a = b;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  REP(i, N) cin >> A[i] >> B[i] >> C[i];

  // dp: value of (N)th day
  vector<vector<int> > dp(N+1, vector<int>(3, 0));

  REP(i, N) {
    chmax(dp[i+1][0], dp[i][1] + A[i]);
    chmax(dp[i+1][0], dp[i][2] + A[i]);
    chmax(dp[i+1][1], dp[i][0] + B[i]);
    chmax(dp[i+1][1], dp[i][2] + B[i]);
    chmax(dp[i+1][2], dp[i][0] + C[i]);
    chmax(dp[i+1][2], dp[i][1] + C[i]);
  }

  int ans = *max_element(dp[N].begin(), dp[N].end());

  cout << ans << endl;

}

