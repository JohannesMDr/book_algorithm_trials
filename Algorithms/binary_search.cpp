#include <bits/stdc++.h>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// if `index` is fulfilled in the condition
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// template of binary search
int binary_search(int key) {
    int ng = -1;
    int ok = (int)a.size();

    // ok > ng / ng > ok
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}