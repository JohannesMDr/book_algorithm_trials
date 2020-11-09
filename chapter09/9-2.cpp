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

  int slen = s.size();
  stack<int> operant;
  REP(i, slen) {
    if (s[i] == '+') {
      int p1 = operant.top();
      operant.pop();
      int p2 = operant.top();
      operant.pop();
      operant.push(p1 + p2);
    } else if (s[i] == '-') {
      int p1 = operant.top();
      operant.pop();
      int p2 = operant.top();
      operant.pop();
      operant.push(p2 - p1);
    } else if (s[i] == '*') {
      int p1 = operant.top();
      operant.pop();
      int p2 = operant.top();
      operant.pop();
      operant.push(p1 * p2);
    } else if (s[i] == '/') {
      int p1 = operant.top();
      operant.pop();
      int p2 = operant.top();
      operant.pop();
      operant.push(p2 / p1);
    }
    else operant.push(s[i] - '0');
  }
  cout << operant.top() << endl;
}