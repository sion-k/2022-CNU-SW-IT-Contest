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
    int yt = 0, yj = 0;
    int common = 0;
    for (int i = 2; i <= 1000; i++) {
        if (!prime(i)) continue;
        if (a <= i && i <= b && c <= i && i <= d) {
            common++;
        } else if (a <= i && i <= b) {
            yt++;
        } else if (c <= i && i <= d) {
            yj++;
        }
    }
    // cout << yt << ", " << yj << "\n";
    yt += (common + 1) / 2;
    yj += common / 2;
    cout << (yt > yj ? "yt" : "yj") << "\n";
}
