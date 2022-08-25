#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()

using namespace std;

// longest perfect subsequence
int lps(int n, vector<int> &a, int start) {
    int sum = a[start], cnt = 1;
    for (int i = start + 1; i < n; i++) {
        if (sum >= a[i]) {
            sum += a[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    reverse(ALL(a));
    int max = 0;
    for (int i = 0; i < n; i++) {
        max = ::max(max, lps(n, a, i));
    }
    cout << max << "\n";
}
