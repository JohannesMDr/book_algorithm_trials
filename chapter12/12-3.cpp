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
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  priority_queue<int> q;
  FOR(i, 0, K) {
    q.push(a[i]);
  }

  cout << q.top() << endl;

  FOR(i, K, N) {
    q.push(a[i]);
    q.pop();
    cout << q.top() << endl;
  }
}