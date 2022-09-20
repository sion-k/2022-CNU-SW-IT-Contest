#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if (s == t) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}
