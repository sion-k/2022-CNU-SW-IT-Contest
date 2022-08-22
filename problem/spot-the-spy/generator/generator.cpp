#include <bits/stdc++.h>
#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
using namespace std;

const int NM_MIN = 2, NM_MAX = 10;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(NM_MIN, NM_MAX);
    int m = rnd.next(NM_MIN, NM_MAX);
    int k = m * rnd.next(1, NM_MAX) - rnd.next(1, m - 1);
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
