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
  string s;
  cin >> s;

  stack<int> operant;
  vector<pair<int,int> > ps;
  REP(i, s.size()) {
    if (s[i] == '(') {
      operant.push(i);
    } else {
      if (operant.empty()) {
        cout << "No" << endl;
        return 0;
      } else {
        int p = operant.top();
        operant.pop();
        ps.push_back({p, i});
      }
    }
  }

  if (!operant.empty()) {
    cout << "No" << endl;
    return 0;
  }

  sort(ALL(ps));
  REP(i, ps.size()) {
    cout << "(" << ps[i].first << ", " << ps[i].second << ")" << endl;
  }
  return 0;
}