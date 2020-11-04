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
  vector<int> a(N);
  REP(i, N) cin >> a[i];

  vector<int> b = a;
  sort(b.begin(), b.end());
  vector<int> ans(N);
  REP(i, N) {
    int left = 0, right = N - 1;
    while (right >= left) {
      int mid = left + (right - left) / 2;
      if (b[mid] == a[i]) {
        ans[i] = mid;
        break;
      }
      else if (b[mid] > a[i]) right = mid - 1;
      else if (b[mid] < a[i]) left = mid + 1;
    }
    cout << ans[i] << endl;
  }
}