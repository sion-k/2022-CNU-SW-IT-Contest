#include <bits/stdc++.h>
#include <random>

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
    int p = (double)rand() / 32767 * (max(0, n - 80000));

    int max = 0;
    for (int i = p; i < min(n, p + 80000); i++) {
        for (int j = i; j < min(n, p + 80000); j++) {
            max = ::max(max, a[j] - a[i]);
        }
    }
    cout << max << "\n";
}
