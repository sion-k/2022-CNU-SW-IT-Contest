#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";
    int range = rnd.next(1, n);
    for (int i = 0; i < n; i++) {
        cout << rnd.next(max(1, n - range), n + range) << " \n"[i == n - 1];
    }
}
