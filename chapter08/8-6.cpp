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
    if (hash_a.count(a) != 0) hash_a[a]++;
    else hash_a[a] = 1;
  }
  REP(i, M) {
    int b;
    cin >> b;
    if (hash_b.count(b) != 0) hash_b[b]++;
    else hash_b[b] = 1;
  }

  int ans = 0;
  auto itr = hash_a.begin();
  for (itr; itr != hash_a.end(); itr++) {
    int i = itr->first;
    if (hash_b.count(i) != 0) ans += hash_a[i] * hash_b[i];
  }
  cout << ans << endl;
}