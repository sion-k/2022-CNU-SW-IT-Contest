#include <bits/stdc++.h>

using namespace std;

void flip(string &s, int p) {
    s[p] = s[p] == '0' ? '1' : '0';
}

void flip_range(string &s, int l, int r) {
    for (int i = l; i <= r; i++) {
        flip(s, i);
    }
}

bool balanced(int n, string &s) {
    vector<int> c(2);
    for (int i = 0; i < n; i++) {
        c[s[i] - '0']++;
    }
    return c[0] == c[1];
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            flip_range(s, i, j);
            if (balanced(n, s)) {
                cout << "YES" << "\n";
                // cout << i << " " << j << "\n";
                return 0;
            }
            flip_range(s, i, j);
        }
    }
    cout << "NO" << "\n";
}
