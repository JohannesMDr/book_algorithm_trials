#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> memo;

ll fibo(int N) {
  // basecase
  if (N == 0) return 0;
  else if (N == 1) return 1;

  // check memo
  if (memo[N] != -1) return memo[N];

  return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main() {
  memo.assign(50, -1);
  fibo(49);
  for (int N = 2; N < 50; ++N) {
    cout << "fibo(" << N << ") = " << memo[N] << endl;
  }
}