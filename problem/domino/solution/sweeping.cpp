#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int max = 0, sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (sum >= a[i]) {
            sum += a[i];
            cnt++;
        } else {
            sum = a[i];
            cnt = 1;
        }
        max = ::max(max, cnt);
    }
    cout << max << "\n";
}
