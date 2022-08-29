#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()

using namespace std;

pair<int, int> count(int n, vector<long long> &a, int i) {
    long long left = a[i] / 10;
    long long right = a[i] * 10;
    int b = 0, c = 0;
    for (int j = 0; j < n; j++) if (j != i) {
        if (a[j] <= left) {
            c++;
        }
        if (a[j] >= right) {
            b++;
        }
    }
    return { b, c };
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(ALL(a));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto [b, c] = count(n, a, i);
        if (b < c) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}
