#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    cout << "str = " << str << endl;

    int oneCount = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') oneCount++;
    }

    cout << oneCount << endl;
    // assume oneCount >=2 ;

    int dl = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '1') {
            dl = i;
        }
    }

    if (n - dl <= k) {
        swap(str[n - 1], str[dl]);
        k = k - (n - dl);
    }

    int df = INT_MAX;

    for (int i = 0; i <= n - 2; i++) {
        if (str[i] == '1') {
            df = i;
        }
    }

    if (df <= k) {
        swap(str[0], str[df]);
        k = k - df;
    }

    cout << str << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    getchar();
    return 0;
}
