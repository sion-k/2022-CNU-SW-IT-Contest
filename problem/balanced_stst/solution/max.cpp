#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> cnt;
    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt[s[i]]++;
        if (cnt['s'] == cnt['t']) {
            p = i;
        }
    }
    assert(p != 0);
    cout << s.substr(p) << "\n";
}
