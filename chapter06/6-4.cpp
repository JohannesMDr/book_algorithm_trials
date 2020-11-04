// POJ No.2456 Aggressive cows
// http://poj.org/problem?id=2456

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
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  int left = 0, right = a[N-1] + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;

  }

}