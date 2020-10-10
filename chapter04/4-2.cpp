#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> memo;

ll tribonacci(int N) {
  // basecase
  if (N == 0) return 0;
  else if (N == 1) return 0;
  else if (N == 2) return 1;

  // recurrent
  if (memo[N] != -1) return memo[N];
  return memo[N] = tribonacci(N - 1) + tribonacci(N - 2) + tribonacci(N - 3);
}

int main() {
  memo.assign(50, -1);
  tribonacci(49);
  for (int N = 3; N < 50; ++N) {
    cout << "tribonacci(" << N << ") = " << memo[N] << endl;
  }
}