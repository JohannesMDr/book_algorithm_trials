// ABC114 C

#include <iostream>
using namespace std;

long long n;
int ans=0;
void dfs(long x, bool seven, bool five, bool three) {
  if (x > n) {
    cout << "passed: dfs(" << x <<", " << seven << five << three << ")" <<endl;
    return;
  }
  cout << "called: dfs(" << x <<", " << seven << five << three << ")" <<endl;

  if (seven && five && three) {
    ans++;
    cout << "x = " << x << endl;
  }
  dfs(x * 10 + 7, true, five, three);
  dfs(x * 10 + 5, seven, true, three);
  dfs(x * 10 + 3, seven, five, true);
}

int main() {
  cin >> n;
  dfs(0, false, false, false);
  cout << ans << endl;
  return 0;
}