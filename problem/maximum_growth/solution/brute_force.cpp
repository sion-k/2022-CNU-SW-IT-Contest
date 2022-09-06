#include <bits/stdc++.h>

#define FAST() cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
    FAST();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            max = ::max(max, a[j] - a[i]);
        }
    }
    cout << max << "\n";
}
