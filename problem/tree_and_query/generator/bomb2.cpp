#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = N_MAX;
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        cout << rnd.next(0, 1) << " \n"[i == n - 1];
    }

    int r = rnd.next(1, n);

    for (int i = 1; i <= n; i++) if (i != r) {
        int u = r, v = i;

        if (rnd.next(0, 1)) {
            swap(u, v);
        }

        cout << u << " " << v << "\n";
    }

    int q = n;
    cout << q << "\n";

    for (int i = 0; i < q; i++) {
        cout << r << "\n";
    }
}
