#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> c(2);
    for (int i = 0; i < n; i++) {
        c[a[i] % 2]++;
    }
    cout << (c[0] == c[1] || c[0] + 1 == c[1]) << "\n";
}
