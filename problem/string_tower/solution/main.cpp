#include <bits/stdc++.h>

using namespace std;

bool f(int n, string &u, string &v) {
    for (int i = 0; i < n; i++) {
        if (u.substr(n - 1 - i) == v.substr(0, i + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (!f(m, a[i], a[i + 1]) && !f(m, a[i + 1], a[i])) {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
}
