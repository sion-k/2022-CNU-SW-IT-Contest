#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
using namespace std;

// N의 범위
const int N_MIN = 2, N_MAX = 100'000;

// N * M의 범위
const int NM_MIN = 4, NM_MAX = 1'000'000'000;

// a의 범위
const int AI_MIN = 2, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int nm = rnd.next(NM_MIN, NM_MAX);
    int n = rnd.next(max(N_MIN, nm / N_MAX), min(N_MAX, nm / 2));
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
