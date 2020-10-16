// AtCoder Educational DP Contest A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> void chmin(T& a, T b) {
  if (a > b) a = b;
}

const ll INF = 1LL << 60;

int N;
vector<ll> h;
vector<ll> dp;

ll rec(int i) {
  if (dp[i] < INF) return dp[i];

  if (i == 0) return 0;

  ll res = INF;
  chmin(res, rec(i-1) + abs(h[i] - h[i-1]));
  if (i > 1) chmin(res, rec(i-2) + abs(h[i] - h[i-2]));

  return dp[i] = res;
}

int main() {
  cin >> N;
  h.resize(N);
  for (int i = 0; i < N; ++i) cin >> h[i];

  dp.assign(N, INF);
  cout << rec(N-1) << endl;
}