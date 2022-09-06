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
    for (int i = 2; i <= 1000; i++) {
        if (!prime(i)) continue;
        if (a <= i && i <= b) {
            yt++;
        }
        if (c <= i && i <= d) {
            yj++;
        }
    }
    cout << (yt > yj ? "yt" : "yj") << "\n";
}
