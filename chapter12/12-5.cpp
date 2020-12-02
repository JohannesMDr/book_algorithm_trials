// median of medians, quick selection
// https://naoyat.hatenablog.jp/entry/median-of-medians
// http://agw.hatenablog.jp/entry/20090513/1242290109
// https://www-ui.is.s.u-tokyo.ac.jp/~takeo/course/2016/algorithm/quickselect.pdf
// https://www.geeksforgeeks.org/quickselect-algorithm/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);


int partition(int arr[], int l, int r) {
  int x = arr[r], i = l;
  for (int j = l; j <= r - 1; j++) {
    if (arr[j] <= x) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}

int QuickSelect(int arr[], int l, int r, int k) {
  // If k is smaller than number of
  // elements in array
  if (k > 0 && k <= r - l + 1) {

      // Partition the array around last
      // element and get position of pivot
      // element in sorted array
      int index = partition(arr, l, r);

      // If position is same as k
      if (index - l == k - 1)
          return arr[index];

      // If position is more, recur
      // for left subarray
      if (index - l > k - 1)
          return QuickSelect(arr, l, index - 1, k);

      // Else recur for right subarray
      return QuickSelect(arr, index + 1, r,
                          k - index + l - 1);
  }

  // If k is more than number of
  // elements in array
  return INT_MAX;
}

int main() {
  START
  int N, k;
  cin >> N >> k;
  int a[N+10];
  REP(i, N) cin >> a[i];

  cout << QuickSelect(a, 0, N, k) << endl;
}