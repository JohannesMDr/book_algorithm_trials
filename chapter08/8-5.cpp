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
  unordered_map<int, int> hash_a, hash_b;
  REP(i, N) {
    int a;
    cin >> a;
    hash_a[a] = a;
  }
  REP(i, M) {
    int b;
    cin >> b;
    hash_b[b] = b;
  }

  int ans = 0;
  auto itr = hash_a.begin();
  for (itr; itr != hash_a.end(); itr++) {
    int i = itr->first;
    if (hash_b.count(i) != 0) ans++;
  }
  cout << ans << endl;
}