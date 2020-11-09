#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < ll(n); i++)
#define REPD(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, a, b) for(ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for(ll i = a; i > ll(b); i--)
#define ALL(v) v.begin(), v.end()
#define START ios::sync_with_stdio(false);cin.tie(0);
const int MAX = 100000;

int st[MAX];
int top = 0;

void init() {
  top = 0;
}

bool isEmpty() {
  return (top == 0);
}

bool isFull() {
  return (top == MAX);
}

void push(int x) {
  if (isFull()) {
    cout << "error: stack is full." << endl;
    return;
  }
  st[top] = x;
  ++top;
}

int pop() {
  if (isEmpty()) {
    cout << "error: stack is empty." << endl;
    return -1;
  }
  --top;
  return st[top];
}

int main() {
  START
  init();
  push(3);
  push(5);
  push(7);

  cout << pop() << endl;
  cout << pop() << endl;

  push(9);
}