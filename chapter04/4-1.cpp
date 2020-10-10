#include <iostream>
using namespace std;

int tribonacci(int N) {
  // basecase
  if (N == 0) return 0;
  else if (N == 1) return 0;
  else if (N == 2) return 1;

  // recurrent
  int result = tribonacci(N - 1) + tribonacci(N - 2) + tribonacci(N - 3);
  return result;
}

int main() {
  cout << tribonacci(20) << endl;
}