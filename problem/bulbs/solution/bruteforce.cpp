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

    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            q[i] += q[i - 1];
        }
        q[i] += a[i] * !b[i];
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = i == 0 ? 0 : p[i - 1];
            sum += p[n - 1] - p[j];
            sum += q[j] - (i == 0 ? 0 : q[i - 1]);
            max = ::max(max, sum);
        }
    }
    cout << max << "\n";
}
