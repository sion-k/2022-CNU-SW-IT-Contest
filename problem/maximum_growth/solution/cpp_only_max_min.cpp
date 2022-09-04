#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int ret = 0;
    int max = -INF, min = INF;
    for (int i = 0; i < n; i++) {
        max = ::max(max, a[i]);
        min = ::min(min, a[i]);
        ret = ::max(ret, max - min);
    }
    cout << ret << "\n";
}
