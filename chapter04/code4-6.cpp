#include <iostream>
using namespace std;

int fibo(int N) {
  cout << "called: fibo(" << N << ")" << endl;

  // basecase
  if (N == 0) return 0;
  else if (N == 1) return 1;

  // recurrent
  int result = fibo(N - 1) + fibo (N - 2);
  cout << "fibo(" << N << ") = " << result << endl;

  return result;
}

int main() {
  fibo(6);
}