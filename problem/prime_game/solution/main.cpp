#include <bits/stdc++.h>

using namespace std;

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<int, int> cnt;
    int com = 0;
    for (int i = 2; i <= 1000; i++) {
        if (!prime(i)) continue;
        if (a <= i && i <= b && c <= i && i <= d) {
            com++;
        } else if (a <= i && i <= b) {
            cnt.first++;
        } else if (c <= i && i <= d) {
            cnt.second++;
        }
    }
    int p = (com + 1) / 2 + cnt.first;
    int q = com / 2 + cnt.second;
    cout << (p > q ? "yt" : "yj") << "\n";
}
