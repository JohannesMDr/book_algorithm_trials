// ABC026 D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define START ios::sync_with_stdio(false);cin.tie(0);

double f(double t, double A, double B, double C) {
  return A * t + B * sin(C * t * M_PI);
}

int main() {
  START
  double A, B, C;
  cin >> A >> B >> C;

  double left = 0, right = 1000;
  while (right - left > 1e-12) {
    double mid = (left + right) / 2;
    double result = f(mid, A, B, C);
    if (abs(result - 100) <= 1e-12) {
      // cout << mid << endl;
      printf("%.10f\n", mid);
      return 0;
    } else if (result - 100 > 0) {
      right = mid;
    } else {
      left = mid;
    }
  }
  // cout << left << endl;
  printf("%.10f\n", left);
}