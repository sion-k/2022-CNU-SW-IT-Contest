#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, t = 0;
    cin >> a >> b;
    while (true) {
        if (t % 2 == 0) {
            b += a;
        } else {
            a += b;
        }
        t++;
        if (a >= 5) {
            cout << "yj" << "\n";
            return 0;
        }
        if (b >= 5) {
            cout << "yt" << "\n";
            return 0;
        }
    }
}
