#include <bits/stdc++.h>

using namespace std;

int query(int n, vector<int>& a, int l, int r) {
    int max = 0;
    vector<int> dp(n);
    for (int i = l; i <= r; i++) {
        dp[i] = a[i];
        if (i - 1 >= l) {
            dp[i] = min(dp[i], dp[i - 1]);
        }
        max = ::max(max, a[i] - dp[i]);
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int k, v;
            cin >> k >> v;
            a[k - 1] = v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(n, a, l - 1, r - 1) << "\n";
        }
    }
}
