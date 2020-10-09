// ABC045 C

#include <iostream>
#include <string>
const int INF = 1e9;
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  long long ans = 0;
  for (int bit = 0; bit < (1 << (n - 1)); ++bit) {
    long long ans_tmp = 0;
    int index = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        ans_tmp += stoll(s.substr(index, i + 1 - index));
        index = i + 1;
      }
    }
    ans_tmp += stoll(s.substr(index));
    ans += ans_tmp;
  }
  cout << ans << endl;
}