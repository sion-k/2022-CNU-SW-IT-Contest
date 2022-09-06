#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int min = a[0], max = 0;
    for (int i = 0; i < n; i++) {
        min = ::min(min, a[i]);
        max = ::max(max, a[i] - min);
    }
    cout << max << "\n";
}
