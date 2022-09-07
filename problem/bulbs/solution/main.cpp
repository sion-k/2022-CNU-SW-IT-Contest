#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            p[i] += p[i - 1];
        }
        p[i] += a[i] * b[i];
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = a[i] * !b[i];
        if (i - 1 >= 0) {
            dp[i] += max(p[i - 1], dp[i - 1]);
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        max = ::max(max, dp[i] + p[n - 1] - p[i]);
    }
    cout << max << "\n";
}
