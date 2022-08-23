#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
using namespace std;

// N의 범위
const int N_MIN = 2, N_MAX = 100'000;

// N * M 의 범위이자 a_i 의 범위
const int NM_MIN = 2, NM_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int nm = rnd.next(NM_MIN, NM_MAX);
    int n = rnd.next(N_MIN, N_MAX);
    int m = rnd.next(2, nm / n);
    int k = m * rnd.next(1, n) - rnd.next(1, m - 1);
    if (k == 1) {
        k = m == 2 ? 3 : 2;
    }
    cout << n << "\n";
    vector<int> a(n + 1);
    a[0] = k;
    for (int i = 1; i <= n; i++) {
        a[i] = i * m;
    }
    shuffle(ALL(a));
    for (int i = 0; i < n + 1; i++) {
        cout << a[i] << " \n"[i == n];
    }
}
